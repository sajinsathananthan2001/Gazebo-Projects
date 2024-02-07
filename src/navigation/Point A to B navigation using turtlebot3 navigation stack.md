### In this code we use ros turtleBot3 navigation stack to sent goals to navigate the bot to different sequential point that we hardcoded. It using 'MoveBaseClient' to handle goal execution and provide the callback functions.

Here is the code explanation below:

```c++
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
```

we included the necessary header files to work with ros and MoveBase's action. ros.h is for ROS functionality and MoveBaceAction.h and Simple_action_client.h are for the MoveBase action.

```c++
float points[4][2] = {
    {-2.16, 0.764},
    {-0.68, 1.6},
    {-0.55, -1.55},
    {-2, 0}
};
```

A 2D array is taken to store different 2D coordinate to make the bot to move different points after reaching one another.

```c++
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

```

We declared MoveBaseClient which is an action client for MoveBase action.

```c++
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

```

These are the callback funtions which will called dueing the execution of the MoveBase action in the time of navigation.

In this "doneCallback" will called when the goal is reached, "activeCallback" will called when the goal become active and feedback will sent the feedback continuously with the argument feedback where we can acces the current position of the bot.

```c++
int main(int argc, char** argv) {
    ros::init(argc, argv, "point_navigation_cpp");
    ros::NodeHandle nh;

```

The main function initialize the ros node and node handle.

```c++
MoveBaseClient ac("move_base", true);

```

The instance of the "MoveBaseClient" is created and which will take the action name as parameter.

```c++
for (int i = 0; i < sizeof(points) / sizeof(points[0]); ++i) {

```

Now the for loop will run as per the length of the coordinates that we have taken in the 2d array.

```c++
while (!ac.waitForServer(ros::Duration(5.0))) {
    ROS_INFO("Waiting for the move_base action server to come up");
}

```

This set of loop will wait for the mentioned seconds for MoveBase action server.

```c++
move_base_msgs::MoveBaseGoal goal;
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();

goal.target_pose.pose.position.x = points[i][0];
goal.target_pose.pose.position.y = points[i][1];
goal.target_pose.pose.orientation.w = 1.0;

```

An Object is created in the name of "goal" and pass the values for the movebase reference.

```c++
ac.waitForServer();
ac.sendGoal(goal, doneCallback, activeCallback, feedbackCallback);

ROS_INFO("Sending goal");
ac.waitForResult();

```

Now the client sends the goal to the MoveBase server using the "sendGoal" method and wait for result and the callback functions also assigned for different stages.

```c++
if(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED)
{
    ROS_INFO("Hooray, the base reached the goal!");
}
else
{
    ROS_INFO("The base failed to reach the goal for some reason");
}
```

After reaching the goal it will threw the SUCCEEDED message.

----------------------------

# Here the output video of the navigation 

https://github.com/sajinsathananthan2001/Gazebo-Projects/assets/93672391/54517743-26c3-4a61-94d0-9054e67d8b81

