################################################## OBJECT INFO #########################################################

# Contains information about the identity and the position of a found object
# Some of those fields might not be filled because the used techniques do not fill them or because the user does not
# request them

# The id of the found object
string id

# The db parameters stored as a JSON/compressed YAML string. An object id does not make sense without the corresponding
# database. E.g., in object_recognition, it can look like: "{'type':'CouchDB', 'root':'http://localhost'}"
# There is no conventional format for those parameters and it's nice to keep that flexibility.
string db

#confidence: how sure you are it is that object and not another one
float32 confidence

################################################ OBJECT CLUSTERS #######################################################

# Sometimes you can extract the 3d points that belong to the object, in the frames of the original sensors
sensor_msgs/PointCloud2[] point_cloud

# Sometimes, you can only provide a bounding box/shape, even in 3d. We probably need a non visualization type there
# This is in the pose frame
visualization_msgs/Marker bounding_mesh

# Sometimes, you only have 2d input so you can't really give a pose, you just get a contour, or a box
# The last point will be linked to the first one automatically
geometry_msgs/Point[] bounding_contour

#################################################### POSE INFO #########################################################

# This is the result that everybody expects : the pose in some frame given with the input. The units are radian/meters
# as usual
geometry_msgs/PoseWithCovarianceStamped pose
