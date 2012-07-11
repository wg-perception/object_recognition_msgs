cmake_minimum_required(VERSION 2.8)
project(object_recognition_msgs)

find_package(catkin REQUIRED)
catkin_stack()
catkin_project(object_recognition_msgs
               INCLUDE_DIRS include)

# generate the messages and the actionlib server for ROS
find_package(genmsg REQUIRED)

find_package(ecto REQUIRED)
set_ecto_install_package_name(object_recognition_msgs/ecto_cells)

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
        find_ros_package(geometry_msgs)
        find_ros_package(sensor_msgs)
        find_ros_package(std_msgs)
        find_ros_package(visualization_msgs)
    else()
        find_package(ROS REQUIRED actionlib_msgs geometry_msgs rosbag roscpp sensor_msgs shape_msgs visualization_msgs)

        add_action_files(DIRECTORY action FILES ObjectRecognition.action)
        add_service_files(DIRECTORY srv FILES GetObjectInformation.srv)
    endif()

    add_message_files(DIRECTORY msg
                      FILES ObjectId.msg
                            ObjectInformation.msg
                            RecognizedObject.msg
                            RecognizedObjectArray.msg
                            Shape.msg
                            Table.msg
                            TableArray.msg
    )

    generate_messages(DEPENDENCIES actionlib_msgs geometry_msgs sensor_msgs shape_msgs std_msgs visualization_msgs)
endif()

# generate ecto cells to wrap the different messages
find_package(ecto_ros REQUIRED)
pubsub_gen_wrap(object_recognition_msgs ObjectId ObjectInformation RecognizedObject RecognizedObjectArray Table TableArray)

add_subdirectory(python)

# install the include folder
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION include
        COMPONENT main
)
