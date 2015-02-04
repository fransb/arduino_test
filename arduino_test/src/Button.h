/*
 * Button.h
 *
 *  Created on: Feb 4, 2015
 *      Author: frans
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "Arduino.h"

class Button {
public:
	Button();
	~Button();
	void Init();
	boolean ReadButton();

private:
	boolean buttonState;
};

#endif /* BUTTON_H_ */
