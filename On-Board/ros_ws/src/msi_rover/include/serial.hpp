#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

class Serial {
  private:
    int _FILE_H;
  public:
    Serial(const char* port, speed_t speed);
    void send(char*, int);
    void send(char);
    void receive(char*, int);
    void receive(char);
};

Serial::Serial(const char* port, speed_t speed) {
  _FILE_H = open(port, O_RDWR | O_NONBLOCK);

  struct termios tty;
  memset(&tty, 0, sizeof(tty));
  tty.c_iflag     = 0;
  tty.c_oflag     = 0;
  tty.c_cflag     = CS8|CREAD|CLOCAL;
  tty.c_lflag     = 0;
  tty.c_cc[VMIN]  = 1;
  tty.c_cc[VTIME] = 5;
  cfsetospeed(&tty, speed);
  cfsetispeed(&tty, speed);

  tcflush(  _FILE_H, TCIFLUSH);
  tcsetattr(_FILE_H, TCSANOW,   &tty);
  tcsetattr(_FILE_H, TCSAFLUSH, &tty);
}
void Serial::send(char* str, int len) {
	write(_FILE_H, str, len);
}
void Serial::send(char str) {
	write(_FILE_H, &str, 1);
}
void Serial::receive(char* str, int len) {
	read(_FILE_H, str, len);
}
void Serial::receive(char str) {
	read(_FILE_H, &str, 1);
}
