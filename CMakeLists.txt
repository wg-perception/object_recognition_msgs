cmake_minimum_required(VERSION 2.8)
project(object_recognition_msgs)

find_package(catkin REQUIRED)
catkin_stack()
catkin_project(object_recognition_msgs)

# generate the messages and the actionlib server for ROS
find_package(genmsg REQUIRED)

if (genmsg_FOUND)
    if ("$ENV{ROS_ROOT}" STREQUAL "/opt/ros/electric/ros")
        set(ROS_ELECTRIC_FOUND TRUE)
    else()
        unset(ROS_ELECTRIC_FOUND)
    endif()
    if (ROS_ELECTRIC_FOUND)
        find_package(ecto)
        find_ros_package(actionlib_msgs)
        find_package(actionlib)
        find_ros_package(arm_navigation_msgs)
        find_ros_package(geometry_msgs)
        find_ros_package(sensor_msgs)
        find_ros_package(std_msgs)
        find_ros_package(visualization_msgs)
        set(arm_navigation_msgs_MSG_INCLUDE_DIRS /opt/ros/electric/stacks/arm_navigation/arm_navigation_msgs/msg)
        include_directories(SYSTEM /opt/ros/electric/stacks/arm_navigation/arm_navigation_msgs/msg_gen/cpp/include/)
        set(arm_navigation_msgs_SOURCE_DIR whatever)
        set(arm_navigation_msgs_FOUND True)
    else()
        find_package(ROS REQUIRED actionlib_msgs geometry_msgs rosbag roscpp sensor_msgs visualization_msgs)
        set(arm_navigation_msgs_MSG_INCLUDE_DIRS /opt/ros/fuerte/stacks/arm_navigation/arm_navigation_msgs/msg)
        include_directories(SYSTEM /opt/ros/fuerte/stacks/arm_navigation/arm_navigation_msgs/msg_gen/cpp/include/)
        set(arm_navigation_msgs_SOURCE_DIR whatever)
        set(arm_navigation_msgs_FOUND True)

        add_action_files(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/action FILES ObjectRecognition.action)
        add_service_files(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/srv FILES GetObjectInformation.srv)
    endif()

    add_message_files(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/msg
                      FILES ObjectId.msg
                            ObjectInformation.msg
                            RecognizedObject.msg
                            RecognizedObjectArray.msg
    )

    generate_messages(DEPENDENCIES actionlib_msgs arm_navigation_msgs geometry_msgs sensor_msgs std_msgs visualization_msgs)
endif()


# generate ecto cells to wrap the different messages
find_package(ecto_ros REQUIRED)
pubsub_gen_wrap(object_recognition_msgs)
