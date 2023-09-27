
int ledpin = A0;
int pin=



void setup() {
  // put your setup code here, to run once:

serial.begin(9600);

pinmode(ledpin,OUTPUT);



}

void loop() {
  // put your main code here, to run repeatedly:

delay (500);

digitalWrite(trigpin,LOW);

delay(500);

digitalWrite(trigpin,HIGH); 


}
