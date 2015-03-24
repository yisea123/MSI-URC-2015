#define NP 30
#define NI 50
#define NS 100000

#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdint.h>
using namespace std;

double odom_noise_cov[NP][15];
double map_noise_cov[15];

void write_odom_launch() {
/*********************************************************************/
/****************** WRITE ODOMETRY EKF LAUNCH FILE *******************/
/*********************************************************************/

  ofstream odom_launch;
  odom_launch.open("odom_ekf.launch", ios::out | ios::trunc );
  odom_launch << "<launch>\r\n";
  for (uint8_t i = 0; i < NP; i++) {
    odom_launch << "  <group ns=\"" << (unsigned int)(unsigned char)i << "\" clear_params=\"true\">\r\n";
    odom_launch << "    <node pkg=\"robot_localization\" type=\"ekf_localization_node\" name=\"odom_ekf\" clear_params=\"true\">\r\n";
    odom_launch << "      <param name=\"frequency\" value=\"10\"/>\r\n";
    odom_launch << "      <param name=\"sensor_timeout\" value=\"0.1\"/>\r\n";
    odom_launch << "      <param name=\"two_d_mode\" value=\"false\"/>\r\n";
    odom_launch << "      <param name=\"map_frame\" value=\"map\"/>\r\n";
    odom_launch << "      <param name=\"odom_frame\" value=\"odom\"/>\r\n";
    odom_launch << "      <param name=\"base_link_frame\" value=\"base_link\"/>\r\n";
    odom_launch << "      <param name=\"world_frame\" value=\"odom\"/>\r\n";

    odom_launch << "      <param name=\"twist0\" value=\"/rover/sensors/encoders/data\"/>\r\n";
    odom_launch << "<!--  <param name=\"twist1\" value=\"/rover/sensors/camera/twist_feedback\"/>    -->\r\n";
    odom_launch << "<!--  <param name=\"pose0\" value=\"/rover/sensors/camera/pose_feedback\"/>    -->\r\n";
    odom_launch << "      <param name=\"imu0\" value=\"/rover/sensors/imu/data\"/>\r\n";

    odom_launch << "      <rosparam param=\"twist0_config\">[false, false, false,\r\n";
    odom_launch << "                                       false, false, false,\r\n";
    odom_launch << "                                       true,  true,  true,\r\n";
    odom_launch << "                                       true,  true,  true,\r\n";
    odom_launch << "                                       false, false, false]</rosparam>\r\n";
    odom_launch << "<!--  <rosparam param=\"twist1_config\">[false, false, false,\r\n";
    odom_launch << "                                       false, false, false,\r\n";
    odom_launch << "                                       true,  true,  true,\r\n";
    odom_launch << "                                       true,  true,  true,\r\n";
    odom_launch << "                                       false, false, false]</rosparam>    -->\r\n";
    odom_launch << "<!--  <rosparam param=\"pose0_config\">[true,  true,  true,\r\n";
    odom_launch << "                                      true,  true,  true,\r\n";
    odom_launch << "                                      false, false, false,\r\n";
    odom_launch << "                                      false, false, false,\r\n";
    odom_launch << "                                      false, false, false]</rosparam>    -->\r\n";
    odom_launch << "      <rosparam param=\"imu0_config\">[false, false, false,\r\n";
    odom_launch << "                                     true,  true,  true,\r\n";
    odom_launch << "                                     false, false, false,\r\n";
    odom_launch << "                                     true,  true,  true,\r\n";
    odom_launch << "                                     true,  true,  true]</rosparam>\r\n";

    odom_launch << "<!--  <param name=\"pose0_differential\" value=\"true\"/>    -->\r\n";
    odom_launch << "      <param name=\"imu0_differential\" value=\"true\"/>\r\n";
    odom_launch << "      <param name=\"imu0_remove_gravitational_acceleration\" value=\"false\"/>\r\n";

    odom_launch << "      <param name=\"twist0_rejection_threshold\" value=\"1.2\"/>\r\n";
    odom_launch << "<!--  <param name=\"twist1_rejection_threshold\" value=\"1.2\"/>    -->\r\n";
    odom_launch << "<!--  <param name=\"pose0_rejection_threshold\" value=\"2\"/>    -->\r\n";
    odom_launch << "      <param name=\"imu0_pose_rejection_threshold\" value=\"0.3\"/>\r\n";
    odom_launch << "      <param name=\"imu0_angular_velocity_rejection_threshold\" value=\"0.1\"/>\r\n";
    odom_launch << "      <param name=\"imu0_linear_acceleration_rejection_threshold\" value=\"0.1\"/>\r\n";

    odom_launch << "      <param name=\"debug\"           value=\"true\"/>\r\n";
    odom_launch << "      <param name=\"debug_out_file\"  value=\"/home/singularity/debug_ekf_odom_" << i << ".txt\"/>\r\n";

    odom_launch << std::fixed << std::setprecision(3);
    odom_launch << "      <rosparam param=\"process_noise_covariance\">[" << odom_noise_cov[i][ 0] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
    odom_launch << "                                                  0.000, " << odom_noise_cov[i][ 1] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
    odom_launch << "                                                  0.000, 0.000, " << odom_noise_cov[i][ 2] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
    odom_launch << "                                                  0.000, 0.000, 0.000, " << odom_noise_cov[i][ 3] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
    odom_launch << "                                                  0.000, 0.000, 0.000, 0.000, " << odom_noise_cov[i][ 4] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
    odom_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, " << odom_noise_cov[i][ 5] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
    odom_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << odom_noise_cov[i][ 6] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
    odom_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << odom_noise_cov[i][ 7] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
    odom_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << odom_noise_cov[i][ 8] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
    odom_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << odom_noise_cov[i][ 9] << ", 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
    odom_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << odom_noise_cov[i][10] << ", 0.000, 0.000, 0.000, 0.000,\r\n";
    odom_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << odom_noise_cov[i][11] << ", 0.000, 0.000, 0.000,\r\n";
    odom_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << odom_noise_cov[i][12] << ", 0.000, 0.000,\r\n";
    odom_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << odom_noise_cov[i][13] << ", 0.000,\r\n";
    odom_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << odom_noise_cov[i][14] << "]</rosparam>\r\n";
    odom_launch << "      <remap from=\"odometry/filtered\" to=\"/rover/" << (unsigned int)(unsigned char)i << "/localization/odometry\"/>\r\n";
    odom_launch << "    </node>\r\n";
    odom_launch << "  </group>\r\n";
  }
  odom_launch << "</launch>";
  odom_launch.close();

/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
}

