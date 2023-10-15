#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int triggerpin= A0;
const int echopin= A1;
int dur=0;
int dist=0;




void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  


  pinMode(triggerpin,OUTPUT); // put your setup code here, to run once:
  pinMode(echopin,INPUT) ;


 

  // Invert and restore display, pausing in-between
  display.invertDisplay(true);
  delay(1000);
  display.invertDisplay(false);
  delay(1000);
  


}

void loop() {

  delayMicroseconds(5);// put your main code here, to run repeatedly:
  digitalWrite(triggerpin,LOW);
  delayMicroseconds(5);
  digitalWrite(triggerpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin,LOW);
  dur= pulseIn(echopin,HIGH);
  dist= dur/58;
 
  Serial.println(dist);
   
  testscrolltext(dist);    // Draw scrolling text
  delay(1000);
  if(distance<0);
  else 
}


void testscrolltext(int x) {
  
  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(25, 0);
  
  display.println(x);
  display.display();      // Show initial text
  delay(1000);
  
  

}
