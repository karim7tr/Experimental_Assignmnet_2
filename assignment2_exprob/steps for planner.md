### Step 1:

Define domain as a pddl file i.e.
>domain_planner.pddl

### Step 2:

Define problem as a pddl file i.e.
>problem_planner.pddl

### Step 3: Understanding ROSPlan

In general we need:
1. Problem Generation
2. Planning
3. Plan Execution

To that end, we use five main components:

1) The Knowledge Base
2) The Problem Interface
3) The Planner Interface
4) The Parsing Integrace
5) The Plan Dispatch

#### The Knowledge Base

The Knowledge Base is used to store a PDDL model. In particular, it stores both a domain model and the current problem instance.

**Practically, it:**

- Loads a PDDL domain (and optionally a problem) from a file
- Stores the state as a PDDL instance
- May be updated by ROS messages.
- Can be queried

#### The Problem Interface

The Problem Interface node is used to generate a problem instance.

**Practically, it:**

- It fetches the domain details and current state through service calls to the Knowledge Base node

- Publishes a PDDL **problem instance** as a string, also writing it to a file.


#### The Planner Interface

The planner is called through a service, which returns true if a solution was found.\
**This interface feeds the planner with a problem instance**, and calls the planner.\
The planner **retrieves the domain** by exploiting the services offered **by the Knowledge Base** component.

#### The Parsing Interface

The Parsing Interface node is used to **convert planner output into a plan representation** that can be executed, and whose actions can be dispatched to other parts of the system.

#### The Plan Dispatch

Plan Dispatch includes:
- Plan execution
- The process of connecting single actions to the processes which are responsible for their execution.

An implementation of the Plan Dispatch node **subscribes to a plan topic, and to the action feedback provided by the node** that practically implements the action.


### Step 4: Launching the commands

#### I .  Generating the problem *(Knowledge Base and Problem Interface)*
To generate a problem, we should launch two nodes:

> knowledgeBase *(package rosplan_knowledge_base)*

This node stores the PDDL model: both the domain and the current state, and takes 3 parameters:

- *domain_path* is required and specifies a PDDL domain file.

- *problem_path* is an optional parameter to load an initial state.\
If this parameter is not set, then the state will contain no objects, any propositions will be false, and all functions will be initialised to zero.

- *use_unknowns* is used for conditional planning.\
If **false**, then a proposition not added to the Knowledge Base is assumed to be false in the initial state.\
If **true**, then it is assumed to be unknown; false propositions have to be explicitly stated.

And:
> problemInterface *(package rosplan_planning_system)*


- The Problem Interface also has 4 parameters:

- *knowledge_base* specifies the node name of the Knowledge Base node that stores the current state.

- *domain_path* specifies the path to the domain file used by that Knowledge Base.

- *problem_path* specifies the path into which the new problem file will be written.

- *problem_topic* specifies the topic name on which the problem will be published.

</br>

Indeed, if we generate a new problem by:

1. Calling the **problem interface** service
```cmd
rosservice call /rosplan_problem_interface/problem_generation_server
```
2. Echoing the **/problem instance** topic :
```cmd
rostopic echo /rosplan_problem_interface/problem_instance -p
```
</br>

#### II . Generating the Plan (*Planning Interface)*
We can **generate a plan** based on the problem with:

```cmd
rosservice call /rosplan_planner_interface/planning_server
```

<u>**Note:**</u> You can check the output with:

```cmd
rostopic echo /rosplan_planner_interface/planner_output -p
```
</br>

#### III . Parsing the Plan *(Parsing Interface)*

The **Parsing Interface** will subscribe to the string sent by the planner generating a ROS message with the overall plan.

The node subscribes to the planner_output, and parses the plan, converting it to a ROS message.

*In this case, we are using the pddl_simple_plan_parser, that will represent the plan as an ordered list of action messages.*


```cmd
rosservice call /rosplan_parsing_interface/parse_plan
```
<u>**Note:**</u> You can check the output with:

```cmd
rosservice echo /rosplan_parsing_interface/complete_plan
```

On the topic /rosplan_parsing_interface/complete_plan you will have the plan in the form of a ROS Message (as an array of rosplan_dispatch_msgs/ActionDispatch)

</br>

#### VI . Dispatching the Plan *(Plan Dispatcher)*

The **Plan Dispatcher** will implement a ROS action client to execute the actions one by one, also monitoring their status

The node implements a plan execution algorithm
by subscribing to the message created by the parser
and publishing the action to be implemented on the topic **/action_dispatch.**

*Since we are using the pddl_simple_plan_parser, here we need to use the pddl_simple_plan_dispatcher.*

After we do the three steps listed before, we just need to **start the action dispatching** by calling another service:

```cmd
rosservice call /rosplan_plan_dispatcher/dispatch_plan
```









