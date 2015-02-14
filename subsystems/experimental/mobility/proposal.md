#Mobility on CPLD
Number of pins and operating speeds required for complete implementation of mobility subsystem are more than arduino or similar
microcontrollers can provide. We should think of shifting the subsystem to CPLD.

##Pin Requirement
###Pin Requirement on Microcontroller
| Device            |  Pins Required  | Comments                        |
|!----------------- | ---------------!|!------------------------------- |
|Motor Control      |     30 (3 x 10) |                                 |
|Encoders	    |     20 (2 x 10) |                                 |
|Current Sense      |     10 (1 x 10) | ADC channels                    |
|Steering Pots      |      4 (1 x  4) | ADC channels                    |
|Rocker Bogie Pots  |      4 (1 x  4) | ADC channels                    |
|Communication      | 8  ( 2 + 4 + 2) | I2C + SPI + UART                |
|Control and Status |              2+ | Status LED and remote reset etc |
|Ultrasonic sensors |       6 (2 x 3) |                                 |

Total pins required   = 58+ digital pins (including 10 interrupts) and 18 ADC channels.
Available pins on Due = 54 digital pins and 12 ADC Channels

###Pin Requirement on CPLD
| Device            |  Pins Required  | Comments                                                                                     |
|!----------------- | ---------------!|!-------------------------------------------------------------------------------------------- |
|Motor Control      |     30 (3 x 10) |                                                                                              |
|Encoders	    |     20 (2 x 10) |                                                                                              |
|ADC                |      6 (3 +  3) | SPI based 8 + 8 + 4 channel ADCs                                                             |
|Current Sense      |              0  | Current sense pins from drive motors go to an 8 ch ADC, the pins from steering go to another |
|Steering Pots      |              0  | Pot values go to the steering 8 ch ADC                                                       |
|Rocker Bogie Pots  |              0  | Pot values go to th 4 ch ADC                                                                 |
|Communication      | 8  ( 2 + 4 + 2) | I2C + SPI + UART                                                                             |
|Control and Status |              2+ | Status LED and remote reset etc                                                              |
|Ultrasonic sensors |       6 (2 x 3) |                                                                                              |

Total pins required = 72+ digital pins (including 10 interrupts)
Available pins on Max V CPLD (5M1270Z) = 114 digital pins

###Pros
  Processing can be implemented on a single processor.
###Cons
  Requires ADCs as it doesn't have any analog channel.

##Processing
  Arduino Mega starts behaving erroneously with just 4 encoder interrupts at full resolution and i2c interrupts. I had to reduce the
encoder resolution by a factor of 2 to get things working. The full implementation will have 10 encoder interrupts, i2c interrupts/spi
interrupts some processing etc. Arduino Due might just be able to do it, but its always better to be away from max operating power.

  A CPLD has hardware parellelism and can do much more than what we are planning. CPLDs are inherently more reliable than microcontrollers.
It has a very flexible floating point unit as we have do design it and we also have readymade libraries available.
