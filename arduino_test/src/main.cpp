/*
 * main.cpp
 *
 *  Created on: Nov 20, 2013
 *      Author: frans
 */

#include "Arduino.h"
#include "LedFuncVariable.h"
#include "LedFuncFixed.h"
#include "Button.h"

const int led = 12;
const int buttonLed = 13;
const int potpin = A0;
const int buttonPin = 2;

unsigned long StartTime;


LedFuncVariable ledFuncVariable;
LedFuncFixed ledFuncFixed;
Button button;

enum State {
  PBIT,
  Variable,
  Fixed
};

State state = PBIT;

void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);

  pinMode(buttonLed, OUTPUT);

  StartTime = 0;

  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

	unsigned long CurrentTime = micros();
	unsigned long ElapsedTime = CurrentTime - StartTime;





	/*
	if (digitalRead(2)) {
		digitalWrite(buttonLed, HIGH);
	} else {
		digitalWrite(buttonLed, LOW);
	}*/

	if ((ElapsedTime > 15618) || (StartTime == 0)) {
		//TODO borde vara 16667
		StartTime = CurrentTime;

		boolean buttonPressed = button.ReadButton();

		switch (state) {
			case PBIT:
				state = Variable;
				break;
			case Variable:

				if (buttonPressed){
					state = Fixed;
				}
				ledFuncVariable.Hz60();
				break;
			case Fixed:

				if (buttonPressed){
					state = Variable;
				}
				ledFuncFixed.Hz60();
				break;
			default:
				break;
		}

	}

}


int main() {
	init();

	setup();

	ledFuncVariable.Init();


	Serial.println("start");
	while(1) {
		loop();
	}
}

