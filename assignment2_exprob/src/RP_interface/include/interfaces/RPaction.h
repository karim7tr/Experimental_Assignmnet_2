#include <ros/ros.h>
#include "rosplan_action_interface/RPActionInterface.h"

/*source and was adapted from: https://github.com/KCL-Planning/ROSPlan/blob/master/rosplan_planning_system/src/ActionInterface/RPActionInterface.cpp */

namespace KCL_rosplan {

    class RPMoveBaseInterface: public RPActionInterface
    { 
 	private:
 	
	public:
	
     	/* constructor */ 
     	RPMoveBaseInterface(ros::NodeHandle &nh);
     	
     	/* listen to and process action_dispatch topic */
     	bool concreteCallback(const 
rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg);
    };
}
