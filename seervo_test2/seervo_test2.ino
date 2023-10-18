#include<Servo.h>
Servo Myservo;
int potPin = A0;
int servoPin = 13;
int val = 0;
int x = 0;
int oldval = 0;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(servoPin, OUTPUT);

Myservo.attach(13);
}


  
void loop() 
{ 
  for(val = 0; val < 180; val += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    Myservo.write(val);                 //command to rotate the servo to the specified angle
    delay(15);                       
  } 
 
  delay(1000);
  
  for(val = 180; val>=1; val-=5)     // command to move from 180 degrees to 0 degrees 
  {                                
    Myservo.write(val);              //command to rotate the servo to the specified angle
    delay(5);                       
  } 

    delay(1000);
}
