/*
 * LedFuncFixed.h
 *
 *  Created on: Feb 4, 2015
 *      Author: frans
 */

#ifndef SRC_LEDFUNCFIXED_H_
#define SRC_LEDFUNCFIXED_H_

#include "Arduino.h"

class LedFuncFixed {
public:
	LedFuncFixed();
	~LedFuncFixed();
	void Init();
	void Hz60();

private:
	void ledSwitch(int cycles);
};

#endif /* SRC_LEDFUNCFIXED_H_ */
