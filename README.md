# LED-morse-code

__Brief Description__  
This project uses an Arduino to translate english to morse code. You input words into the Serial Monitor, then it outputs the morse code equivalent and makes the LED blink.  
If you are going to use this please set the Serial Monitor's baud rate to 9600 and have your jumper wire connected to pin13/change the code to your matching pin.

__Hardware__
![Image](https://github.com/user-attachments/assets/de846c25-d8ce-40dc-9136-383f53eece14)
<img width="1482" height="692" alt="Image" src="https://github.com/user-attachments/assets/cd2c3806-2af7-4068-9006-2583d6b2bc9c" />
*Tinkercad for clarity*  
Using an Arduino Uno R3, a 220ohm Resistor, an LED, a breadboard, and a few jumper wires

__Software__  
<img width="1462" height="442" alt="Image" src="https://github.com/user-attachments/assets/5cc48164-66d4-4419-a6c1-27caa8142797" />
Written in VS Code with the PlatformIO IDE extension  
Code is C++ with the Arduino Library  
Type your sentence into the Serial Monitor and it will output the morse code and LED will blink
