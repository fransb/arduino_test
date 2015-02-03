/*
 * main.cpp
 *
 *  Created on: Nov 20, 2013
 *      Author: frans
 */

#include "Arduino.h"

int led = 12;
int ledPin = 11;
byte dim = 0;
int TimeOff = 0;
int potpin1 = 0;
int potpin2 = 1;
int potpin3 = 2;
int buttonPin = 2;
int time = 0;
bool button = false;
int delayTime = 15;
int start = 0;
int stopp = 255;

void setupPins() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

}

// the loop routine runs over and over again forever:
void loop() {
/*	if ((digitalRead(buttonPin) == HIGH) && (!button)) {

		button = true;

		int pot1 = analogRead(potpin1);
		int pot2 = analogRead(potpin2);
		int pot3 = analogRead(potpin3);

		delayTime = map(pot1, 0, 1023, 0, 250);

		start = map(pot2, 0, 1023, 0, 255);
		stopp = map(pot3, 0, 1023, 0, 255);

		Serial.println("Delay: ");
		Serial.println(delayTime);

		Serial.println("Start: ");
		Serial.println(start);

		Serial.println("Stop: ");
		Serial.println(stopp);

	} else if (digitalRead(buttonPin) == LOW) {
		button = false;
		analogWrite(ledPin, random(start,stopp));
		delay(delayTime);
	}



*/
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayTime);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);               // wait for a second
  delayTime = delayTime - 50;
  if (delayTime < 100) {
	  delayTime = 1000;
  }




}


int main() {
	init();
	setupPins();
	Serial.println("start");
	while(1) {
		loop();
	}
}

