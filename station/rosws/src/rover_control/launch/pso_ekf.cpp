#define NP 50
#define NI 120
#define NS 100000

#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

double odom_noise_cov[NP][15];
double map_noise_cov[NP][15];

double pbest_odom[NP][NI][15];
double gbest_odom[NI][15];
double pbestfitness_odom[NP][NI];
double fitness_odom[NP][NI];
double gbestfitness_odom;

double pbest_map[NP][NI][15];
double gbest_map[NI][15];
double pbestfitness_map[NP][NI];
double fitness_map[NP][NI];
double gbestfitness_map;

void write_odom_launch() {
/*********************************************************************/
/****************** WRITE ODOMETRY EKF LAUNCH FILE *******************/
/*********************************************************************/

  ofstream odom_launch;
  odom_launch.open("odom_ekf.launch", ios::out | ios::trunc );
  odom_launch << "<launch>\r\n";
  for (uint8_t i = 0; i < NP; i++) {
    odom_launch << "  <group ns=\"ODOM" << (unsigned int)(unsigned char)i << "\" clear_params=\"true\">\r\n";
    odom_launch << "    <node pkg=\"robot_localization\" type=\"ekf_localization_node\" name=\"odom_ekf\" clear_params=\"true\">\r\n";
    odom_launch << "      <param name=\"frequency\" value=\"100\"/>\r\n";
    odom_launch << "      <param name=\"sensor_timeout\" value=\"0.01\"/>\r\n";
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
    odom_launch << "      <param name=\"debug_out_file\"  value=\"/home/singularity/cloud/git/MSI-URC-2015/station/rosws/log/debug_ekf_odom_" << (unsigned int)(unsigned char)i << ".txt\"/>\r\n";

    odom_launch << std::fixed << std::setprecision(5);
    odom_launch << "      <rosparam param=\"process_noise_covariance\">[" << odom_noise_cov[i][ 0] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    odom_launch << "                                                  0.00000, " << odom_noise_cov[i][ 1] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    odom_launch << "                                                  0.00000, 0.00000, " << odom_noise_cov[i][ 2] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    odom_launch << "                                                  0.00000, 0.00000, 0.00000, " << odom_noise_cov[i][ 3] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    odom_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, " << odom_noise_cov[i][ 4] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    odom_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << odom_noise_cov[i][ 5] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    odom_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << odom_noise_cov[i][ 6] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    odom_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << odom_noise_cov[i][ 7] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    odom_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << odom_noise_cov[i][ 8] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    odom_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << odom_noise_cov[i][ 9] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    odom_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << odom_noise_cov[i][10] << ", 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    odom_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << odom_noise_cov[i][11] << ", 0.00000, 0.00000, 0.000,\r\n";
    odom_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << odom_noise_cov[i][12] << ", 0.00000, 0.000,\r\n";
    odom_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << odom_noise_cov[i][13] << ", 0.000,\r\n";
    odom_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << odom_noise_cov[i][14] << "]</rosparam>\r\n";
    odom_launch << "      <remap from=\"odometry/filtered\" to=\"/rover/" << (unsigned int)(unsigned char)i << "/localization/odometry\"/>\r\n";
    odom_launch << "    </node>\r\n";
    odom_launch << "  </group>\r\n";
  }
  odom_launch << "</launch>";
  odom_launch.close();

/*********************************************************************/
}

void write_map_launch() {
/*********************************************************************/
/********************* WRITE MAP EKF LAUNCH FILE *********************/
/*********************************************************************/

  ofstream map_launch;
  map_launch.open("map_ekf.launch", ios::out | ios::trunc );
  map_launch << "<launch>\r\n";
  for (uint8_t i = 0; i < NP; i++) {
    map_launch << "  <group ns=\"MAP" << (unsigned int)(unsigned char)i << "\" clear_params=\"true\">\r\n";
    map_launch << "    <node pkg=\"robot_localization\" type=\"ekf_localization_node\" name=\"map_ekf\" clear_params=\"true\">\r\n";
    map_launch << "      <param name=\"frequency\" value=\"100\"/>\r\n";
    map_launch << "      <param name=\"sensor_timeout\" value=\"0.01\"/>\r\n";
    map_launch << "      <param name=\"two_d_mode\" value=\"false\"/>\r\n";
    map_launch << "      <param name=\"map_frame\" value=\"map\"/>\r\n";
    map_launch << "      <param name=\"odom_frame\" value=\"odom\"/>\r\n";
    map_launch << "      <param name=\"base_link_frame\" value=\"base_link\"/>\r\n";
    map_launch << "      <param name=\"world_frame\" value=\"map\"/>\r\n";

    map_launch << "      <param name=\"odom0\" value=\"/rover/" << (unsigned int)(unsigned char)i << "/localization/odometry\"/>\r\n";
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
    map_launch << "      <param name=\"debug_out_file\"  value=\"/home/singularity/cloud/git/MSI-URC-2015/station/rosws/log/debug_ekf_map_" << (unsigned int)(unsigned char)i << ".txt\"/>\r\n";

    map_launch << std::fixed << std::setprecision(5);
    map_launch << "      <rosparam param=\"process_noise_covariance\">[" << map_noise_cov[i][ 0] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    map_launch << "                                                  0.00000, " << map_noise_cov[i][ 1] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    map_launch << "                                                  0.00000, 0.00000, " << map_noise_cov[i][ 2] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    map_launch << "                                                  0.00000, 0.00000, 0.00000, " << map_noise_cov[i][ 3] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    map_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, " << map_noise_cov[i][ 4] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    map_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << map_noise_cov[i][ 5] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    map_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << map_noise_cov[i][ 6] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    map_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << map_noise_cov[i][ 7] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    map_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << map_noise_cov[i][ 8] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    map_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << map_noise_cov[i][ 9] << ", 0.00000, 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    map_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << map_noise_cov[i][10] << ", 0.00000, 0.00000, 0.00000, 0.000,\r\n";
    map_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << map_noise_cov[i][11] << ", 0.00000, 0.00000, 0.000,\r\n";
    map_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << map_noise_cov[i][12] << ", 0.00000, 0.000,\r\n";
    map_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << map_noise_cov[i][13] << ", 0.000,\r\n";
    map_launch << "                                                  0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, " << map_noise_cov[i][14] << "]</rosparam>\r\n";
    map_launch << "      <remap from=\"odometry/filtered\" to=\"/rover/" << (unsigned int)(unsigned char)i << "/localization/map\"/>\r\n";
    map_launch << "    </node>\r\n";
    map_launch << "  </group>\r\n";
  }
  map_launch << "</launch>";
  map_launch.close();

/*********************************************************************/
}

