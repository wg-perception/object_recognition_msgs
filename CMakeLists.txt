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
        find_pacakge(ecto REQUIRED)
        find_ros_package(actionlib_msgs)
        find_ros_package(geometry_msgs)
        find_ros_package(sensor_msgs)
        find_ros_package(std_msgs)
        find_ros_package(visualization_msgs)
        include_directories(SYSTEM
                            ${ecto_ros_INCLUDE_DIRS}
        )
    else()
        find_package(ROS REQUIRED actionlib_msgs geometry_msgs rosbag roscpp sensor_msgs visualization_msgs)
    endif()

    add_message_files(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/msg FILES RecognizedObject.msg RecognizedObjectArray.msg Shape.msg)
    add_action_files(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/action FILES ObjectRecognition.action)

    generate_messages(DEPENDENCIES actionlib_msgs geometry_msgs sensor_msgs std_msgs visualization_msgs)
endif()