void write_map_launch() {
/*********************************************************************/
/********************* WRITE MAP EKF LAUNCH FILE *********************/
/*********************************************************************/

  ofstream map_launch;
  map_launch.open("map_ekf.launch", ios::out | ios::trunc );
  map_launch << "<launch>\r\n";
  map_launch << "    <node pkg=\"robot_localization\" type=\"ekf_localization_node\" name=\"map_ekf\" clear_params=\"true\">\r\n";
  map_launch << "      <param name=\"frequency\" value=\"10\"/>\r\n";
  map_launch << "      <param name=\"sensor_timeout\" value=\"0.1\"/>\r\n";
  map_launch << "      <param name=\"two_d_mode\" value=\"false\"/>\r\n";
  map_launch << "      <param name=\"map_frame\" value=\"map\"/>\r\n";
  map_launch << "      <param name=\"odom_frame\" value=\"odom\"/>\r\n";
  map_launch << "      <param name=\"base_link_frame\" value=\"base_link\"/>\r\n";
  map_launch << "      <param name=\"world_frame\" value=\"map\"/>\r\n";

  map_launch << "      <param name=\"odom0\" value=\"/rover/localization/odometry\"/>\r\n";
  map_launch << "      <param name=\"twist0\" value=\"/rover/sensors/gps/twist\"/>\r\n";
  map_launch << "      <param name=\"pose0\" value=\"/rover/sensors/gps/pose\"/>\r\n";

  map_launch << "      <rosparam param=\"odom0_config\">[true,  true,  true,\r\n";
  map_launch << "                                      true,  true,  true,\r\n";
  map_launch << "                                      true,  true,  true,\r\n";
  map_launch << "                                      true,  true,  true,\r\n";
  map_launch << "                                      true,  true,  true]</rosparam>\r\n";
  map_launch << "      <rosparam param=\"twist0_config\">[false, false, false,\r\n";
  map_launch << "                                       false, false, false,\r\n";
  map_launch << "                                       true,  true,  true,\r\n";
  map_launch << "                                       false, false, false,\r\n";
  map_launch << "                                       false, false, false]</rosparam>\r\n";
  map_launch << "      <rosparam param=\"pose0_config\">[true,  true,  true,\r\n";
  map_launch << "                                      false, false, false,\r\n";
  map_launch << "                                      false, false, false,\r\n";
  map_launch << "                                      false, false, false,\r\n";
  map_launch << "                                      false, false, false]</rosparam>\r\n";

  map_launch << "      <param name=\"odom0_differential\" value=\"true\"/>\r\n";
  map_launch << "      <param name=\"pose0_differential\" value=\"true\"/>\r\n";

  map_launch << "      <param name=\"odom0_pose_rejection_threshold\" value=\"5\"/>\r\n";
  map_launch << "      <param name=\"odom0_twist_rejection_threshold\" value=\"1\"/>\r\n";
  map_launch << "      <param name=\"twist0_rejection_threshold\" value=\"1.2\"/>\r\n";
  map_launch << "      <param name=\"pose0_rejection_threshold\" value=\"2\"/>\r\n";

  map_launch << "      <param name=\"debug\"           value=\"true\"/>\r\n";
  map_launch << "      <param name=\"debug_out_file\"  value=\"/home/singularity/debug_ekf_map.txt\"/>\r\n";

  map_launch << std::fixed << std::setprecision(3);
  map_launch << "      <rosparam param=\"process_noise_covariance\">[" << map_noise_cov[ 0] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
  map_launch << "                                                  0.000, " << map_noise_cov[ 1] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
  map_launch << "                                                  0.000, 0.000, " << map_noise_cov[ 2] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
  map_launch << "                                                  0.000, 0.000, 0.000, " << map_noise_cov[ 3] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
  map_launch << "                                                  0.000, 0.000, 0.000, 0.000, " << map_noise_cov[ 4] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
  map_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, " << map_noise_cov[ 5] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
  map_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << map_noise_cov[ 6] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
  map_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << map_noise_cov[ 7] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
  map_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << map_noise_cov[ 8] << ", 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
  map_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << map_noise_cov[ 9] << ", 0.000, 0.000, 0.000, 0.000, 0.000,\r\n";
  map_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << map_noise_cov[10] << ", 0.000, 0.000, 0.000, 0.000,\r\n";
  map_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << map_noise_cov[11] << ", 0.000, 0.000, 0.000,\r\n";
  map_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << map_noise_cov[12] << ", 0.000, 0.000,\r\n";
  map_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << map_noise_cov[13] << ", 0.000,\r\n";
  map_launch << "                                                  0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, " << map_noise_cov[14] << "]</rosparam>\r\n";
  map_launch << "      <remap from=\"odometry/filtered\" to=\"/rover/localization/map\"/>\r\n";
  map_launch << "    </node>\r\n";
  map_launch << "</launch>";
  map_launch.close();

/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
}