void init_odom_cov() {
/*********************************************************************/
/******************* INITIALIZE ODOMETRY COVARIANCES *****************/
/*********************************************************************/
  for (uint8_t i = 0; i < NP; i++) {
    odom_noise_cov[i][ 0] = 0.050 + 0.050 * (float)rand()/RAND_MAX;
    odom_noise_cov[i][ 1] = 0.050 + 0.050 * (float)rand()/RAND_MAX;
    odom_noise_cov[i][ 2] = 0.100 + 0.050 * (float)rand()/RAND_MAX;
    odom_noise_cov[i][ 3] = 0.030 + 0.030 * (float)rand()/RAND_MAX;
    odom_noise_cov[i][ 4] = 0.030 + 0.030 * (float)rand()/RAND_MAX;
    odom_noise_cov[i][ 5] = 0.060 + 0.030 * (float)rand()/RAND_MAX;
    odom_noise_cov[i][ 6] = 0.025 + 0.030 * (float)rand()/RAND_MAX;
    odom_noise_cov[i][ 7] = 0.025 + 0.030 * (float)rand()/RAND_MAX;
    odom_noise_cov[i][ 8] = 0.050 + 0.030 * (float)rand()/RAND_MAX;
    odom_noise_cov[i][ 9] = 0.010 + 0.020 * (float)rand()/RAND_MAX;
    odom_noise_cov[i][10] = 0.010 + 0.020 * (float)rand()/RAND_MAX;
    odom_noise_cov[i][11] = 0.020 + 0.020 * (float)rand()/RAND_MAX;
    odom_noise_cov[i][12] = 0.010 + 0.020 * (float)rand()/RAND_MAX;
    odom_noise_cov[i][13] = 0.010 + 0.020 * (float)rand()/RAND_MAX;
    odom_noise_cov[i][14] = 0.020 + 0.020 * (float)rand()/RAND_MAX;
  }
  write_odom_launch();
/*********************************************************************/
}

void init_map_cov() {
/*********************************************************************/
/********************* INITIALIZE MAP COVARIANCES ********************/
/*********************************************************************/
  for (uint8_t i = 0; i < NP; i++) {
    map_noise_cov[i][ 0] = 0.050 + 0.050 * (float)rand()/RAND_MAX;
    map_noise_cov[i][ 1] = 0.050 + 0.050 * (float)rand()/RAND_MAX;
    map_noise_cov[i][ 2] = 0.100 + 0.050 * (float)rand()/RAND_MAX;
    map_noise_cov[i][ 3] = 0.030 + 0.030 * (float)rand()/RAND_MAX;
    map_noise_cov[i][ 4] = 0.030 + 0.030 * (float)rand()/RAND_MAX;
    map_noise_cov[i][ 5] = 0.060 + 0.030 * (float)rand()/RAND_MAX;
    map_noise_cov[i][ 6] = 0.025 + 0.030 * (float)rand()/RAND_MAX;
    map_noise_cov[i][ 7] = 0.025 + 0.030 * (float)rand()/RAND_MAX;
    map_noise_cov[i][ 8] = 0.050 + 0.030 * (float)rand()/RAND_MAX;
    map_noise_cov[i][ 9] = 0.010 + 0.020 * (float)rand()/RAND_MAX;
    map_noise_cov[i][10] = 0.010 + 0.020 * (float)rand()/RAND_MAX;
    map_noise_cov[i][11] = 0.020 + 0.020 * (float)rand()/RAND_MAX;
    map_noise_cov[i][12] = 0.010 + 0.020 * (float)rand()/RAND_MAX;
    map_noise_cov[i][13] = 0.010 + 0.020 * (float)rand()/RAND_MAX;
    map_noise_cov[i][14] = 0.020 + 0.020 * (float)rand()/RAND_MAX;
  }
  write_map_launch();
/*********************************************************************/
}

void run() {
  cout << system("roslaunch rover_control odom_ekf.launch &") << endl;
  cout << system("roslaunch rover_control map_ekf.launch &") << endl;
  sleep(30);
  cout << system("kill `ps -ef | grep -Pe \"odom_ekf.launch$\" | grep -oPe \"^[^0-9]*[0-9]*\" | grep -oPe \"[0-9]*\"`") << endl;
  cout << system("kill `ps -ef | grep -Pe \"map_ekf.launch$\" | grep -oPe \"^[^0-9]*[0-9]*\" | grep -oPe \"[0-9]*\"`") << endl;
  sleep(30);
}

void update_odom_cov() {

}

void update_map_cov() {

}

int main() {
  init_odom_cov();
  init_map_cov();
//  for(uint8_t i = 0; i < NI; i++) {
    run();
    update_odom_cov();
    update_map_cov();
//  }
}
