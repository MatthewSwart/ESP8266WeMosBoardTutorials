/*
 *Since I have covered the last part of this tutorial in the 
 *previous one I have done a bulk amount of code. Keep in mind 
 *the code looks a little different but does the same job.
 *Lets hit the issues I have found while doing this tutorial.
 *It took a good bit of work to set the port forwarding up 
 *and will admit that after a lot of fustration figured out
 *that the board needs to running and connected to the wifi 
 *before you go online to check if the port is open. You can 
 *use http://ping.eu/port-chk/ to find out if your required 
 *port is available. Second issue I came across is that 
 *sometimes my board disconnects from the net by itself. I 
 *have seen that other people have come across this issue 
 *and I am still trying to get a clear answer as to why it 
 *does. Happy coding any issues please open a tcket on GITHUB
 *and I will get back to you with in a 3 day window.
 */
#include <ESP8266WiFi.h>

const char* ssid = "Your ssid here";//Declare ssid and use your
//ssid name here for the router that is connect to the internet.
const char* pass = "Your wifi paasword here";//Declared pass.
//Enter your wifi password in here. 

int ledPin = BUILTIN_LED;//Declare the GPIO for the LED. In this
//case I am using the LED on the board to save me the hassle of
//making up a circuit on a breadboard since I am sure you already
//know how to do that.

WiFiServer server(8080); //Initializing a port between 1000-65535 

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

  //Set the digital pin and then set the LED to off.
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() 
{
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) 
  {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available())
  {
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) 
  {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1)
  {
    digitalWrite(ledPin, LOW);
    value = LOW;
  }
 
 
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led pin is now: ");
 
  if(value == HIGH) 
  {
    client.print("On");  
  } 
  else 
  {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("Click <a href=\"/LED=ON\">here</a> turn the LED on pin 5 ON<br>");
  client.println("Click <a href=\"/LED=OFF\">here</a> turn the LED on pin 5 OFF<br>");
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}
