#Communication Protocol
Communication system consists of two parts.
* Communication between base station and main controller.
* Communication between main controller and sub-systems.

##Base Station &harr; Main Controller

##Main Controller &harr; Sub-systems
Main controller (master) communicates with sub-systems (slaves) over I2C (100kHz) or SPI (4MHz).
The communication method between main controller and each sub-system can be changed with a command from base station.
The command only changes the method on main controller, the slave boards always support both methods.

The I2C/SPI addresses are listed down in the following table.

| Sub-system | I2C address | SPI address |
|:---------- | -----------:| -----------:|
| Drive      |           5 |           0 |
| Arm        |           6 |           1 |
| BMS_1*     |           7 |           2 |
| BMS_2*     |           8 |           3 |
| Bio        |           9 |           4 |

<sub><sup>\* BMS is given 2 addresses just in case it needs them. If two addresses are not needed use only BMS_1.</sup></sub>

The I2C/SPI commands are listed down in the following table.

| Command | Description               | Length  |
|:------- |:------------------------- | -------:|
| 0x5A    | Drive directive           | 04 (12) |
| 0x51    | Encoder data request      | 22 (22) |
| 0x52    | Ultrasonic data request   | 08 (16) |
| 0x53    | Drive pot data request    | 08 (08) |
| 0x54    | Drive status query        | 01 (01) |
| 0x6A    | Arm command               |      01 |
| 0x61    | Arm pot data request      |     TBD |
| 0x62    | Arm status query          |      01 |
| .       | .                         |       . |
| .       | .                         |       . |
| .       | .                         |       . |
| TBD     | TBD                       |     TBD |

<sub><sup>\* Length in bracket is for experimental CPLD board.</sup></sub>

###Command Description
####Drive directive (0x5A)
#####Due
| Offset  | Name   | Description                                      | Unit   | Type        |
|:------- |:------ |:------------------------------------------------ |:------:| -----------:|
| 0       | CTRL1  | Control byte 1                                   | -      | Masked byte |
| 1       | CTRL2  | Control byte 2                                   | -      | Masked byte |
| 2       | FPWM   | Forward PWM (-100 to 100)                        | -      | int8_t      |
| 3       | RYAW   | Yaw relative to present yaw (-90 to 90)          | deg/2  | int8_t      |

#####CPLD
| Offset  | Name   | Description                                      | Unit   | Type        |
|:------- |:------ |:------------------------------------------------ |:------:| -----------:|
| 0       | CTRL1  | Control byte 1                                   | -      | Masked byte |
| 1       | CTRL2  | Control byte 2                                   | -      | Masked byte |
| 2       | SPWMFL | Steering PWM front left motor (-100 to 100)      | -      | int8_t      |
| 3       | SPWMRL | Steering PWM rear left motor (-100 to 100)       | -      | int8_t      |
| 4       | SPWMRR | Steering PWM rear right motor (-100 to 100)      | -      | int8_t      |
| 5       | SPWMFR | Steering PWM front right motor (-100 to 100)     | -      | int8_t      |
| 6       | PWMFL  | Drive PWM front left motor (-100 to 100)         | -      | int8_t      |
| 7       | PWMML  | Drive PWM middle left motor (-100 to 100)        | -      | int8_t      |
| 8       | PWMRL  | Drive PWM rear left motor (-100 to 100)          | -      | int8_t      |
| 9       | PWMRR  | Drive PWM rear right motor (-100 to 100)         | -      | int8_t      |
| 10      | PWMMR  | Drive PWM middle right motor (-100 to 100)       | -      | int8_t      |
| 11      | PWMFR  | Drive PWM front right motor (-100 to 100)        | -      | int8_t      |

#####Definitions
######CTRL1
| T | - | - | - | SENAFR | SENARR | SENARL | SENAFL |
|:-:|:-:|:-:|:-:|:------:|:------:|:------:|:------:|
T : Turn in place at speed given by PWMFL or FPWM

######CTRL2
| - | - | ENAFR | ENAMR | ENARR | ENARL | ENAML | ENAFL |
|:-:|:-:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
