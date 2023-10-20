int potPin = A0;
int servoPin = 13;
int val = 0;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(servoPin, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:


int val = analogRead(A0);
//Serial.println(val);
val = map(val, 880 , 1023, 0, 180);
Serial.println(val);

delay(100);



}
