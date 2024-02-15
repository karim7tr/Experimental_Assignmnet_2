
ADVICE!!

you can launch the whole project from globallaunch.launch
However, if you dont have a titan laptop (most probably it is the case) run these commands below on your shell following the same order: 

1)roslaunch rosbot_gazebo assignment2.launch
2)roslaunch rosbot_bringup rosbot_gazebo.launch

OR for 1) and 2) you can run this launch file: fromassignment1.launch

3)rolaunch assignment2_exprob gmapping.launch
4)rolaunch assignment2_exprob move_base.launch
5)rosrun aruco_ros marker_publish
6)rosrun assignment2_exprob detectmarker.py
7)roslaunch RP_interface RPlaunch.launch
8)rosrun assignment2_exprob executor.py

