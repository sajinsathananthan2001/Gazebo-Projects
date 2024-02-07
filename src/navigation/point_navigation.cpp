#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>


//global variables
float points[4][2] = {
    {-2.16, 0.764},
    {-0.68, 1.6},
    {-0.55, -1.55},
    {-2, 0}
};

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

void doneCallback(const actionlib::SimpleClientGoalState& state, const move_base_msgs::MoveBaseResultConstPtr& result) {
    ROS_INFO("Finished in state [%s]", state.toString().c_str());
    // You can perform additional actions or checks based on the result here

}

void activeCallback() {
    ROS_INFO("Goal just went active");
}

void feedbackCallback(const move_base_msgs::MoveBaseFeedbackConstPtr& feedback) {
    ROS_INFO("Got feedback of the current position - x: %f, y: %f", feedback->base_position.pose.position.x, feedback->base_position.pose.position.y);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "point_navigation_cpp");
    ros::NodeHandle nh;
    

    for(int i = 0; i< sizeof(points); ++i)
    {
        MoveBaseClient ac("move_base", true);

        while (!ac.waitForServer(ros::Duration(5.0))) {
            ROS_INFO("Waiting for the move_base action server to come up");
        }

        move_base_msgs::MoveBaseGoal goal;
        goal.target_pose.header.frame_id = "map";
        goal.target_pose.header.stamp = ros::Time::now();

        goal.target_pose.pose.position.x = points[i][0];
        goal.target_pose.pose.position.y = points[i][1];
        goal.target_pose.pose.orientation.w = 1.0;

        // Set up callbacks
        ac.waitForServer();
        // ac.SimpleDoneCallback(boost::bind(&doneCallback, _1, _2));
        // ac.SimpleActiveCallback(boost::bind(&activeCallback));
        // ac.SimpleFeedbackCallback(boost::bind(&feedbackCallback, _1));

        ac.sendGoal(goal, doneCallback, activeCallback, feedbackCallback);

        ROS_INFO("Sending goal");
        // ac.sendGoal(goal);

        ac.waitForResult();

        if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
            ROS_INFO("Hooray, the base reached the goal!");
        else
            ROS_INFO("The base failed to reach the goal for some reason");

    }

    return 0;
}
