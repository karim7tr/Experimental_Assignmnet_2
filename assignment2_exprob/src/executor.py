#! /usr/bin/env python3
import actionlib
import actionlib.msg
from rosplan_dispatch_msgs.srv import DispatchService, DispatchServiceRequest, DispatchServiceResponse
from std_srvs.srv import Empty  # Add this import
import rospy
from tf import transformations
from rosplan_dispatch_msgs.srv import DispatchServiceRequest
import time
import math


#source tutorial: https://kcl-planning.github.io/ROSPlan//tutorials/tutorial_01


class pddlexecutor():
    def __init__(self):
        #number of services used, refer to lines below 
        self.number = 4

        self.service_list = [
            #refer to: https://kcl-planning.github.io/ROSPlan//tutorials/tutorial_01
            #call the problem generation service 
            "/rosplan_problem_interface/problem_generation_server",
            #call planning server 
            "/rosplan_planner_interface/planning_server",
            #call parse_plan
            "/rosplan_parsing_interface/parse_plan",
            #call dsipatch_plan
            "/rosplan_plan_dispatcher/dispatch_plan"
        ]
        

    def execute(self):
    #here we iterate through the list of services
        for index in range(self.number):
            # Wait for the ROS service to bee available
            rospy.wait_for_service(self.service_list[index])

            try:
                service_proxy = rospy.ServiceProxy(self.service_list[index], DispatchService)
                
                # get the respective request based on number index 
                if index == self.number - 1:
                    request = DispatchServiceRequest()  # DispatchServiceRequest of the respective serbvice
                    service_proxy(request)
                else:
                    #empty service 
                    errorservice= rospy.ServiceProxy(self.service_list[index], Empty) #instead of DispatchService
                    #same methid as above 
                    errorservice()

                

            except rospy.ServiceException as error:
                # if it fails
                rospy.loginfo("Error occurred: %s" % error)


        

    
if __name__ == "__main__":
    

    rospy.init_node('initialize dispatching and start planning')

    pddlexecutor().execute()
    
 
    rospy.spin()
