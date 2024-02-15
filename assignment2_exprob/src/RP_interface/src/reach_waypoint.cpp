

//reference or source tutorial, link: https://github.com/gerardcanal/ICAPS_20_SummerSchool_ROSPlan/blob/master/icaps_ss
// and link: https://github.com/KCL-Planning/ROSPlan/blob/master/rosplan_planning_system/src/ActionInterface/RPActionInterface.cpp
//from move_base package 
#include <move_base_msgs/MoveBaseAction>
#include <rosplan_dispatch_msgs/ActionDispatch.h> 
#include "RP_interface/RPaction.h"
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/Pose.h>  
#include <std_msgs/String.h> 
#include <actionlib/client/terminal_state.h>
#include <rosparam_shortcuts/rosparam_shortcuts.h>
#include <tf/transform_listener.h>
#include <ros/ros.h>
#include <rosplan_knowledge_msgs/Notification.h>
#include <rosplan_dispatch_msgs/ActionFeedback.h>
#include <assignment2_exprob/ReachingAction.h>


//reference or source tutorial, link: https://github.com/gerardcanal/ICAPS_20_SummerSchool_ROSPlan/blob/master/icaps_ss
// and link: https://github.com/KCL-Planning/ROSPlan/blob/master/rosplan_planning_system/src/ActionInterface/RPActionInterface.cpp
class RPActionInterface {
public:
    RPActionInterface(ros::NodeHandle &nh);
    void runActionInterface();

private:
};

namespace KCL_rosplan {

    RPActionInterface::RPActionInterface(ros::NodeHandle &nh) {
    // here the initialization
    }

   /* run action interface 
	void RPActionInterface::runActionInterface() {

		ros::NodeHandle nh("~");

		// set action name
		nh.getParam("pddl_action_name", params.name);

		// knowledge base services
		std::string kb = "knowledge_base";
		nh.getParam("knowledge_base", kb); */

    //same method used in goback.cpp

    bool RPActionInterface::concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg) {
        
            //same method used in goback.cpp

        //creating a client for the action server
        //source from this tutorial: https://web.unibas.it/bloisi/corsi/lezionicf/4.1-actions.pdf
        actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> goclient("move_base", true); 
        
        //create a goal object of type move_base_msgs::MoveBaseGoal to indicate the position the robot should go to 
        move_base_msgs::MoveBaseGoal positionwp;
        
        //waits for our action client to connect to the move_base action server
        goclient.waitForServer();
        
        /*there are 4 waypoints given by the professor. The 4 waypoints, we name them from wp0 to wp3 are approximate positions from the markers 
        and that is where the robot will be able to detect the markers */
        
        //depending on the message the robot will go to either of the waypoints of the markers 
        //waypoint of the 1st marker, given by the professor 
        if(msg->parameters[2].value  == "wp1"){ 
           
            positionwp.target_pose.pose.position.x  =  6.0;
            positionwp.target_pose.pose.position.y  =  2.0;
	}
        //waypoint of the 2nd marker, given by the professor 
	    else if (msg->parameters[2].value  == "wp2"){
            
            positionwp.target_pose.pose.position.x  =  7.0;
            positionwp.target_pose.pose.position.y  =  -5.0;
            
	}
        //waypoint of the 3rd marker, given by the professor     
	    else if (msg->parameters[2].value  == "wp3"){
            
            positionwp.target_pose.pose.position.x  =  -3.0;
            positionwp.target_pose.pose.position.y  =  -8.0;
           
	}
        //waypoint of the 4th marker, given by the professor 
	    else if (msg->parameters[2].value  == "wp4"){
            
            positionwp.target_pose.pose.position.x  =  -7.0;
            positionwp.target_pose.pose.position.y  =  -1.5; 
            
	}
        
        ROS_INFO("I am now going to the marker waypoint "); 
        
        
        
        //send the desired position for the robot to go to its initial position
        goclient.sendGoal(positionwp); 
        goclient.waitForResult();
        return true;
    }
}



int main(int argc, char **argv) {
    ros::init(argc, argv, "my_reachwp_action", ros::init_options::AnonymousName); 
    ros::NodeHandle nh("~"); 
    KCL_rosplan::RPActionInterface my_reachwp_action(nh);
    my_reachwp_action.runActionInterface(); 
    return 0;
}