# Navigation

###  Performing navigation with TurtleBot3 in ROS 1 involves using the ROS Navigation Stack, which includes components like the AMCL (Adaptive Monte Carlo Localization) package, move_base package, and more. Below are the steps to set up navigation with TurtleBot3 using RViz:



### Step:1
## Install ROS and TurtleBot3 Packages:

Here you can refer to this documentation to install ROS and TurtleBot3

#### For ROS installation [ROS Documentation](https://wiki.ros.org/noetic/Installation/Ubuntu)

#### For TurtleBot3 installation [TurtleBot3 Documentation](https://emanual.robotis.com/docs/en/platform/turtlebot3/quick-start/#pc-setup)


### Step:2
#### Import and Launch Gazebo Simulation with Turtlebot2 model:
```
$ export TURTLEBOT3_MODEL=burger
$ roslaunch turtlebot3_gazebo turtlebot3_world.launch
```

### Step:3
#### Launch Navigation Stack:

Open a new terminal and launch the navigation stack. Replace the map location where you have saved the map file. If you have any doubght in the map file refer [SLAM](https://github.com/sajinsathananthan2001/Gazebo-Projects/tree/master/scripts/SLAM).
```
$ export TURTLEBOT3_MODEL=burger
$ roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=$HOME/map.yaml
```
Now the Rviz will be open and perform Navigation using scan data and try to match global map and local map datas.


### Step:4
Now try to pose estimate the position of the bot using the 2DposeEstimater in the rviz and after estimation for the proper localization use "roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=$HOME/map.yaml" to run the turtlebot3 manually to localize itself which will result in the better global and local map merge.

### Step:5
Now use 2D Nav Goal to move the Turtlebot3 model to the desire location.

## Output:

[Screencast from 02-02-2024 04:47:08 PM.webm](https://github.com/sajinsathananthan2001/Gazebo-Projects/assets/93672391/9c887d7d-ad2a-4838-b626-69a8d2073e26)



## Tips:

#### ROS Navigation Stack:
The standard ROS Navigation Stack provides a set of packages for navigation, including AMCL for localization and move_base for path planning and control.

#### Gmapping:
Gmapping (Grid-based Mapping) is a popular SLAM (Simultaneous Localization and Mapping) package in ROS. It can be used to create a 2D occupancy grid map of an environment.

#### Hector SLAM:
Hector SLAM is another SLAM package that focuses on real-time 2D mapping. It's suitable for platforms like drones and ground robots.

#### Robot Localization:
The robot_localization package is used for sensor fusion and state estimation. It allows you to integrate data from multiple sensors to improve localization accuracy.

#### DWA Local Planner:
The DWA (Dynamic Window Approach) Local Planner is a component of the ROS Navigation Stack. It's responsible for generating dynamically feasible trajectories for the robot to follow.

#### TeB Local Planner:
The Timed Elastic Band (TeB) Local Planner is an alternative to DWA and is designed to handle dynamic constraints and trajectory optimization.

#### MRTK (Mobile Robot Programming Toolkit):
MRTK is a framework that includes navigation, perception, and manipulation components. It is designed to simplify the development of mobile robot applications.

#### AMCL (Adaptive Monte Carlo Localization):
While mentioned in the context of the ROS Navigation Stack, AMCL is worth highlighting as a standalone package for probabilistic localization in a known map.

#### MoveIt!:
MoveIt! is a widely used framework for motion planning in ROS. It is designed for manipulators but can be adapted for mobile robots as well.

#### OpenSLAM:
OpenSLAM is not a ROS package, but it's a collection of SLAM algorithms and implementations. It can be integrated into ROS for various SLAM applications.

#### ROS2 Navigation Stack:
ROS 2, the next version of ROS, has its own navigation stack that builds on the lessons learned from the original ROS Navigation Stack.

#### SBPL:
