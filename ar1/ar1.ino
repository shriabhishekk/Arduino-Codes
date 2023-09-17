const int trigpin = AO
const int echopin = A1
int dur=0;
int dis=0
void setup() {Serial.begin(9600);
pinMode(trigpin,OUTPUT)
pinMode(ecopin, INPUT)
  // put your setup code here, to run once:

}
loop() 
{ 
  delayMicroseconds(5);
  digital write (trigpin,LOW);
  delayMicroseconds(5);
  digital write (trigpin,HIGH);
  delayMicroseconds(10);
  digitalwrite(trigpin,LOW);
  dur= pulsein(echopin,HIGH);
  dist= dur/58;
  serial.print(dist);
  
  // put your main code here, to run repeatedly:

}
