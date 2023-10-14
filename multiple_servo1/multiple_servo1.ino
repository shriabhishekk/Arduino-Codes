/*
Program: Flexible Control of the SG90 Micro Servo Motor Using Arduino
File: sg90_using_arduino_flex.ino
Description: Causes the servo motor to sweep back and forth
Author: Addison Sears-Collins
Website: https://automaticaddison.com
Date: June 20, 2020
*/
  
#include <Servo.h>
 
// Define the number of servos
#define SERVOS 1
 
// Create the servo object to control a servo.
Servo myservo[SERVOS];  
 
// Attach servo to digital pin on the Arduino
int servo_pins[SERVOS] = {9}; 
 
// Default angle for the servo in degrees
int default_pos[SERVOS] = {0}; 
 
void setup() {
   
  for(int i = 0; i < SERVOS; i++) {
     
    // Attach the servo to the servo object 
    myservo[i].attach(servo_pins[i]);
   
    // Make all the servos go to the default position
    myservo[i].write(default_pos[i]);
  }
   
  // Wait 15 milliseconds for the servo to get to the position
  delay(15);   
}
  
void loop() {
   
  // Go from 0 degrees to 180 degrees
  // Move in steps of 1 degree
  for (int angle = 0; angle <= 180; angle += 1) { 
 
    // Update the angle for all servos
    for(int i = 0; i < SERVOS; i++) {
   
      // Tell servo to go to the position in variable 'angle'
      // where 'angle' is in degrees
      myservo[i].write(angle);  
 
      // Wait 15 milliseconds for the servo to get to the position
      delay(15);    
    }                   
  }
 
  // Go from 180 degrees to 0 degrees
  // Move in steps of 1 degree   
  for (int angle = 180; angle >= 0; angle -= 1) { 
 
    // Update the angle for all servos
    for(int i = 0; i < SERVOS; i++) {
   
      // Tell servo to go to the position in variable 'angle'
      // where 'angle' is in degrees
      myservo[i].write(angle);  
 
      // Wait 15 milliseconds for the servo to get to the position
      delay(15);    
     }
  }
}      
