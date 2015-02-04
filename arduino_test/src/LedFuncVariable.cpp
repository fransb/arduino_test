/*
 * LedFuncVariable.cpp

 *
 *  Created on: Feb 4, 2015
 *      Author: frans
 */

#include "LedFuncVariable.h"
#include "Arduino.h"

int const LED_PIN = 12;
int const potPin = A0;
boolean ledOn;
int passedCycle;

LedFuncVariable::LedFuncVariable() {
	ledOn = false;
	passedCycle = 0;
}

LedFuncVariable::~LedFuncVariable() {
	// TODO Auto-generated destructor stub
}

void LedFuncVariable::Init() {
	ledOn=false;
	passedCycle=0;
}

void LedFuncVariable::ledSwitch(int cycles) {
	if (passedCycle > (cycles / 2)) {
		passedCycle = 0;
		if (ledOn) {
			digitalWrite(LED_PIN, LOW);
			ledOn = false;
		} else {
			digitalWrite(LED_PIN, HIGH);
			ledOn = true;
		}
	} else {
		++passedCycle;
	}
}

void LedFuncVariable::Hz60() {

	int potVal = analogRead(potPin);

	if ((potVal < 0) || (potVal > 1023)) {
		//TODO error
		return;
	}

	int procent = map(potVal, 0 , 1023, 0 , 99);


	if (procent < 33){
		int cycles = map(procent, 0, 33, 240, 48);

		ledSwitch(cycles);



	} else if (procent < 67) {
		ledSwitch(75);

	} else {
		int cycles = map(procent, 67, 99, 48, 240);
		ledSwitch(cycles);
	}

}
