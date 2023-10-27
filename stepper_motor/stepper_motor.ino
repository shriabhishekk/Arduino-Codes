#include <Stepper.h>
const int stepPerRevolution =512;// change this to fit the number of revolution
Stepper myStepper1(stepPerRevolution,7,9,8,10);//1-3-2-4
​
void setup() {
  // put your setup code here, to run once:
myStepper1.setSpeed(90);
}
​
void loop() {
  // put your main code here, to run repeatedly:
forward();
delay(1000);
backward();
delay(1000);   
}
​
​
void forward()
{
  for(int i=1;i<2560;i++){
  myStepper1.step(-1);
 
  }
  
 
}
void backward()
{
   for(int i=1;i<2560;i++){
  myStepper1.step(1);
  
  }
}
