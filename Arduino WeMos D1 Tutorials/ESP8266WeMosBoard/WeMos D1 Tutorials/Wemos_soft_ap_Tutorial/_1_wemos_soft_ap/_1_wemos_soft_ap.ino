/*
 * Ok John lets start small the following program is to make 
 * your WeMos an access point. This is pretty much like your
 * router at home. Once you have this loaded into your WeMos
 * you should be able to connect to it via the wifi on your 
 * computer. Disconnect from your home router and find the SSID
 * in your access list. In This case it should say WeMosD1, click
 * to access that and type in the password test1234.
 */
#include <ESP8266WiFi.h>

WiFiServer server(80); //Initializing the AP access port 

void setup() 
{
  WiFi.mode(WIFI_AP); //This is making the WeMos an actuall 
  //Access Point sort of a mini router so that 
  //you can coonect to as you would your home wifi.

  WiFi.softAP("WeMosD1", "test1234"); //SSID you should be looking 
  //for on you wifi access list and the password (no shorter then 
  //8 charaters long

  server.begin(); //Starts the HTTP server you just set up.
  //The default IP address for the soft access point is set 
  //to 192.168.4.1
}

void loop() {
  // put your main code here, to run repeatedly:

}
