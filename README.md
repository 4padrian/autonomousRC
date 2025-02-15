# Autonomous 4 x 4 vehicle using HC-SR04 ultrasonic sensors

Code, equipment and steps to create an autonomous RC car with HC-SR04 sensors and Arduino

List of components:

**HC-SR04 Ultrasonic sensor Pins:**  
VCC: +5VDC  
Trig : Trigger (INPUT)  
Echo: Echo (OUTPUT)  
GND: GND  

**L298N H Bridge Dual Motor Driver Pins:**  
VMC: +5VDC  
5V: 5V (OUTPUT)  
GND: GND  
Motor A - IN1: INPUT  
Motor A - IN2: INPUT  
Motor A - ENABLE: PWM INPUT  
Motor B - IN3: INPUT  
Motor B - IN4: INPUT  
Motor B - ENABLE: PWM INPUT  

**Arduino Mega 2560**  
54 Digital Pins: INPUT/OUTPUT  
16 Analog Pins: INPUT/OUTPUT  
12 PWM Pins
4 Serial Communication Ports  
SPI Communication Pins  
I2C Communication Pins  
Built-In LED for Testing  

**LiPo Battery Ace 2S 7.4V 450mAh 30C**  

Project Diagram  
![Project_Diagram](https://github.com/4padrian/autonomousRC/blob/main/project_images/project_diagram.jpg | width=600)

RC Assembled  
![RC_Assembled](https://github.com/4padrian/autonomousRC/blob/main/project_images/assembly-9.jpg|width=600)

More images and details can be found in **/project_images** folder.

**Project description and details:**

The platform on which we will mount all the electronic components is a non-functional Tyco Mutator 9.6V Turbo from 1996. I managed to salvage its two DC motors. This remote-controlled car was also featured in the 1997 movie Home Alone 3.  
![tyco_mutator](https://github.com/4padrian/autonomousRC/blob/main/project_images/tyco_mutator.JPG|width=600)

**Accessing the DC Motors**  
The first step was to access the DC motors inside the car by removing all unnecessary components that won’t be used in this project. These include the car body, rear wing, antenna, and front bumper.  The rotating gears are connected to each other on both sides of the car chassis. The DC motor's gear connects with these gears, driving both wheels on that side of the car. The same mechanism applies to the other side, where the second motor is installed.  
![assembly-2](https://github.com/4padrian/autonomousRC/blob/main/project_images/assembly-2.jpg|width=600)

**DC Motors Installation**  
The two DC motors (6–8V) come with plastic casings that help secure them inside the car, ensuring proper connection to the gear system. Each channel transmits power to both wheels on the left or right side of the car when the respective motor is running.  
![electric-motors](https://github.com/4padrian/autonomousRC/blob/main/project_images/electric-motors.jpg|width=600)

**Preparing for Electronic Components**  
The plastic cover has been mounted over the motors, and the wires connected to them have been routed through the rear side of the chassis. This surface will be used to mount all the electronic components listed earlier.  
![assembly-3](https://github.com/4padrian/autonomousRC/blob/main/project_images/assembly-3.jpg|width=600)

The first components to be installed are the HC-SR04 ultrasonic sensors. This project uses a total of five ultrasonic sensors.

**Installing the Components**  
Below, you can see that almost all electronic components have been installed. The ultrasonic sensors have been positioned as follows:  
- One on each side of the car
- Three in the front  
  ![assembly-7](https://github.com/4padrian/autonomousRC/blob/main/project_images/assembly-7.jpg|width=600)

**Dupont connector cables were used to interconnect all components:**  
- The HC-SR04 ultrasonic sensors were connected to the Arduino Mega 2560 for signal transmission and reception. For power, they were linked to the power rails on the Breadboard.  
- The L298N dual H-bridge motor driver was connected to the Arduino Mega 2560 to receive the signals that control the two DC motors (PWM and direction signals).  
- The LiPo 7.4V battery was connected to the L298N motor driver, which in turn was linked to the Breadboard to power the entire circuit using the 5V output pin and GND from the motor driver.