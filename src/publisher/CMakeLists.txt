set_ecto_install_package_name(object_recognition_msgs/ecto_cells)

find_package(ecto_ros REQUIRED)
include_directories(SYSTEM
                    ${ecto_ros_INCLUDE_DIRS}
                    /opt/ros/electric/stacks/ros_comm/clients/cpp/roscpp/include
                    /opt/ros/fuerte/include
)

ectomodule(ecto_tabletop
  ecto_tabletop.cpp
  wrap_tabletop_TableArray.cpp
)

link_ecto(ecto_tabletop
  ${OpenCV_LIBS}
  ${roscpp_LIBRARIES}
  ${rosbag_LIBRARIES}
  ${geometry_msgs_LIBRARIES}
  ${sensor_msgs_LIBRARIES}
  )

install_ecto_module(ecto_tabletop)
