# Documentation for Odometry Nodes
## GPS Interfacing Node
* Messages Published
  - `<nav_msgs::Odometry>/rover/gps/pos`<br\>Raw GPS data from receiver for `robot_localization::ekf_localization_node`
  - `<sensor_msgs::NavSatFix>/rover/gps/fix`<br\>Raw GPS data from receiver for debugging purposes
  - `<geometry_msgs::TwistWithCovarianceStamped>/rover/gps/vel`<br\>Raw GPS data from receiver for `robot_localization::ekf_localization_node`
* Services Provided
  - `{<nav_msgs::Odometry>,<std_msgs::Bool>}/rover/gps/setPos`<br\>Send aiding data for the receiver.
  - `{<sensor_msgs::NavSatFix>,<std_msgs::Bool>}/rover/gps/setFix`<br\>Send aiding data for the receiver.
  - `{<geometry_msgs::TwistWithCovarianceStamped>,<std_msgs::Bool>/rover/gps/setVel`<br\>Send aiding data for the receiver.
* Other I/Os
  - Serial/USB port to communicate with reciever

## Arduino Odometry Interfacing Node
* Messages Published
  - `<geometry_msgs::Vector3Stamped>/rover/imu/angular_velocity`
  - `<geometry_msgs::Vector3Stamped>/rover/imu/linear_acceleration`
  - `<geometry_msgs::Vector3Stamped>/rover/imu/magnetic_compass`
  - `<std_msgs::UInt16MultiArray>/rover/encoders/raw`

## Odometry Preprocessing Node
* Messages Subscribed
  - `<geometry_msgs::Vector3Stamped>/rover/imu/angular_velocity`
  - `<geometry_msgs::Vector3Stamped>/rover/imu/linear_acceleration`
  - `<geometry_msgs::Vector3Stamped>/rover/imu/magnetic_compass`
  - `<std_msgs::UInt16MultiArray>/rover/encoders/raw`
* Messages Published
  - `<sensor_msgs::Imu>/rover/imu/data`
  - `<geometry_msgs::TwistWithCovarianceStamped>/rover/encoders/twist`
* Services Provided
* Services Used

## EKF Localization Node w/o GPS
* Messages Subscribed
* Messages Published
* Services Provided
* Services Used

## EKF Localization Node w/ GPS
* Messages Subscribed
* Messages Published
* Services Provided
* Services Used
