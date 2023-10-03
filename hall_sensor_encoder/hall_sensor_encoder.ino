
int hallSensorpin=2;
int ledpin=13;
int state=0;

void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);
pinMode(hallSensorpin,INPUT);
Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  
state=digitalRead(hallSensorpin);
Serial.println(state);
if (state == LOW){
  digitalWrite(ledpin,LOW);
  
}
else{
  digitalWrite(ledpin,HIGH);
  
}
}
