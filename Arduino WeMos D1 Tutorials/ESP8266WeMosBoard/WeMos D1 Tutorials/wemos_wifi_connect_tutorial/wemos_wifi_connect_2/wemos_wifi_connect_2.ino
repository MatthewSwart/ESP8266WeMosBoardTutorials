/*
 * For this tutorial I am going to connect through the world
 * wide web to control the LED. You will need to sort out 
 * port forwarding on your router at home and I suggest you
 * do that once you have decide which port you want to use.
 * When it comes to port forwarding the one thing you will 
 * need to keep in mind is that rule of thumb the first 1000
 * ports are generally off limits as they are considered 
 * reserved and you could land up causing other issues with 
 * your network if you happened to land up choosing one of 
 * one of those reserved ports. You will also notice later 
 * on that I am recycling code from my previous tutorial so 
 * if something looks out of place please contact me so that
 * I can make the changes.
 */
#include <ESP8266WiFi.h>

const char* ssid = "Your ssid here";//Declare ssid and use your
//ssid name here for the router that is connect to the internet.
const char* pass = "Your wifi paasword here";//Declared pass.
//Enter your wifi password in here. 

WiFiServer server(2171); //Initializing a port between 1000-65535 

void setup() 
{
  Serial.begin(115200);//Start the serial monitor and set baud rate.
  delay(50);//I added a delay so that the serial monitor had time 
  //to start up.

  //Printing on the serial monitor.
  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);//Conneting to the wifi using the ssid &
  //pass that we declared earlier.

  //Check to make sure that the WeMos is connecting to the wifi.
  //for as long as it has not either completed or will no connect 
  //to the wifi it will run in the while loop.
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