int main() {
  for (uint8_t i = 0; i < NP; i++) {
    odom_noise_cov[i][ 0] = 0.05;
    odom_noise_cov[i][ 1] = 0.05;
    odom_noise_cov[i][ 2] = 0.06;
    odom_noise_cov[i][ 3] = 0.03;
    odom_noise_cov[i][ 4] = 0.03;
    odom_noise_cov[i][ 5] = 0.06;
    odom_noise_cov[i][ 6] = 0.025;
    odom_noise_cov[i][ 7] = 0.025;
    odom_noise_cov[i][ 8] = 0.04;
    odom_noise_cov[i][ 9] = 0.01;
    odom_noise_cov[i][10] = 0.01;
    odom_noise_cov[i][11] = 0.02;
    odom_noise_cov[i][12] = 0.01;
    odom_noise_cov[i][13] = 0.01;
    odom_noise_cov[i][14] = 0.015;
  }
  write_odom_launch();

  map_noise_cov[ 0] = 0.05;
  map_noise_cov[ 1] = 0.05;
  map_noise_cov[ 2] = 0.06;
  map_noise_cov[ 3] = 0.03;
  map_noise_cov[ 4] = 0.03;
  map_noise_cov[ 5] = 0.06;
  map_noise_cov[ 6] = 0.025;
  map_noise_cov[ 7] = 0.025;
  map_noise_cov[ 8] = 0.04;
  map_noise_cov[ 9] = 0.01;
  map_noise_cov[10] = 0.01;
  map_noise_cov[11] = 0.02;
  map_noise_cov[12] = 0.01;
  map_noise_cov[13] = 0.01;
  map_noise_cov[14] = 0.015;
}
