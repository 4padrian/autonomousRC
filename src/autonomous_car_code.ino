/* ==== Autonomous 4*4 vehicle using the HC-SR04 ultrasonic sensor ===
 *  
 *  Components:
       *HC-SR04 Ultrasonic sensor Pins:
          VCC: +5VDC
          Trig : Trigger (INPUT)
          Echo: Echo (OUTPUT)
          GND: GND
       *L298N H Bridge Dual Motor Driver Pins:
          VMC: +5VDC
          5V: 5V (OUTPUT)
          GND: GND
          Motor A - IN1: INPUT
          Motor A - IN2: INPUT
          Motor A - ENABLE: PWM INPUT
          Motor B - IN3: INPUT
          Motor B - IN4: INPUT
          Motor B - ENABLE: PWM INPUT
       *Arduino Mega 2560
          54 Digital Pins: INPUT/OUTPUT
          16 Analog Pins: INPUT/OUTPUT
          12 PWM Pins
          4 Serial Communication Ports
          SPI Communication Pins
          I2C Communication Pins
          Built-In LED for Testing
       *LiPo Battery Ace 2S 7.4V 450mAh 30C
 */
 //LEFT SENSOR
 const int left_trig_pin = 22; //left sensor trig to pin 22
 const int left_echo_pin = 23; //left sensor echo to pin 23

//FRONT LEFT SENSOR
 const int front_left_trig_pin = 24; //front_left sensor trig to pin 24
 const int front_left_echo_pin = 25; //front_left sensor echo to pin 25

 //FRONT SENSOR
 const int front_trig_pin = 26; //front sensor trig to pin 26
 const int front_echo_pin = 27; //front sensor echo to pin 27

//FRONT RIGHT SENSOR
 const int front_right_trig_pin = 28; //front_right sensor trig to pin 28
 const int front_right_echo_pin = 29; //front_right sensor echo to pin 29

//RIGHT SENSOR
 const int right_trig_pin = 30; //right sensor trig pin to 30
 const int right_echo_pin = 31; //right sensor echo pin to 31

 //variables for sonar redings and setting speeds
 int left_distance;
 int front_left_distance;
 int front_distance;
 int front_right_distance;
 int right_distance;
 
//Thresholds for the different 'types' of sonar sensors - front, front side, and side (set in centimeters)
const int front_threshold = 50;    
const int front_sides_threshold = 45;
const int sides_threshold = 50;

 //LEFT SIDE DC MOTOR
 int left_motor_A_IN_1 = 33; //forward signal for motor_A
 int left_motor_A_IN_2 = 32; //reverse signal for motor_A
 int left_motor_A_EN_A = 2;  //pwm control for motor_A

 //RIGHT SIDE DC MOTOR
 int right_motor_B_IN_3 = 35; //forward signal for motor_B
 int right_motor_B_IN_4 = 34; //reverse signal for motor_B
 int right_motor_B_EN_B = 3; //pwm control for motor_B

 //variables for DC motors speed settings
 int left_motor_A_speed;
 int right_motor_B_speed;

void setup(){
  //configuring all sensor pins
  pinMode(left_trig_pin, OUTPUT);
  pinMode(left_echo_pin, INPUT);

  pinMode(front_left_trig_pin, OUTPUT);
  pinMode(front_left_echo_pin, INPUT);

  pinMode(front_trig_pin, OUTPUT);
  pinMode(front_echo_pin, INPUT);

  pinMode(front_right_trig_pin, OUTPUT);
  pinMode(front_right_echo_pin, INPUT);

  pinMode(right_trig_pin, OUTPUT);
  pinMode(right_trig_pin, INPUT);

  //configuring the motor driver pins
  pinMode(left_motor_A_IN_1, OUTPUT);
  pinMode(left_motor_A_IN_2, OUTPUT);
  pinMode(right_motor_B_IN_3, OUTPUT);
  pinMode(right_motor_B_IN_4, OUTPUT);

  digitalWrite(left_motor_A_IN_1, LOW);
  digitalWrite(left_motor_A_IN_2, LOW);
  digitalWrite(right_motor_B_IN_3, LOW);
  digitalWrite(right_motor_B_IN_4, LOW);
}

