cmake_minimum_required(VERSION 3.5)
project(object_recognition_msgs)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()

# generate the messages and the actionlib server for ROS
find_package(catkin REQUIRED actionlib_msgs genmsg geometry_msgs sensor_msgs shape_msgs std_msgs)

add_action_files(DIRECTORY action FILES ObjectRecognition.action)
add_service_files(DIRECTORY srv FILES GetObjectInformation.srv)

add_message_files(DIRECTORY msg
                  FILES ObjectType.msg
                        ObjectInformation.msg
                        RecognizedObject.msg
                        RecognizedObjectArray.msg
                        Table.msg
                        TableArray.msg
)

generate_messages(DEPENDENCIES actionlib_msgs geometry_msgs sensor_msgs shape_msgs std_msgs)

# define the project
catkin_package(CATKIN_DEPENDS actionlib_msgs geometry_msgs sensor_msgs shape_msgs std_msgs)
