/*
 *This part of the tutorial we going to set-up the LED that we are
 *using to show the application is working over the internet. For
 *this example I am using the tradition pin 13 LED which is on the 
 *on the board for the WeMos this is called the BUILTIN_LED. First 
 *under the ssid and pass declaration I declare and name the 
 *BUILTIN_LED to make it a little easier. Then in the setup loop  
 *I set the digital pin and make sure that the LED is set to off 
 *at the beginning. Once that is done I start the server and 
 *print that out on the serial monitor. Then I setup a printed
 *statement so that the user can see the IP address allocated 
 *to the WeMos board.
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

void loop() {
  // put your main code here, to run repeatedly:

}
