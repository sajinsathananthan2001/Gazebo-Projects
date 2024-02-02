# SLAM

###  Simultaneous Localization and Mapping (SLAM) is a technique used in robotics to create a map of an environment while simultaneously keeping track of the robot's position within that environment. Here are the steps to perform SLAM using the TurtleBot3 model with Gazebo and RViz:



### Step:1
## Install ROS and TurtleBot3 Packages:

Here you can refer to this documentation to install ROS and TurtleBot3

#### For ROS installation [ROS Documentation](https://wiki.ros.org/noetic/Installation/Ubuntu)

#### For TurtleBot3 installation [TurtleBot3 Documentation](https://emanual.robotis.com/docs/en/platform/turtlebot3/quick-start/#pc-setup)


### Step:2
Import and Launch the Gazebo's Turtlebot3 Model
```
$ export TURTLEBOT3_MODEL=burger
$ roslaunch turtlebot3_gazebo turtlebot3_empty_world.launch
```

### Step:3
Open the new terminal import the model and launch the slam package using the command:
```
$ export TURTLEBOT3_MODEL=burger
$ roslaunch turtlebot3_slam turtlebot3_slam.launch
```
Now the Rviz will be open and perform Maping using scan data

![Screenshot from 2024-02-02 14-53-14](https://github.com/sajinsathananthan2001/Gazebo-Projects/assets/93672391/582b4e7c-48fe-4c93-92df-2a84d8c55b57
)
### Step:4
In a new terminal launch the teleoperation node to manually control the TurtleBot3:
```
$ export TURTLEBOT3_MODEL=burger
$ roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
```
After this navigate manually throughout all the places in the map you will map the entire world using SLAM algorithem.

Here the example output:

![Screenshot from 2024-02-02 14-55-12](https://github.com/sajinsathananthan2001/Gazebo-Projects/assets/93672391/38924330-7e0b-42e4-8aa1-6585a1b1437d)

### Step:5
Now open a new terminal to save the maped environment using the below command.
```
$ rosrun map_server map_saver -f ~/map

```

Here you have to go to your desire file location to run the particular command.



