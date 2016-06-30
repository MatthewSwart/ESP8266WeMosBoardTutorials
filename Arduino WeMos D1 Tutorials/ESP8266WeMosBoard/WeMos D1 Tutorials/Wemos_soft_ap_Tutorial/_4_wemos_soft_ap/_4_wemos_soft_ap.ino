/*
 * Ok this step will be to check what the browser is sending 
 * to server. Everytime you connect to a webserver your browser 
 * sends info so that web server knows what information is 
 * relavent to the browser. To a degree this is why the same
 * webpage can look different in different browsers. That is
 * not the complete picture but then this ain't a HTML/CSS 
 * tutorial.
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

void loop() 
{
  /*Next step is to check if someone has connected to the 
   * server/client. Once someone has connected the serial 
   * monitor will give feed back.
   */
  WiFiClient client = server.available(); //Declaring the client
  //vairable for use later in the code.
    
    if (!client)
    {
      return;
    }//Simple loop to check over and over again if someone has 
    //connected to the client browser and if so then the code
    //will step out of the loop and give you feedback in the 
    //serial monitor.

    Serial.println("Somebody has connected o.O");//To get this
    //feedback on your serial monitor you will need to connect 
    //to the WeMosD1 SSID and then load a webpage and enter 
    //192.168.4.1 for now you have no HTML code so your browser 
    //should give you an error message but on the serial monitor 
    //you should get if not one but three Somebody has connected
    //o.O messages.

    String request = client.readString();//This reads what the 
    //browser sends into a String class and prints it out in the
    //serial monitor.

    Serial.println(request);//Prints the information out on the 
    //serial monitor.
}
