cmake_minimum_required(VERSION 3.0.2)
project(RP_interface)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  actionlib
  diagnostic_msgs
  roscpp
  rospy
  std_msgs
  genmsg
  actionlib_msgs
  rosplan_planning_system
)

catkin_python_setup()

catkin_package(
#  CATKIN_DEPENDS
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


add_executable(go_back_init src/go_back_init.cpp)
add_dependencies(go_back_init ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(go_back_init ${catkin_LIBRARIES})

add_executable(go_marker src/go_marker.cpp)
add_dependencies(go_marker ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(go_marker ${catkin_LIBRARIES})

add_executable(reach_waypoint src/reach_waypoint.cpp)
add_dependencies(reach_waypoint ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(reach_waypoint ${catkin_LIBRARIES})

include_directories(
# include
# ${catkin_INCLUDE_DIRS}
)

