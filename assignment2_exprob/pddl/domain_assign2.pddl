(define (domain assignment2)

(:requirements :strips :typing :fluents :disjunctive-preconditions :durative-actions)

(:types
    waypoint 
    robot
    marker
)

(:predicates
    (robot_at ?v - robot ?wp - waypoint)
    (visited ?wp - waypoint)
    (localised ?v - robot)
    (reach_init ?wp - waypoint)
    (marker_found ?m - marker)
    (marker_at ?m - marker ?wp - waypoint)
    
)

(:functions
    (mark_identified ?v - robot ?wp - waypoint) 
)


(:durative-action reachwp
    :parameters (?v - robot ?from ?to - waypoint)
    :duration ( = ?duration 60) 
    :condition (and
        (at start (robot_at ?v ?from))
        (at start (localised ?v)))
    :effect (and
        (at end (visited ?to))
        (at end (robot_at ?v ?to))
        (at start (not (robot_at ?v ?from))))
)

;; Detect marker 
(:durative-action detect_marker
    :parameters (?v - robot ?m - marker ?wp - waypoint)
    :duration ( = ?duration 10) 
    :condition (and
        (at start (robot_at ?v ?wp))
        (at start (marker_at ?m ?wp)))
    :effect (and
        (at end (increase (mark_identified ?v ?wp) 1)) 
        (at end (marker_found ?m)))
)

;; Go back to initial waypoint 
(:durative-action goback
    :parameters (?v - robot ?from ?to - waypoint)
    :duration ( = ?duration 30) 
    :condition (and
        (at start (robot_at ?v ?from))
        ;;the robot can go back only if he found all the markers 
        (at start (= (mark_identified ?v ?from) 4)) 
    )
    :effect (and
        (at start (not (robot_at ?v ?from)))
        (at end (robot_at ?v ?to))
        (at end (reach_init ?to)))
)

)

