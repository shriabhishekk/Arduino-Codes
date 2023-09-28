char bt_data=0;
const int pin1 = 13;
char  incomingdata= '0';

bool flag = true;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
 pinMode(pin1, OUTPUT);
 

}

void loop() {
 
  if(Serial.available()>0)
  {
    bt_data=Serial.read();
    incomingdata=bt_data;
    Serial.print(bt_data);
     if(incomingdata=='1'){ 
  
   flag = false;
   
 
 }
 else if(incomingdata=='0' ){
  
  flag = true;
  
}
   
  }
  // put your main code here, to run repeatedly:

  

   if (flag == false){

    digitalWrite(pin1,HIGH);
    Serial.println("bulb is on");
   }else{
    digitalWrite(pin1,LOW);
    Serial.println("bulb is off");
   }

   delay(2000);
}
  
 
