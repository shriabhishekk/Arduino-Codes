#include "DHT.h"  // Including library for dht

#include <ESP8266WiFi.h>
 
String apiKey = "8ES547M8HUL7HIEE";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "J7Prime";     // replace with your wifi ssid and wpa2 key
const char *pass =  "harekrishna07";
const char* server = "api.thingspeak.com";

#define DHTPIN 0          //pin where the dht11 is connected
 
DHT dht;

WiFiClient client;
 
void setup() 
{
  dht.setup(16);
       Serial.begin(115200);
       delay(10);
      
 
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
}
 
void loop() 
{

   float h = dht.getHumidity();/* Get humidity value */
  float t = dht.getTemperature();/* Get temperature value */
   //   float h = dht.readHumidity();
    //  float t = dht.readTemperature();

      h=40.0;
              if (isnan(h) || isnan(t)) 
                 {
                     Serial.println("Failed to read from DHT sensor!");
                      return;
                 }

                         if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(t);
                             postStr +="&field2=";
                             postStr += String(h);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Temperature: ");
                             Serial.print(t);
                             Serial.print(" degrees Celcius, Humidity: ");
                             Serial.print(h);
                             Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
  delay(10000);
}

// end of code
