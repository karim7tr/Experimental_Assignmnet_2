(define (problem navigate_world)
(:domain assignment2)
(:objects
        marker11 marker12 marker13 marker15 - marker
        wp0 wp1 wp2 wp3 wp4 - waypoint
        bear - robot
)
(:init

        ;indicate the respective position of each marker 
        (marker_at marker11 wp1)
        (marker_at marker12 wp2)
        (marker_at marker13 wp3)
        (marker_at marker15 wp4)
        (mark_identified bear wp0) ; Initialize the mark_identified function
        (robot_at bear wp0) ; robot at intial position
        (visited wp0) ; Assuming wp0 is the starting point
        ; the remaining wps where the markers are positioned are not visited
        (not (visited wp1)) 
        (not (visited wp2))
        (not (visited wp3))
        (not (visited wp4))
        ;therefore the num of markers found should be 0
        (= (mark_identified bear wp0) 0)

        
)
(:goal (and
        ; now all wps should be visited
        (visited wp0)
        (visited wp1)
        (visited wp2)
        (visited wp3)
        (visited wp4)
        ;since all wps are visited all the markers should be found 
        (marker_found marker11)
        (marker_found marker12)
        (marker_found marker13)
        (marker_found marker15)
        (= (mark_identified bear wp0) 4) ; Condition based on mark_identified
        ;the robot should be also be back to its intiali position wp0
        (robot_at bear wp0)
))
)

