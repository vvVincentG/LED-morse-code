#include <Arduino.h>

#define pin13 13

//Array for each letter's morse code
String alphabet[]
{
  ".-",//A
  "-...",//B
  "-.-.",//C
  "-..",//D
  ".",//E
  "..-.",//F
  "--.",//G
  "....",//H
  "..",//I
  ".---",//J
  "-.-",//K
  ".-..",//L
  "--",//M
  "-.",//N
  "---",//O
  ".--.",//P
  "--.-",//Q
  ".-.",//R
  "...",//S
  "-",//T
  "..-",//U
  "...-",//V
  ".--",//W
  "-..-",//X
  "-.--",//Y
  "--..",//Z
};

// initiate function here:
void dot();
void dash();
void letterGap();
void wordGap();
void translateMorse(String sentence); 

// board code:
void setup() 
{
  // put your setup code here, to run once:
  pinMode(pin13, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //Serial.begin(9600); //debugging (is it one or 2 g?)
  translateMorse("hi sos"); //STRING CANNOT HAVE ANY CHARACTERS ONLY LETTERS AND SPACE or else everything breaks :sob:

}

// define function here:
void dot()
{
  digitalWrite(pin13, HIGH);
  delay(250); //I'm letting 250ms be the 1 timing
  digitalWrite(pin13, LOW);
  delay(250); 
}

void dash()
{
  digitalWrite(pin13, HIGH);
  delay(750); //dashes last 3x a timing
  digitalWrite(pin13, LOW);
  delay(250); 
}

void letterGap()
{
  //3 timings between each letter of a word but we already have one timing at the end of a dot/dash 
  //so add 2 timings, 250 + (2*250) or 250 + 500
  delay(500); 
}

void wordGap()
{
  //7 timings between each letter of a word but we already have one timing at the end of a dot/dash 
  //so add 6 timings, 250 + (6*250) or 250 + 1500
  delay(1500);
}

void translateMorse(String sentence)
{
  //Sets the sentence to uppercase, useful later on
  sentence.toUpperCase();

  //For loop to break the string apart into its individual letters
  for (size_t i = 0; i < sentence.length(); i++)
  {
    char letter = sentence[i];

    //Checks if theres a space
    if (letter == ' ')
    {
      wordGap();
    }
    else 
    {
      //C++ reads 'A' as 1 and the rest of the letters of the alphabet as numbers, as long as the letter is uppercase and in ' '
      //ex: 'A'=1, 'B'=2, 'C'=3,...,'Z'=26
      //So we can take advantage of it and use it for the alphabet list
      //Alphabet['Letter' - 'A'] = Letter's Morse code 
      //ex: 'Letter' = 'A', Alphabet['A' - 'A'] --> Alphabet[1 - 1] --> Alphabet[0] = ".-"(Morse code for A)
      String morseCode = alphabet[letter - 'A'];

      //Run another For Loop to read each individual dot/dash and play its function
      for (size_t j = 0; j < morseCode.length(); j++)
      {
        //checks if that character is a dot .
        Serial.println(morseCode[j]);
        if (morseCode[j] == '.')
        {
          dot();
        }
        //checks if that character is a dash -
        if (morseCode[j] == '-')
        {
          dash();
        }
        
      }
      letterGap();

    }

  }
  //Once the for loop breaks that means the sentence is over, I'm setting a small break before it loops the message again
  wordGap();

}