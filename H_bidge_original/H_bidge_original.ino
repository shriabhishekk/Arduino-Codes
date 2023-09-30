#define enb1 6
#define left1 7
#define left2 8
#define right1 9
#define right2 10
#define enb2 11

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(enb1,OUTPUT);
pinMode(left1,OUTPUT);
pinMode(left2,OUTPUT);
pinMode(right1,OUTPUT);
pinMode(right2,OUTPUT);
pinMode(enb2,OUTPUT);

digitalWrite(left1,HIGH);
digitalWrite(left2,HIGH);
digitalWrite(right1,HIGH);
digitalWrite(right2,HIGH);
analogWrite(enb1,255);
analogWrite(enb2,255);

}

void loop() {
  // put your main code here, to run repeatedly:
front();
delay(10000);
stp();
delay(5000);
back();
delay(10000);
}

 //function for left turn
void leftturn(){
    
  
}


//function for 
void rightturn(){
  
}
void front(){

   digitalWrite(left1,HIGH);
   digitalWrite(left2,LOW);
   digitalWrite(right1,HIGH);
   digitalWrite(right2,LOW);
}

void back(){
  
   digitalWrite(left1,LOW);
   digitalWrite(left2,HIGH);
   digitalWrite(right1,LOW);
   digitalWrite(right2,HIGH);

}

void stp(){
   digitalWrite(left1,HIGH);
   digitalWrite(left2,HIGH);
   digitalWrite(right1,HIGH);
   digitalWrite(right2,HIGH);
   
}
