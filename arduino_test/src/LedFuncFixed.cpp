/*
 * LedFuncFixed.cpp

 *
 *  Created on: Feb 4, 2015
 *      Author: frans
 */

#include "LedFuncFixed.h"
#include "Arduino.h"

int const LED_PIN_FIXED = 12;
boolean ledOnFixed;
int passedCycleFixed;

LedFuncFixed::LedFuncFixed() {
	// TODO Auto-generated constructor stub

}

LedFuncFixed::~LedFuncFixed() {
	// TODO Auto-generated destructor stub
}

void LedFuncFixed::Init() {
	ledOnFixed=false;
	passedCycleFixed=0;
}

void LedFuncFixed::ledSwitch(int cycles) {
	if (passedCycleFixed > (cycles / 2)) {
		passedCycleFixed = 0;
		if (ledOnFixed) {
			digitalWrite(LED_PIN_FIXED, LOW);
			ledOnFixed = false;
		} else {
			digitalWrite(LED_PIN_FIXED, HIGH);
			ledOnFixed = true;
		}
	} else {
		++passedCycleFixed;
	}
}

void LedFuncFixed::Hz60() {
	ledSwitch(60);
}
