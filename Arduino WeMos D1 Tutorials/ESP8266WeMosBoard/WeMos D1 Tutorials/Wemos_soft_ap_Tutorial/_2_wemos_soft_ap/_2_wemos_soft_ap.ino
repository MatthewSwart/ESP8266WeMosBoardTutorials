/*
 * Ok John moving on we need to get some information feed back
 * from the softAP we built in the previous sketch, what we are
 * looking for is the system to confirm that default ip address 
 * we spoke about in the server.begin code.
 */
#include <ESP8266WiFi.h>

WiFiServer server(80); //Initializing the AP access port 

void setup() 
{
  WiFi.mode(WIFI_AP); //This is making the WeMos an actuall 
  //Access Point sort of a mini router so that 
  //you can coonect to as you would your home wifi.

  WiFi.softAP("WeMosD1", "test1234"); //SSID you should be lookinprevig 
  //for on you wifi access list and the password (no shorter then 
  //8 charaters long

  server.begin(); //Starts the HTTP server you just set up.
  //The default IP address for the soft access point is set 
  //to 192.168.4.1

  Serial.begin(115200); //Start communicating between the WeMos
  //board and the serial monitor window. The little magnify glass
  //looking icon on the top right of the page.

  IPAddress HTTPS_ServerIP = WiFi.softAPIP(); //This is getting 
  //the IP from the server and adding it to a declared variable
  //called HTTPS_ServerIP which you will access below. 
  //The bulk of the code that is needed
  //to do this is in the ESP8266WiFi.h library so if you 
  //require information you will need to search the library 
  //documentation at https://github.com/ekstrand/ESP8266wifi

  Serial.print("Server IP is: ");
  Serial.println(HTTPS_ServerIP); //This just simply prints
  //that IP address that you acquired earlier in the serial
  //monitor window.
}

void loop() {
  // put your main code here, to run repeatedly:

}
