cmake_minimum_required(VERSION 3.0.2)
project(assignment2_exprob)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  nav_msgs
  octomap_msgs
  urdf
  sensor_msgs
  actionlib
  actionlib_msgs
  tf
  message_generation
  move_base_msgs
  rosplan_planning_system# Add this line
)

## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################
## Generate actions in the 'action' folder
add_action_files(
   FILES
   Reaching.action
   lookformarker.action
#   Action2.action
)

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   actionlib_msgs
   octomap_msgs
   geometry_msgs
)

# ...

###################################
## catkin specific configuration ##
###################################

catkin_package(
 
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ executable
##add_executable(myAction_assign2 src/myAction_assign2.cpp)
##add_dependencies(myAction_assign2 ${catkin_EXPORTED_TARGETS})

##target_link_libraries(myAction_assign2
##  ${catkin_LIBRARIES}
##)

#############
## Install ##
#############

# ...

#############
## Testing ##
#############

# ...
