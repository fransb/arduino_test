/*
 * LedFuncVariable.h
 *
 *  Created on: Feb 4, 2015
 *      Author: frans
 */

#ifndef SRC_LEDFUNCVARIABLE_H_
#define SRC_LEDFUNCVARIABLE_H_

class LedFuncVariable {
public:
	LedFuncVariable();
	~LedFuncVariable();
	void Init();
	void Hz60();

private:
	void ledSwitch(int cycles);
/*
	int const LED_PIN = 12;
	int const potPin = A0;
	boolean ledOn;
	int passedCycle;
*/
};

#endif /* SRC_LEDFUNCVARIABLE_H_ */
