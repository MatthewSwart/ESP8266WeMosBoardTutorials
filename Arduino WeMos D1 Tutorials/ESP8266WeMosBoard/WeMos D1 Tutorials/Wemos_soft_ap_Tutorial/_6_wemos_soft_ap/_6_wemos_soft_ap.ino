/*
 * Ok this step will be to setup an LED on GPIO 16 then handle 
 * the code so that we can turn the LED on and off via the 
 * web browser.
 */
#include <ESP8266WiFi.h>

WiFiServer server(80); //Initializing the AP access port 

int LED = 16;//Declare the LED to 16 used in the setup loop.

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

  pinMode (LED, OUTPUT);//We declared this earlier on in the 
  //could and set it to GPIO 16.
  digitalWrite (LED, HIGH);//Set the initial state to off.
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
    //serial monitor. I have deleted the Serial.println
    //that was after this code.

    //Handling the request for the browser.
    if (request.indexOf("/OFF") != -1)
    {
      digitalWrite(LED, HIGH);
    }
    else if (request.indexOf("/ON") != -1)
    {
      digitalWrite(LED, LOW);
    }//Ok what this boils down to is if you connect the SSID
    //WeMosD1 and open browser and goto 192.168.4.1/ON or
    //192.168.4.1/OFF the browser sends the request to your
    //WeMos board and either switches the LED ON or OFF.
    //Keep in mind that you will need to type the word ON and 
    //OFF in CAPTALS or the request won't work.

    //Getting the HTML ready for use and adding buttons
    String buttons = "HTTP/1.1 200 OK\r\n";
    buttons += "Content-Type: text/html\r\n\r\n";
    buttons += "<!DOCTYPE HTML>\r\n<html>\r\n";
    buttons += "<br><input type=\"button\" name=\"b1\" value=\"LED ON\" onclick=\"location.href=\'/ON'\"";
    buttons += "<br><br><br>";
    buttons += "<br><input type=\"button\" name=\"b1\" value=\"LED OFF\" onclick=\"location.href=\'/OFF'\"";
    buttons += "</html>\n";

    //Hands the code over to the browser and refreshes
    //the browser ever time you click on a button.
    client.flush();//Refreshes the browser in stream.
    client.print(buttons);//Sends the responce over to the client.
    delay(5);
    Serial.println("Client disconnected");
}
