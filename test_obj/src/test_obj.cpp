//============================================================================
// Name        : test_obj.cpp
// Author      : Sy hoang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "exam.h"

using namespace std;

securityExample code;
uint8_t key[4];
uint8_t seed[4] = {4,5,12,5};
int main() {
	/*
	code.CreateKey(key, seed);
	printf("%x\n", key[0]);
	printf("%x\n", key[1]);
	printf("%x\n", key[2]);
	printf("%x\n", key[3]);
	*/
	code.test();
	return 0;
}

