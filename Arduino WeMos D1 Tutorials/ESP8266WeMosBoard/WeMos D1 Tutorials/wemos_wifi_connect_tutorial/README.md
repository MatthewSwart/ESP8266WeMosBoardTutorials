# ESP8266WeMosBoard WiFi internet connection 

#Tutorial by Matthew Swart

1) Setting up the wifi for connection to your router and activating the required port. You should chose a port between          1000-65535 as those under 1000 by rule of thumb could be reservered. A safe bet is to use port 8080. You will need to        setup portforwarding but can only check if the port is available once the board is connected to the wiFi.

2) Setup the LED. You can build a circuit on a breadboard but I decided to use the LED on the board, on an arduino board that    is generally pin 13 but on the WeMos it is called BUILTIN_LED. We declare it and name it something a little simpler for      later. In the void loop we set the digital pin and make sure the LED is set to OFF or in coding terms HIGH. We then start    the the server and print that out in the serial monitor along with the WeMos IP address for the record.

3) Seeing as I covered the thrird part of this tutorial in a previous one I dumped the code to turn the LED on and off plus     the plus the HTML code for the buttons on the webpage into the void loop. I also talk about some of the issues I encounted    while working on this tutorial in the hope that it may help and show you are not the only one that come across issues.
