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

void loop() {
  // put your main code here, to run repeatedly:


int val = analogRead(A0);



Serial.println(val);
val = map(val, 0 , 1023, 0, 180);
Serial.println(val);


Serial.println("Old Value = :" + oldval);



        Serial.println("going 180 side");
        for( x = oldval;x <=val; x++){
        Myservo.write(x);
        delay(10);
        
        }

 
oldval = val;





delay(1000);

}
