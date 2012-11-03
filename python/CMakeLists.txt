if (ROS_GROOVY_FOUND)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/__init__.py.plain.in
               ${CATKIN_BUILD_PREFIX}/${CATKIN_PACKAGE_PYTHON_DESTINATION}/ecto_cells/__init__.py
               @ONLY
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/__init__.py.plain.in
               ${CATKIN_BUILD_PREFIX}/${CATKIN_PACKAGE_PYTHON_DESTINATION}/__init__.py
               @ONLY
)

install(FILES ${CATKIN_BUILD_PREFIX}/${CATKIN_PACKAGE_PYTHON_DESTINATION}/ecto_cells/__init__.py
        DESTINATION ${CATKIN_GLOBAL_PYTHON_DESTINATION}/${PROJECT_NAME}/ecto_cells/
)

install(FILES ${CATKIN_BUILD_PREFIX}/${CATKIN_PACKAGE_PYTHON_DESTINATION}/__init__.py
        DESTINATION ${CATKIN_GLOBAL_PYTHON_DESTINATION}/${PROJECT_NAME}/
)

else()
set(ECTO_PYTHON_BUILD_PATH ${CMAKE_BINARY_DIR}/gen/py/)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/__init__.py.plain.in
               ${ECTO_PYTHON_BUILD_PATH}/${PROJECT_NAME}/ecto_cells/__init__.py
               @ONLY
)
 
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/__init__.py.plain.in
               ${ECTO_PYTHON_BUILD_PATH}/${PROJECT_NAME}/__init__.py
               @ONLY
)

install(FILES ${ecto_module_PYTHON_OUTPUT}/ecto_cells/__init__.py
        DESTINATION ${PYTHON_PACKAGES_PATH}/object_recognition_msgs/ecto_cells/
)

install(FILES ${ecto_module_PYTHON_OUTPUT}/__init__.py
        DESTINATION ${PYTHON_PACKAGES_PATH}/object_recognition_msgs
)

endif()