//function called to read left side of the car
void read_left_sensor(unsigned long left_duration){
  digitalWrite(left_trig_pin, LOW);
  delayMicroseconds(3);
  digitalWrite(left_trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(left_trig_pin, LOW);
  left_duration = pulseIn(left_echo_pin, HIGH, 40000);
  
  //Convert the time into a distance
  left_distance = (left_duration / 2) / 29.1; 
  //divide by 29.1 or multiply by 0.0343 to get the distance in centimeters
  return (left_distance);
}

//function called to read front left side of the car
void read_front_left_sensor(unsigned long front_left_duration){
  digitalWrite(front_left_trig_pin, LOW);
  delayMicroseconds(3);
  digitalWrite(front_left_trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(front_left_trig_pin, LOW);
  front_left_duration = pulseIn(front_left_echo_pin, HIGH, 87500);
  
  //Convert the time into a distance
  front_left_distance = (front_left_duration / 2) / 29.1;
  //divide by 29.1 or multiply by 0.0343 to get the distance in centimeters
  return (front_left_distance);
}

//function called to read in front of the car
void read_front_sensor(unsigned long front_duration){
  digitalWrite(front_trig_pin, LOW);
  delayMicroseconds(3);
  digitalWrite(front_trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(front_trig_pin, LOW);
  front_duration = pulseIn(front_echo_pin, HIGH, 100000);
  
  //Convert the time into a distance
  front_distance = (front_duration / 2) / 29.1; 
  //divide by 29.1 or multiply by 0.0343 to get the distance in centimeters
  return (front_distance);
}

//function called to read front right side of the car
void read_front_right_sensor(unsigned long front_right_duration){
  digitalWrite(front_right_trig_pin, LOW);
  delayMicroseconds(3);
  digitalWrite(front_right_trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(front_right_trig_pin, LOW);
  front_right_duration = pulseIn(front_right_echo_pin, HIGH, 87500);
  
  //Convert the time into a distance
  front_right_distance = (front_right_duration / 2) / 29.1; 
  //divide by 29.1 or multiply by 0.0343 to get the distance in centimeters
  return (front_right_distance);
}

//function called to read right side of the car
void read_right_sensor(unsigned long right_duration){
  digitalWrite(right_trig_pin, LOW);
  delayMicroseconds(3);
  digitalWrite(right_trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(right_trig_pin, LOW);
  right_duration = pulseIn(right_echo_pin, HIGH, 40000); 
    
  //Convert the time into a distance
  right_distance = (right_duration / 2) / 29.1;
  //divide by 29.1 or multiply by 0.0343 to get the distance in centimeters
  return (right_distance);
}

//function called to execute forward movement
void advance_move(){
   //IN_1 and IN_3 set to LOW, IN_2 and IN_4 set to HIGH to turn advance forward
  digitalWrite(left_motor_A_IN_1, LOW);
  digitalWrite(left_motor_A_IN_2, HIGH);
  analogWrite(left_motor_A_EN_A, 125);
  
  digitalWrite(right_motor_B_IN_3, LOW);
  digitalWrite(right_motor_B_IN_4, HIGH);
  analogWrite(right_motor_B_EN_B, 125);
}

void reverse_move(){
   //IN_1 and IN_3 set to HIGH, IN_2 and IN_4 set to LOW to reverse
  digitalWrite(left_motor_A_IN_1, HIGH);
  digitalWrite(left_motor_A_IN_2, LOW);
  analogWrite(left_motor_A_EN_A, 125);
  
  digitalWrite(right_motor_B_IN_3, HIGH);
  digitalWrite(right_motor_B_IN_4, LOW);
  analogWrite(right_motor_B_EN_B, 125);

  //active for three quarters of a second
  delay(750);
}

//function called to execute a short turn to the right to get away from an obstacle
void short_right_turn(){
  //IN_2 and IN_3 set to HIGH, IN_1 and IN_4 set to LOW to turn right
  digitalWrite(left_motor_A_IN_1, LOW);
  digitalWrite(left_motor_A_IN_2, HIGH);
  analogWrite(left_motor_A_EN_A, 220);
  
  digitalWrite(right_motor_B_IN_3, HIGH);
  digitalWrite(right_motor_B_IN_4, LOW);
  analogWrite(right_motor_B_EN_B, 220);

  //active for a quarter of a second
  delay(500);
}

//function called to execute a short turn to the left to get away from an obstacle
void short_left_turn(){
  //IN_2 and IN_3 set to LOW, IN_1 and IN_4 set to HIGH to turn right
  digitalWrite(left_motor_A_IN_1, HIGH);
  digitalWrite(left_motor_A_IN_2, LOW);
  analogWrite(left_motor_A_EN_A, 220);
  
  digitalWrite(right_motor_B_IN_3, LOW);
  digitalWrite(right_motor_B_IN_4, HIGH);
  analogWrite(right_motor_B_EN_B, 220);

  //active for a quarter of a second
  delay(500);
}

//function called to execute a right turn (approximately 45 degrees) when an obstacle is detected
void right_turn(){
  //IN_2 and IN_3 set to HIGH, IN_1 and IN_4 set to LOW to turn right
  digitalWrite(left_motor_A_IN_1, LOW);
  digitalWrite(left_motor_A_IN_2, HIGH);
  analogWrite(left_motor_A_EN_A, 220);
  
  digitalWrite(right_motor_B_IN_3, HIGH);
  digitalWrite(right_motor_B_IN_4, LOW);
  analogWrite(right_motor_B_EN_B, 220);

  //active for half of a second
  delay(750);
}

//function called to execute a left turn (approximately 45 degrees) turn when an obstacle is detected
void left_turn(){
  //IN_2 and IN_3 set to LOW, IN_1 and IN_4 set to HIGH to turn right
  digitalWrite(left_motor_A_IN_1, HIGH);
  digitalWrite(left_motor_A_IN_2, LOW);
  analogWrite(left_motor_A_EN_A, 220);
  
  digitalWrite(right_motor_B_IN_3, LOW);
  digitalWrite(right_motor_B_IN_4, HIGH);
  analogWrite(right_motor_B_EN_B, 220);

  //active for half of a second
  delay(750);
}

//function called to execute a long right (approximately 90 degrees) turn when an obstacle is detected 
void long_right_turn(){
  //IN_2 and IN_3 set to HIGH, IN_1 and IN_4 set to LOW to turn right
  digitalWrite(left_motor_A_IN_1, LOW);
  digitalWrite(left_motor_A_IN_2, HIGH);
  analogWrite(left_motor_A_EN_A, 220);
  
  digitalWrite(right_motor_B_IN_3, HIGH);
  digitalWrite(right_motor_B_IN_4, LOW);
  analogWrite(right_motor_B_EN_B, 220);

  //active for one of a second
  delay(1000);
}

//function called to execute a long left (approximately 90 degrees) turn when an obstacle is detected 
void long_left_turn(){
  //IN_2 and IN_3 set to LOW, IN_1 and IN_4 set to HIGH to turn right
  digitalWrite(left_motor_A_IN_1, HIGH);
  digitalWrite(left_motor_A_IN_2, LOW);
  analogWrite(left_motor_A_EN_A, 220);
  
  digitalWrite(right_motor_B_IN_3, LOW);
  digitalWrite(right_motor_B_IN_4, HIGH);
  analogWrite(right_motor_B_EN_B, 220);

  //active for one of a second
  delay(1000);
}

//function called to determine if any short of 45 degree turns are needed (minor corrections)
void sides_and_front_sides() {
  read_front_left_sensor(0);             
  delay(3);
  read_front_right_sensor(0);
  delay(3);
  read_left_sensor(0);
  delay(3);
  read_right_sensor(0);
  if (right_distance < left_distance && right_distance != 0 && left_distance != 0) {
    read_left_sensor(0);
    delay(3);
    read_right_sensor(0);
    if (right_distance < left_distance && right_distance != 0 && left_distance != 0) {
      short_left_turn();
    }
    else {
      advance_move();
    }
  }
  else if (left_distance < right_distance && left_distance != 0 && right_distance != 0) {
    read_left_sensor(0);
    delay(3);
    read_right_sensor(0);
    if (left_distance < right_distance && left_distance != 0 && right_distance != 0) {
      short_right_turn();
    }
    else {
      advance_move();
    }
  }
  else if (front_right_distance <= 4 && front_right_distance != 0) {
    right_turn();
    delay(2000);
    advance_move();
    delay(1000);
  }
  else if (front_right_distance < front_sides_threshold && front_right_distance != 0) {
    read_front_right_sensor(0);

    if (front_right_distance < front_sides_threshold && front_right_distance != 0) {
      read_front_right_sensor(0);

      if (front_right_distance < front_sides_threshold && front_right_distance != 0) {
        left_turn();
      }
      else {
        advance_move();
      }
    }
    else {
      advance_move();
    }
  }
  else if (front_left_distance <= 4 && front_left_distance != 0) {
    left_turn();
    delay(2000);
    advance_move();
    delay(1000);
  }
  else if (front_left_distance < front_sides_threshold && front_left_distance != 0) {
    read_front_left_sensor(0);
    if (front_left_distance < front_sides_threshold && front_left_distance != 0) {
      read_front_left_sensor(0);
      if (front_left_distance < front_sides_threshold && front_left_distance!= 0) {
        right_turn();
      }
      else {
           advance_move();
      }
    }
    else {
          advance_move();
    }
  }
}

void loop() {
  advance_move();
  digitalWrite(left_trig_pin, LOW);
  digitalWrite(front_left_trig_pin, LOW);
  digitalWrite(front_trig_pin, LOW);
  digitalWrite(front_right_trig_pin, LOW);
  digitalWrite(right_trig_pin, LOW);
  read_front_sensor(0);
  /*this delay is present before turning
   *has a negligible impact on reading performance, 
   *and has a similar structure like the sides_and_front_sides() function above*/
  delay(8);  
  if (front_distance > front_threshold && front_distance != 0) {
    read_front_sensor(0);
    delay(8);
    if (front_distance > front_threshold && front_distance != 0) {
      read_front_sensor(0);
      delay(8);
      if (front_distance > front_threshold && front_distance != 0) {
        read_front_sensor(0);
        delay(8);
        if (front_distance > front_threshold || front_distance == 0) {
           advance_move();
        }
        /*code for the passage of the quadruple check, indicating an obstacle - 
         *the car reads the two sides and decides which one has more room 
         *if one sensor returns an error (0), the car turns in 
         *that direction due to errors being returned for wide open spaces*/
        else {            
          read_right_sensor(0);   
          read_left_sensor(0);
          if (left_distance > right_distance && left_distance != 0) {
            long_left_turn();
          }
          else if (right_distance > left_distance && right_distance != 0) {
            long_right_turn();
          }
          else if (left_distance == 0) {
            long_left_turn();
          }
          else if (right_distance == 0) {
            long_right_turn();
          }
          read_front_sensor(0);  
          /*if the front sonar is too close to the wall (less than 5cm), 
           *the car will pause, then back up and carry on with normal function*/
          if (front_distance <= 5 && front_distance != 0) {
            reverse_move();
            delay(1000);
          }
        }
      }
      /*if the multiple checks for a wall in front fail at any 
       *point, the car reads the rest of the sensors for minor adjustments
       *it calls the sides_and_front_sides() function 
       *three times just to be sure the reading is correct*/
      else {
        sides_and_front_sides();   
      }
    }
    else {
      sides_and_front_sides();
    }
  }
  else {
    sides_and_front_sides();
  }
}