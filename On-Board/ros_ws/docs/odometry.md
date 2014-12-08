# Documentation for Odometry Nodes
## GPS Interfacing Node
* Messages Published
  - `<sensor_msgs::NavSatFix>/rover/gps/fix`<br\>Raw GPS data from receiver for `robot_localization::navsat_transform_node`
  - `<geometry_msgs::TwistWithCovarianceStamped>/rover/gps/vel`<br\>Raw GPS data from receiver for `robot_localization::ekf_localization_node`
* Services Provided
  - `{<sensor_msgs::NavSatFix>,<std_msgs::Bool>}/rover/gps/setFix`<br\>Send aiding data for the receiver.
  - `{<geometry_msgs::TwistWithCovarianceStamped>,<std_msgs::Bool>/rover/gps/setVel`<br\>Send aiding data for the receiver.
* Other I/Os
  - Serial/USB port to communicate with reciever
  
## EKF Localization Node w/o GPS
* Messages Subscribed
* Messages Published
* Services Provided
* Services Used

## NavSatTransform Node
* Messages Subscribed
* Messages Published
* Services Provided
* Services Used

## EKF Localization Node w/ GPS
* Messages Subscribed
* Messages Published
* Services Provided
* Services Used
