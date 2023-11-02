 char bt_data=0;
const int pin1 = 13;
char  incomingdata= '0';

int trigPin = A0;      // trig pin of HC-SR04
int echoPin = A1;

int revleft4 = 4;       //REVerse motion of Left motor
int fwdleft5 = 5;       //ForWarD motion of Left motor
int revright6 = 6;      //REVerse motion of Right motor
int fwdright7 = 7;      //ForWarD motion of Right motor

int enA = 9;
int enB = 10;

long duration, distance;

void setup() {
  pinMode(pin1, OUTPUT);
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(revleft4, OUTPUT);      // set Motor pins as output
  pinMode(fwdleft5, OUTPUT);
  pinMode(revright6, OUTPUT);
  pinMode(fwdright7, OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enA,OUTPUT);
  
  /*pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT); */         //set echo pin as input to capture reflected waves


}

void loop() {

  if(Serial.available()>0)
  {
    bt_data=Serial.read();
  
    Serial.print(bt_data);
    Serial.print("\n");

   if(bt_data=='1'){

    moveforward();
    ultrasonic();
    delay(50);
    Serial.println(distance);
    if (distance < 10);{
      halt();
    }
   }
   
  
  else if(bt_data =='2'){
   movebackward();
  }
  else if(bt_data =='3'){
    turningtoright();
  }
  else if(bt_data =='4'){
    turningtoleft();
  }
  else if(bt_data =='0'){
    halt();
  }
 
  } 

  

  

}

void moveforward(){
     analogWrite(enA, 200);
  analogWrite(enB,200);
  digitalWrite(fwdright7, HIGH);                    // move forward
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, HIGH);                                
    digitalWrite(revleft4, LOW); 
    delay(500);   
}


void halt() {
  digitalWrite(fwdright7, LOW);               //Stop                
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);
    delay(500);
}

void movebackward(){
    analogWrite(enA, 200);
  analogWrite(enB,200);
  digitalWrite(fwdright7, LOW);              //movebackword         
    digitalWrite(revright6, HIGH);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, HIGH);
    delay(500);
}

 void turningtoright(){
    analogWrite(enA, 70);
  analogWrite(enB,70);
    digitalWrite(fwdright7, HIGH);       
    digitalWrite(revright6, LOW);         // turning to right
    digitalWrite(fwdleft5, LOW);                                 
    digitalWrite(revleft4, HIGH);  
    delay(500);
  }

 void turningtoleft(){
    analogWrite(enA, 70);
  analogWrite(enB,70);
   digitalWrite(fwdright7, LOW);       
    digitalWrite(revright6, HIGH);         // turning to left
    digitalWrite(fwdleft5, HIGH);                                 
    digitalWrite(revleft4, LOW);  
    delay(500);
 }

 void ultrasonic(){
  delayMicroseconds(5);// put your main code here, to run repeatedly:
 digitalWrite(trigPin,LOW);
 delayMicroseconds(5);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
 duration= pulseIn(echoPin,HIGH);
 distance= duration/58;

 }
//end of code
