const int pot = A0;
int value = 0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(pot,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

value = analogRead(pot) ;
Serial.println(value);
delay(200);

}
