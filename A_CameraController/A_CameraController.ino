/*

This is a simple example that allows you to connect a tact switch, an LED and a rotary encoder to your Arduino.
The Arduino acts as a keyboard by outputting information as key presses.

You will need this table to figure the code for the characters you are trying to output.
http://www.asciitable.com/

You can use Keyboard.press() and modifier keys to use special keyboard keys
https://www.arduino.cc/reference/tr/language/functions/usb/keyboard/keyboardpress/
https://www.arduino.cc/reference/tr/language/functions/usb/keyboard/keyboardmodifiers/

*/

#include <Keyboard.h>      // include library that let's Arduino act as a keyboard
#include <RotaryEncoder.h> // include rotary encoder library

// Setup a RoraryEncoder for pins A0 and A1:
RotaryEncoder encoder(A0, A1);

// some useful values
#define OFF 0
#define ON 1

// start by assuming no buttons are pressed
bool keyX = OFF;


void setup()
{

  // connect to serial port for debugging
  Serial.begin(57600);

  // make pin 4 an input 
  pinMode(4, INPUT);

  pinMode(10, OUTPUT);    // sets the digital pin 10 as output
 

  // start the keyboard
  Keyboard.begin();
}

void loop()
{

  // Read the encoder and output its value
  /////////////////////////////////////////
  static int pos = 0;
  encoder.tick();

  int newPos = encoder.getPosition();
  if (pos != newPos)
  {
    Serial.print(newPos);
    Serial.println();

    if (newPos > pos)
    {
      Keyboard.write(69); // E
    }

    if (newPos < pos)
    {
      Keyboard.write(70); // F
    }

    pos = newPos;
  }

  // All the key presses happen here
  //////////////////////////////////////////////
  if ((digitalRead(4) == HIGH) && keyX == OFF)
  {
    keyX = ON;
    Keyboard.write(176); // ENTER key
    digitalWrite(10, HIGH);
   
  }
  if (digitalRead(4) == LOW)
  {
    keyX = OFF;
    digitalWrite(10, LOW);
  }

}
