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
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(action_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(shape_msgs REQUIRED)

set(msg_files
	"msg/ObjectInformation.msg"
	"msg/ObjectType.msg"
	"msg/RecognizedObject.msg"
	"msg/RecognizedObjectArray.msg"
	"msg/Table.msg"
	"msg/TableArray.msg"
)
set(srv_files
	"srv/GetObjectInformation.srv"
)
set(action_files
	"action/ObjectRecognition.action"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  ${srv_files}
  DEPENDENCIES
		action_msgs
		std_msgs
		geometry_msgs
		sensor_msgs
		shape_msgs
)

# define the project
ament_package()
