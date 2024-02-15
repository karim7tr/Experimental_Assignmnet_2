

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


    bool RPActionInterface::concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg) {
        
        //creating a client for the action server
        //source from this tutorial: https://web.unibas.it/bloisi/corsi/lezionicf/4.1-actions.pdf
        actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> goclient("move_base", true); 
        
        //create a goal object of type move_base_msgs::MoveBaseGoal to indicate the intial position the robot should go to 
        move_base_msgs::MoveBaseGoal initialposition;
        
        //waits for our action client to connect to the move_base action server
        goclient.waitForServer();
        
        
        if(msg->parameters[2].value  == "wp0"){

        
        
        //this is the initial position of the robot at the beginning 
        initialposition.target_pose.pose.position.x  =  2.0;
        initialposition.target_pose.pose.position.y  =  2.5;
        }
        
        ROS_INFO("I am now going back to my intial position "); 
        
        
        
        //send the desired position for the robot to go to its initial position
        goclient.sendGoal(initialposition); 
        goclient.waitForResult();
        return true;
    }
}



int main(int argc, char **argv) {
    ros::init(argc, argv, "my_goback_action", ros::init_options::AnonymousName); 
    ros::NodeHandle nh("~"); 
    KCL_rosplan::RPActionInterface my_goback_action(nh);
    my_goback_action.runActionInterface(); 
    return 0;
}