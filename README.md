# Experimental_Assignment_2

## Project Overview

This project implements an autonomous navigation system for a robot in a simulated environment using the Robot Operating System (ROS) and the ROSPlan framework. The system allows the robot to navigate to specific waypoints, detect ArUco markers, and perform high-level task planning.

### Components

1. **ROS Nodes**: The project consists of several ROS nodes written in both C++ and Python.

2. **ROSPlan Framework**: ROSPlan is utilized for high-level task planning and coordination of actions.

3. **Simulation Environment**: The robot operates in a simulated environment created using Gazebo.

4. **Motion Planning**: The robot employs a motion planning algorithm to navigate between waypoints.

5. **ArUco Marker Detection**: ArUco markers are detected using sensors onboard the robot.

### Workflow

1. **Initialization**: The ROS nodes and necessary packages are initialized.

2. **Simulation Environment Setup**: The Gazebo simulation environment, including the robot and waypoints, is launched.

3. **Motion Planning Initialization**: The motion planning node is initialized to enable navigation.

4. **ArUco Marker Extraction**: The `ArUcoMarkerExtractor.py` script extracts ArUco marker information from Gazebo simulation data and publishes it for visualization.

5. **ROSPlan Action Interface**: The `MyActionInterface` class serves as an interface between ROSPlan and the motion planning system. It triggers motion planning actions based on high-level action dispatch messages from ROSPlan.

6. **Planning and Execution**: ROSPlan generates high-level plans specifying actions to achieve goals. The robot executes these plans, such as moving between waypoints and detecting markers.

7. **Feedback and Monitoring**: The system provides feedback on action execution status and monitors progress towards goals.

8. **Completion**: Once all goals are achieved or the mission is completed, the system shuts down gracefully.

### Logic

- **High-Level Planning**: ROSPlan generates plans based on domain knowledge and the environment state.

- **Action Execution**: The `MyActionInterface` class translates high-level action dispatch messages into motion planning actions.

- **Perception and Localization**: The robot perceives its environment and localizes itself using onboard sensors.

- **Dynamic Environment Handling**: The system handles dynamic changes in the environment by updating its plans and state.

- **Feedback and Adaptation**: Feedback on action execution status is used to adapt the system's behavior for successful task completion.

## Flowchart

<p align="center">
  <img src="flowchart.png" alt="Flowchart" width="600">
</p>

## Launch steps

This project can be launched using a global launch file or by executing a series of commands in the terminal to start individual components. Below are the instructions for both methods.

### Quick Launch

If you prefer a quick start, you can launch the entire project using a single launch file:

```console
roslaunch globallaunch.launch
```

This command initializes all necessary nodes and brings up the simulation environment and the robot ready for marker detection and navigation tasks.

### Step-by-Step Launch

For systems with lower performance, or if you wish to manually control the launch process, follow the steps below. Execute each command in a new terminal window, in the given order:

1. Start the Gazebo simulation with the ROSBot in the assignment-specific environment:

```console
roslaunch rosbot_gazebo assignment2.launch
```

2. Bring up the ROSBot:

```console
roslaunch rosbot_bringup rosbot_gazebo.launch
```

Alternatively, for steps 1 and 2, use the combined launch file:

```console
roslaunch fromassignment1.launch
```

3. Launch the gmapping for SLAM:

```console
roslaunch assignment2_exprob gmapping.launch
```

4. Start the move_base for autonomous navigation:

```console
roslaunch assignment2_exprob move_base.launch
```

5. Run the marker publisher node to publish ArUco marker positions:

```console
rosrun aruco_ros marker_publish
```

6. Execute the marker detection script:

```console
rosrun assignment2_exprob detectmarker.py
```

7. Launch the ROSPlan interface:

```console
roslaunch RP_interface RPlaunch.launch
```

8. Start the executor script for handling detected markers and planning:

```console
rosrun assignment2_exprob executor.py
```

--- 

Contributors:
- Karim Triki
- Romaissa Benkerda
- Ines Haoula

