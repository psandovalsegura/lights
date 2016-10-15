/*
 Ethernet combinations
 Modified by Pedro Sandoval Segura
 10/7/16
 
 Allows you to turn on and off an LED by entering different urls.

 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Connect an LEDs to pins 4,5,6, and 7
 
 Based almost entirely upon Web Server by Tom Igoe and David Mellis
 Edit history: 
 created 18 Dec 2009
 by David A. Mellis
 modified 4 Sep 2010
 by Tom Igoe
 mofified Randy Sarafan
 */

#include <SPI.h>
#include <Ethernet.h>

boolean incoming = false;

//Keep track of which lights are on
boolean red = false;
boolean green = false;
boolean blue = false;
boolean yellow = false;

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 0x38, 0x6E, 0xE0, 0x38, 0xB3, 0x89 };
IPAddress ip(134,173,60,207); 

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);

void setup()
{
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.begin(9600);
  Serial.println("Started Serial");
}

void loop()
{
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    
    while (client.connected()) {
      if (client.available()) { //If there are bytes available client.available() returns the number bytes
        char c = client.read();

        Serial.println( c);
        
        //Check for prefix to incoming data
        if(c == '$'){ 
          incoming = true; 
        }
        
        //Checks for the URL string $1 or $2
        if(incoming == true){
          Serial.println(c);
          
          if(c == 'r'){
            toggleRed();
            break;
          }else if (c == 'g'){
            toggleGreen();
            break;
          } else if (c == 'b'){
            toggleBlue();
            break;
          } else if (c == 'y'){
            toggleYellow();
            break;
          }
        
        }
      }
    }

    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    //Serial.println("Disconnected from server.");
  }
}

void toggleRed() {
  Serial.println("Red");
  if (red) {
    digitalWrite(7, LOW);
    red = false;
  } else {
    digitalWrite(7, HIGH);
    red = true;
  }

  //Now that the process has been completed, there is "no more" data to read
  incoming = false;
}

void toggleGreen() {
  Serial.println("Green");
  if (green) {
    digitalWrite(6, LOW);
    green = false;
  } else {
    digitalWrite(6, HIGH);
    green = true;
  }

  incoming = false;
}

void toggleBlue() {
  Serial.println("Blue");
  if (blue) {
    digitalWrite(5, LOW);
    blue = false;
  } else {
    digitalWrite(5, HIGH);
    blue = true;
  }
  
  incoming = false;
}

void toggleYellow() {
  Serial.println("Yellow");
  if (yellow) {
    digitalWrite(4, LOW);
    yellow = false;
  } else {
    digitalWrite(4, HIGH);
    yellow = true;
  }

  incoming = false;
}


