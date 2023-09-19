char bt_data=0;
const int pin1 = 13;
char  incomingdata= '0';
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
 pinMode(pin1, OUTPUT);
 

}

void loop() {
 
 digitalWrite(pin1,HIGH);
 delay(10000);
 digitalWrite(pin1,LOW);
 delay(10000);

}
