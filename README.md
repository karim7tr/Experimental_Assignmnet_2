# Experimental_Assignment_2

## Project Overview

This project presents an autonomous navigation system tailored for a robot operating within a simulated environment, leveraging the Robot Operating System (ROS) and the ROSPlan framework. The system orchestrates the robot's movement to specific waypoints, integrates ArUco marker detection, and orchestrates high-level task planning.

### Components

1. **ROS Nodes**: The project comprises several ROS nodes implemented in both C++ and Python.

2. **ROSPlan Framework**: Employing ROSPlan facilitates high-level task planning and action coordination.

3. **Simulation Environment**: The robot operates within a simulated environment realized using Gazebo.

4. **Motion Planning**: To navigate between waypoints, the robot employs a motion planning algorithm.

5. **ArUco Marker Detection**: Utilizing onboard sensors, the robot detects ArUco markers.

### Workflow

1. **Initialization**: Initialization encompasses setting up ROS nodes and requisite packages.

2. **Simulation Environment Setup**: This step involves launching the Gazebo simulation environment, complete with the robot and predefined waypoints.

3. **Motion Planning Initialization**: Initializing the motion planning node enables seamless navigation.

4. **ArUco Marker Extraction**: The `ArUcoMarkerExtractor.py` script extracts ArUco marker data from Gazebo simulation data and publishes it for visualization.

5. **ROSPlan Action Interface**: The `MyActionInterface` class bridges ROSPlan with the motion planning system, executing motion planning actions based on high-level action dispatch messages.

6. **Planning and Execution**: ROSPlan generates high-level plans specifying actions to fulfill goals, executed by the robot, including waypoint traversal and marker detection.

7. **Feedback and Monitoring**: The system provides feedback on action execution status and monitors progress toward goals.

8. **Completion**: Upon achieving all goals or mission completion, the system gracefully shuts down.

### Future Improvement
-Initially, one of the waypoints was not set correctly so the robot was not able to detect the marker. This posed a problem because we set the condition for the robot to complete all his tasks and return to wp0 is to strictly find all of the 4 markers. Instead it could be better to set the condition to 3 markers instead for example and also introduce a timer for the robot to search for the marker. If the robot exceed the time set, the marker could be set to found or not found. 
-The method used for the robot navigation is gmapping but other methods could be used such as: HectorSLAM or Cartographer. These are better optimized for real-time localization, mapping and dynamic environments.
-It is important to note the robot was able to find and detect the markers only because the waypoints were provided in advance. The waypoints are the approximate positions of the marker where it can be detected from the camera lidar field of view. Therefore, we should consider the scenario where the robot does not know in advance where the markers are placed. We can set the robot to look for markers while it is navigating the environment, but that would be computationally heavier and longer.

### Logic and Functioning

The project logic intricately weaves together various components to enable autonomous navigation and task execution. ROSPlan's role in high-level planning, coupled with the `MyActionInterface` class orchestrating motion planning actions, ensures efficient goal fulfillment. Meanwhile, the Python script `detectmarker.py` focuses on detecting ArUco markers, crucial for environment perception and localization:

```python
# detectmarker.py

# Detect ArUco marker
detected_marker = detect_aruco_marker()

# Process the detected marker
if detected_marker:
    # Update marker status and continue navigation
    update_marker_status()
    continue_navigation()
```

By integrating these components and their respective logic, the project facilitates autonomous navigation, marker detection, and task execution, ensuring robust performance even in dynamic environments.

---

## Flowchart

<p align="center">
  <img src="flowchart.png" alt="Flowchart" width="600">
</p>

## Launch steps

Launching the project can be accomplished using a global launch file or by manually starting individual components. Below are instructions for both methods.

### Quick Launch

For a streamlined start, execute the following command to launch the entire project using a single launch file:

```console
roslaunch globallaunch.launch
```

### Step-by-Step Launch

For manual control or systems with lower performance, follow these steps to launch the project:

1. Start the Gazebo simulation with the ROSBot:

```console
roslaunch rosbot_gazebo assignment2.launch
```

2. Bring up the ROSBot:

```console
roslaunch rosbot_bringup rosbot_gazebo.launch
```

3. Alternatively, use the combined launch file for steps 1 and 2:

```console
roslaunch fromassignment1.launch
```

4. Launch gmapping for SLAM:

```console
roslaunch assignment2_exprob gmapping.launch
```

5. Start move_base for autonomous navigation:

```console
roslaunch assignment2_exprob move_base.launch
```

6. Run the marker publisher node:

```console
rosrun aruco_ros marker_publish
```

7. Execute the marker detection script:

```console
rosrun assignment2_exprob detectmarker.py
```

8. Launch the ROSPlan interface:

```console
roslaunch RP_interface RPlaunch.launch
```

9. Start the executor script:

```console
rosrun assignment2_exprob executor.py
```

---

Contributors:
- Karim Triki
- Roumaissa Benkredda
- Ines Haouala
  
