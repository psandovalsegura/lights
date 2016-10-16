/*
 Ethernet combinations
 Modified by Pedro Sandoval Segura
 10/7/16
 
 Allows you to turn on and off an LED by entering different urls.

 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Connect an LEDs to pins 5,6,7, and 8
 
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

boolean incomingRequest = false;
boolean incomingTone = false;

//Keep track of which lights are on
boolean red = false;
boolean green = false;
boolean blue = false;
boolean yellow = false;

const int buzzerPin = 9;
const int toneDuration = 100;

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 0x28, 0x22, 0xD0, 0xEC, 0xC6, 0x5D };
IPAddress ip(134,173,60,203); 

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

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

        Serial.println(c);
        
        //Check for prefix to incoming request for lights, 
        if(c == '$'){ 
          incomingRequest = true; 
        }
        
        //Checks for the URL string $1 or $2
        if(incomingRequest == true){
          
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

        //Check for prefix to incoming tones
        if(c== '&') {
          incomingTone = true;
        }

        if (incomingTone == true) {
          if(c != '&') {
            tone(buzzerPin, frequency(c), toneDuration);
            delay(toneDuration);
            incomingTone = false;
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
    digitalWrite(8, LOW);
    red = false;
  } else {
    digitalWrite(8, HIGH);
    red = true;
  }

  //Now that the process has been completed, there is "no more" data to read
  incomingRequest = false;
}

void toggleGreen() {
  Serial.println("Green");
  if (green) {
    digitalWrite(7, LOW);
    green = false;
  } else {
    digitalWrite(7, HIGH);
    green = true;
  }

  incomingRequest = false;
}

void toggleBlue() {
  Serial.println("Blue");
  if (blue) {
    digitalWrite(6, LOW);
    blue = false;
  } else {
    digitalWrite(6, HIGH);
    blue = true;
  }
  
  incomingRequest = false;
}

void toggleYellow() {
  Serial.println("Yellow");
  if (yellow) {
    digitalWrite(5, LOW);
    yellow = false;
  } else {
    digitalWrite(5, HIGH);
    yellow = true;
  }

  incomingRequest = false;
}

int frequency(char note) 
{
  // This function takes a note character (a-g), and returns the
  // corresponding frequency in Hz for the tone() function.

  int i;
  const int numNotes = 8;  // number of notes we're storing

  // The following arrays hold the note characters and their
  // corresponding frequencies. The last "C" note is uppercase
  // to separate it from the first lowercase "c". If you want to
  // add more notes, you'll need to use unique characters.

  // For the "char" (character) type, we put single characters
  // in single quotes.

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  // Now we'll search through the letters in the array, and if
  // we find it, we'll return the frequency for that note.

  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);  // We looked through everything and didn't find it,
              // but we still need to return a value, so return 0.
}


