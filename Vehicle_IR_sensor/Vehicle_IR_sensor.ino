int IRLeft = 2;// connect ir sensor to arduino pin 2
int IRRight = 3;//
/*int LED = 13; // conect Led to arduino pin 13*/

int revleft4 = 4;       //REVerse motion of Left motor
int fwdleft5 = 5;       //ForWarD motion of Left motor
int revright6 = 6;      //REVerse motion of Right motor
int fwdright7 = 7;      //ForWarD motion of Right motor

int enA = 9;
int enB = 10;

long duration, distance;

void setup() 
{

Serial.begin(9600);

  pinMode(revleft4, OUTPUT);      // set Motor pins as output
  pinMode(fwdleft5, OUTPUT);
  pinMode(revright6, OUTPUT);
  pinMode(fwdright7, OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enA,OUTPUT); 

  pinMode (IRLeft, INPUT); // sensor pin INPUT
  pinMode (IRRight, INPUT); // sensor pin INPUT
  
}

void loop()
{
  int leftstatus = digitalRead (IRLeft);
  int rightstatus = digitalRead (IRRight);
 
  if (leftstatus== 1){
    turningtoleft();
     Serial.println(LOW);
     
  }
  else
  { moveforward();
   Serial.println(HIGH);
  }
  if (rightstatus==0){
    turningtoright();
 
  }
  
 else
 { moveforward(); 
  
   
 
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
