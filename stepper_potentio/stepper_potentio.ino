
#include <Stepper.h>
const int stepPerRevolution =512;// change this to fit the number of revolution
Stepper myStepper1(stepPerRevolution,7,9,8,10);//1-3-2-4
int potPin = A0;
int val = 0;
int oldval = 0;
int diff= 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myStepper1.setSpeed(90);
}

void loop() {
  // put your main code here, to run repeatedly:

int val = analogRead(A0);
Serial.println( val);

diff=oldval-val;
if (diff>0) {
  forward(diff);

  
  
  }
  else{
    backward(diff);
    
    }
oldval=val;

delay(100);



}

void forward(int x)

{

  
  for(int i=1;i<x;i++) {     
    
  myStepper1.step(-1);
 
  }
  
 
  }

void backward(int x)  {
   for(int i=1;i<x;i++){
  myStepper1.step(1);
  
  }
}
