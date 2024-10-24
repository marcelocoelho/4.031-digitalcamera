# 4.031 Digital Camera Code Sample - 2024 Edition



## 1. Download Arduino IDE

Arduino is the microcontroller platform you will use to create your joystick. You can download the Arduino IDE here: https://www.arduino.cc/en/Main/Software which is where you will write your software, compile, and flash it into the Arduino. If you've never used an Arduino before, this page has all the info you need to get started: https://www.arduino.cc/en/Tutorial/HomePage

## 2. Program Arduino

We are using a clone of the Arduino Pro Micro (https://www.sparkfun.com/products/12640). Plug your Arduino into your computer and you should see some LEDs lighting up. If you don't, it could be because your Arduino is not properly connected to your computer or your computer might be having some driver issues recognizing the board.

Now let's make sure you can program your board.

First you need tell the Arduino IDE what port your board is connected to and make sure you've selected the right board.

Go to **Tools > Boards** and select **Arduino Micro**. 

Then select the port the Arduino is connected to.

Go to **Tools > Port** and then **/dev/cu.usbmodemHIDPC1 (Arduino Micro)**. <-- this is what it is called on my computer. Yours might be different.

Then run a simple example to make sure your Arduino programs correctly.

Go to **File > New Sketch**. This will open a blank sketch.

Click the Upload arrow. And you should get a **Done Uploading** message.

## 2.5 Reset

Because the keyboard functionality uses the serial port, which is also how we program the Arduino, you might get into a situation where the serial port is outputting numbers and doesn't let you reprogram the Arduino.

If this happens, connect a wire from the **RST (reset)** pin to ground. Then start upload and disconnect the reset wire. You might need to do this a few times to get the timing right.

**The Short Story: when using the Arduino as a keyboard, only have it output serial commands once the user does something like press a button. If you have it output all the time by default, you will get into this situation.**

## 3. Add an LED

Follow this example to add an LED. Make sure that you change pin numbers to reflect the pins you are connecting things to:
https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay/


## 4. Add a Button

Follow this example to add a button:

https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button

## 5. Add a Rotary Encoder

Use the example included wih the Github repo. This example also requires a library that you will need to install by going to Tools > Manage Libraries and search for rotaryencoder. Look for the library by Matthias Hertel.

CLK and DT are the pins on the rotary encoder that you need to connect to Arduino to detect rotation.

SW works like a regular button if you press down the rotary encoder. Code is not included in the example for the switch but it's similar to the button sketch above.

This video has a good explanation of how the encoder works if you are curious:
https://www.youtube.com/watch?v=v4BbSzJ-hz4&ab_channel=HowToMechatronics

## 6. Run A_CameraController

Now adapt your electronics to run the A_CameraController code provided. You will need an encoder, and LED and a button. But you can start with just a button and see if you can get it to control something in your computer similar to how your keyboard does. On the Mac you can use Photobooth to take photos.

## 7. Now design your own camera interface

Once you can control a camera using your Arduino, it's time to think about what the most appropriate camera interface for your project. Here are a few questions to help you think through the problem:

- What sensors should you use? How does the choice of sensor inform its behavior?
- Where should they be located? Are they close together or far apart? At the top, bottom or sides of the camera?
- Do you need one hand or both to control your camera?

