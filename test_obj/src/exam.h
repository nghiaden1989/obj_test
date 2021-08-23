/*
 * exam.h
 *
 *  Created on: Aug 23, 2021
 *      Author: HOO5HC
 */

#ifndef EXAM_H_
#define EXAM_H_
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "string.h"

using namespace std;

void Say(const char* message);

typedef struct RotateFlag
{
	bool CF_Flag;
	bool OF_flag;
} RotateFlag;

class securityExample
{
public:
	void CreateKey(uint8_t* Key, uint8_t* Seed);
private:
	void getTime();
	void convert();
	void RotateTimeBuffer(void);
	bool strCompare(char* str1,const char* str2, uint8_t length);
	int convertMonth(char* month);
protected:
	#define RCL 0x00
	#define RCR 0x01
	#define ROL 0x02
	#define ROR 0x03
	char* timeBuff;
	unsigned char Time[4];
	RotateFlag Rotate(unsigned char* inputNumber, uint8_t rotationMethod, uint8_t timeShift);
};


#endif /* EXAM_H_ */
