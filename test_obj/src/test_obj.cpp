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
uint8_t key[4] = {1,2,3,4};
uint8_t seed[4] = {4,5,2,1};
int main() {

	//code.convert("Mon-Aug-23-10:40:38-2021");

	//char str[] = "Mon-Aug-23-10:40:38-2021";
	//code.convert("Mon-Aug-23-10:40:38-2021");
	code.CreateKey(key, seed);
	printf("%d\n", key[0]);
	printf("%d\n", key[1]);
	printf("%d\n", key[2]);
	printf("%d\n", key[3]);
	return 0;
}
