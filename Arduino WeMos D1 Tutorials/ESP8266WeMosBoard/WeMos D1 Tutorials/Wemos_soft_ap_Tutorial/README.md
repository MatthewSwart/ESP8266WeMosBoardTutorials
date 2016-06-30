# ESP8266WeMosBoard

# Tutorial done by Matthew Swart

Set of step by step how to's that are comment heavy and hopefully easy to follow. 
This was done for a friend but hopefully it will help a beginner understand that steps need to set-up and run the WeMos D1 board.

1) Deals with the initail set-up code needed to get server up and running. 

2) Deals with getting feed back from the server in the form of an IP address.

3) Deals with connecting to the client with a web browser and getting feedback to the serial monitor. 
     You will need to connect the WeMosD1 SSID then open a browser and go to 192.168.4.1 address. 
     You should get an error message from the browser as at this point you have no HTML code added 
     to the project and the browser can't show what it does not have, however if you look at the serial 
     monitor you should get a number of "Somebody has connected o.O" messages. If you are getting 
     error message at this point you will need to go through your code and find out what you are missing.
     If need be copy and paste the code I have available as sometimes it is hard to notice where you are
     missing a semicolon or your indent is wrong or you are missing a bracket or you have spelt something
     wrong.

4) Gets information back from your browser, this information will contain type of browser version
     number etc. Again when you goto the 192.168.4.1 address your browser should give you an error
     message as there is still no HTML code in your program so don't stress.

5) Adding LED to the code and then adding a way to switch it on and off. Please note that when you 
     are turning the LED on and off via the browser you need to ensure that type the word ON and OFF
     in CAPITALS.

6) Last section is to add some buttons on the browser page so that you can switch the led on and off 
     there without the need to type it into the address bar each time. 