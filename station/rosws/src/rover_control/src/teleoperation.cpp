#include <communication/protocol.h>
#include <rover/teleoperation.h>
#include <ros/package.h>

void Init() {
}

void Reset() {
  Telemetry.disconnect();
  while (Telemetry.connect("/dev/ttyUSB0",B19200) < 0 && ros::ok()) {ROS_ERROR("Unable to open /dev/ttyUSB0!"); usleep(1000000);}
}

void LoopPreCallback() {
  std::ostringstream oss;
  unsigned char CK = 0;

  oss << _PROTO_DELIM << _DRIVE_MSG_ID
      << (unsigned char)(int8_t)buttons[JOY_BUTTON_BREAK]
      << (unsigned char)(int8_t)axes[JOY_AXIS_DRIVE_FORWARD]
      << (unsigned char)(int8_t)axes[JOY_AXIS_DRIVE_LEFT];
#ifdef _PROTO_CHECKSUM
  for(uint8_t i = 1; i < oss.str().length(); i++) CK = CK + oss.str()[i];
  oss << CK;
#endif

  Telemetry.put(oss.str());
//  for(int i=0; i < oss.str().length(); i++) std::cout << (unsigned int)(unsigned char)oss.str()[i] << ", ";
//  std::cout << "\r\n";
  oss.str("");
  oss.clear();
  oss << _PROTO_DELIM << _ARM_MSG_ID;

if ((buttons[0] == 1) && (buttons[1] == 0) && (buttons[2] == 0) && (buttons[3] == 0) && (buttons[4] == 0) && (buttons[5] == 0))
  oss << (unsigned char)1;
else if ((buttons[0] == 0) && (buttons[1] == 1) && (buttons[2] == 0) && (buttons[3] == 0) && (buttons[4] == 0) && (buttons[5] == 0))
  oss << (unsigned char)2;
else if ((buttons[0] == 0) && (buttons[1] == 0) && (buttons[2] == 1) && (buttons[3] == 0) && (buttons[4] == 0) && (buttons[5] == 0))
  oss << (unsigned char)3;
else if ((buttons[0] == 0) && (buttons[1] == 0) && (buttons[2] == 0) && (buttons[3] == 1) && (buttons[4] == 0) && (buttons[5] == 0))
  oss << (unsigned char)4;
else if ((buttons[0] == 0) && (buttons[1] == 0) && (buttons[2] == 0) && (buttons[3] == 0) && (buttons[4] == 1) && (buttons[5] == 0))
  oss << (unsigned char)5;
else if ((buttons[0] == 0) && (buttons[1] == 0) && (buttons[2] == 0) && (buttons[3] == 0) && (buttons[4] == 0) && (buttons[5] == 1))
  oss << (unsigned char)6;
else
  oss << (unsigned char)0;

#ifdef _PROTO_CHECKSUM
  for(uint8_t i = 1; i < oss.str().length(); i++) CK = CK + oss.str()[i];
  oss << CK;
#endif

  Telemetry.put(oss.str());
//  for(int i=0; i < oss.str().length(); i++) std::cout << (unsigned int)(unsigned char)oss.str()[i] << ", ";
//  std::cout << "\r\n";
  oss.str("");
  oss.clear();

  //! ------------------- !//
  //! ------ TODO: ------ !//
  //! Add more controls   !//
  //! ------------------- !//
}

void LoopPostCallback() {

}

void Shutdown(int signum) {
  ros::shutdown();
}
