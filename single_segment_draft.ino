#include "SevSeg.h"
SevSeg sevseg;

const int buttonPinGreen = 12;  // Start
const int buttonPinRed = 11; // Stop
const int buttoPinBlue = 10; // Reset

// variables will change:
int buttonStateGreen = 0;  // variable for reading the pushbutton status
int buttonStateRed = 0;
int buttonStateBlue = 0;

void setup()
{
  //Set to 1 for single-digit display
  byte numDigits = 1;
  //defines common pins while using multi-digit display. Left for single digit display
  byte digitPins[] = {};
  //Defines Arduino pin connections in order: A, B, C, D, E, F, G, DP
  byte segmentPins[] = {9,8, 7, 6, 5, 4, 3, 2};
  byte displayType = COMMON_CATHODE; //Use COMMON_ANODE for Common Anode display
  bool resistorsOnSegments = true; //‘false’ if resistors are connected to common pin
  //Initialize sevseg object. Use COMMON_ANODE instead of COMMON_CATHODE for CA display

  // initialize the pushbutton pin as an input:
  pinMode(buttonPinGreen, INPUT);
  pinMode(buttonPinRed, INPUT);
  pinMode(buttonPinBlue, INPUT);

  sevseg.begin(displayType, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
  Serial.begin(9600);
}

bool loop = true;

void loop()
{
  //Display numbers 0-9 with 1 seconds delay
  for(int i = 0; i <= 10 && loop; i++)
  {

    // read the state of the pushbutton value:
    buttonStateGreen = digitalRead(buttonPinGreen);
    buttonStateRed = digitalRead(buttonPinRed);
    buttonStateBlue = digitalRead(buttonPinBlue);


    Serial.println(i);
    if (i == 10)
    {
      i = 0;
    }

    if(buttonStateRed == HIGH){
      //wait till green button is pressed
      while buttonStateGreen != HIGH{
        if (buttonStateBlue == HIGH){
          i = 0; 
        } //reset maybe
      } // do nothing 
    }


    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState == HIGH) {
      // turn LED on:
      digitalWrite(ledPin, HIGH);
    } else {
      // turn LED off:
      digitalWrite(ledPin, LOW);
  }

    sevseg.setNumber(i);
    sevseg.refreshDisplay();
    delay(4000);
  }
}