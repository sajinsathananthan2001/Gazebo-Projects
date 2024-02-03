#!/usr/bin/env python3
import rospy
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal

i = 0

my_2d_list = [
    [-2.16, 0.764],
    [-0.68, 1.6],
    [-0.55, -1.55],
    [-2,0]
]

def active_cb(extra):
    rospy.loginfo("Goal pose being processed")
    

def feedback_cb(feedback):
    rospy.loginfo("Current location: "+str(feedback))

def done_cb(status, result):
    if status == 3:
        rospy.loginfo("Goal reached")
    if status == 2 or status == 8:
        rospy.loginfo("Goal cancelled")
    if status == 4:
        rospy.loginfo("Goal aborted")
   

if __name__ == "__main__":
    rospy.init_node("point_nav")
    rospy.loginfo("Starting point_.")

    for i in range(len(my_2d_list)):
        navclient = actionlib.SimpleActionClient('move_base',MoveBaseAction)
        navclient.wait_for_server()

        # Example of navigation goal
        goal = MoveBaseGoal()
        goal.target_pose.header.frame_id = "map"
        goal.target_pose.header.stamp = rospy.Time.now()

        goal.target_pose.pose.position.x = my_2d_list[i][0]
        goal.target_pose.pose.position.y = my_2d_list[i][1]
        goal.target_pose.pose.position.z = 0.0
        goal.target_pose.pose.orientation.x = 0.0
        goal.target_pose.pose.orientation.y = 0.0
        goal.target_pose.pose.orientation.z = 0.662
        goal.target_pose.pose.orientation.w = 0.750

        i=i+1

        navclient.send_goal(goal, done_cb, active_cb, feedback_cb)
        finished = navclient.wait_for_result()

        if not finished:
            rospy.loginfo("Action server not available!")
        else:
            rospy.loginfo ( navclient.get_result())


    
    while not rospy.is_shutdown():
        pass

