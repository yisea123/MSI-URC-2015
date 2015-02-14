#define JOY_AXES_BASE   3.0
#define JOY_AXES_OFFSET 0.4

#define JOY_AXES     6
#define JOY_BUTTONS 12

#define JOY_BUTTON_BREAK       7
#define JOY_AXIS_DRIVE_FORWARD 3
#define JOY_AXIS_DRIVE_LEFT    0

#define JOY_ARM_BUTTON_A       0
#define JOY_ARM_BUTTON_B       1
#define JOY_ARM_BUTTON_C       2
#define JOY_ARM_BUTTON_D       3
#define JOY_ARM_BUTTON_E       4
#define JOY_ARM_BUTTON_F       5

#include <ros/ros.h>
#include <csignal>
#include <stdint.h>
#include <math.h>
#include <communication/uart.h>
#include <sensor_msgs/Joy.h>
#include <string>
#include <sstream>

void joyCallback(const sensor_msgs::Joy::ConstPtr& msg);

void Init();
void Reset();
void LoopPreCallback();
void LoopPostCallback();
void Shutdown(int signum);

Serial Telemetry;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Telemetry");
    ros::NodeHandle n("rover");
    ros::Subscriber sub = n.subscribe("/joy", 1, joyCallback);

    Init();
    Reset();
    ros::Rate rate(10);
    while(ros::ok()) {
      LoopPreCallback();
      ros::spinOnce();
      LoopPostCallback();
      rate.sleep();
    }
    Shutdown(0);
    return 0;
}

double axes[JOY_AXES];
bool   buttons[JOY_BUTTONS];

void joyCallback(const sensor_msgs::Joy::ConstPtr& msg)
{
  for (uint8_t i = 0; i < JOY_AXES; i++) {
    axes[i] = (msg->axes[i] < 0)?((-msg->axes[i] > 0.02)?(-msg->axes[i] + JOY_AXES_OFFSET):0):((msg->axes[i] > 0.02)?(msg->axes[i] + JOY_AXES_OFFSET):0);
    axes[i] = ((msg->axes[i]<0)?-1:1)*((pow(JOY_AXES_BASE, axes[i]) - 1) * 127) / (pow(JOY_AXES_BASE, 1 + JOY_AXES_OFFSET) - 1);
  }
  for (uint8_t i = 0; i < JOY_BUTTONS; i++)
    buttons[i] = msg->buttons[i];
}
