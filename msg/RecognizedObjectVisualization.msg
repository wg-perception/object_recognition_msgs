############################################## VISUALIZATION INFO ######################################################
################### THIS INFO SHOULD BE OBTAINED INDEPENDENTLY FROM THE CORE, LIKE IN AN RVIZ PLUGIN ###################

# The human readable name of the object
string name

# The full mesh of the object: this can be useful for display purposes, augmented reality ... but it can be big
# Make sure the type is MESH_RESOURCE
object_recognition_msgs/Shape ground_truth_mesh
geometry_msgs/Pose ground_truth_mesh_pose

# Sometimes, you only have a cloud in the DB
# Make sure the type is POINTS
sensor_msgs/PointCloud2 ground_truth_point_cloud
geometry_msgs/Pose ground_truth_point_cloud_pose
