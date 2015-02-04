/*
 * Button.cpp
 *
 *  Created on: Feb 4, 2015
 *      Author: frans
 */

#include "Button.h"
#include "Arduino.h"

Button::Button() {
	// TODO Auto-generated constructor stub

}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

void Button::Init() {
	buttonState = false;
}

boolean Button::ReadButton() {
	boolean button = digitalRead(2);


	if ((buttonState == false) && (button == true)) {
		buttonState = button;
		return true;
	} else {
		buttonState = button;
		return false;
	}
}
