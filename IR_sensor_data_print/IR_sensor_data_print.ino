int IR_analogPin = A0;

int buzzer = 5;
void setup(){
 // pinMode(IR_analogPin, INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop(){

  int sensordata=analogRead (IR_analogPin);
  
  if( sensordata > 100){

   tone(buzzer,5000,500);
      
  }

   Serial.print("Sensor Reading\n");
  
   Serial.println(sensordata);
   delay(200);
}
