/*
 * exam.cpp
 *
 *  Created on: Aug 23, 2021
 *      Author: HOO5HC
 */

#include "exam.h"
void Say(const char* message)
{
	printf(message);
}
void securityExample::CreateKey(uint8_t* Key, uint8_t* Seed)
{
	getTime();
	convert();
	RotateTimeBuffer();
	Key[0] = (Time[3] & Seed[0]) + 30;
	Key[1] = (Time[2] & Seed[1]) + 21;
	Key[2] = (Time[1] & Seed[2]) + 12;
	Key[3] = (Time[0] & Seed[3]) + 3;
}
void securityExample::getTime()
{
	time_t my_time = time(NULL);
	timeBuff = ctime(&my_time);
}
void securityExample::convert()
{
	int stt = 0;
	char *token = strtok(timeBuff," :");
	while (token != NULL)
	    {
	        switch(stt)
	        {
	        	case 1:
	        		Time[1] = (convertMonth(token)/10)+48;
	        		break;
	        	case 2:
	        		Time[2] = token[1];
	        		break;
	        	case 3:
	        		Time[3] = token[0];
	        		break;
	        	case 6:
	        		Time[0] = token[3];
	        		break;
	        }
	        token = strtok(NULL, " :");
	        stt++;
	    }
}

void securityExample::RotateTimeBuffer(void)
{
	int time_shift = 4;
	Rotate(&Time[0],RCL,time_shift);
	Rotate(&Time[1],RCR,time_shift);
	Rotate(&Time[2],ROL,time_shift);
	Rotate(&Time[3],ROR,time_shift);
}


/* Security */
RotateFlag securityExample::Rotate(unsigned char* inputNumber, uint8_t rotationMethod, uint8_t timeShift)
{
	uint8_t tempCount;
	uint8_t tempCF = 0, CF = 0;
	uint8_t OF;
	uint8_t destination = *inputNumber;
	RotateFlag flag;
	switch(rotationMethod)
	{
		case RCL:
			tempCount = timeShift % 9;
			while(tempCount != 0)
			{
				tempCF = (destination & 0x80) >> 7;
				destination = (destination << 1) + CF;
				CF = tempCF;
				tempCount = tempCount - 1;
			}
			if(timeShift == 1)
				OF = ((destination & 0x80) >> 7) ^ CF;
			else
				OF = 0xff | OF;
			*inputNumber = destination;
			break;
		case RCR:
			tempCount = timeShift % 9;
			if(timeShift == 1)
				OF = (destination & 0x01) ^ CF;
			else
				OF = 0xff;
			while(tempCount != 0)
			{
				tempCF = destination & 0x01;
				destination = (destination >> 1) + (CF << 7);
				CF = tempCF;
				tempCount = tempCount - 1;
			}
			*inputNumber = destination;
			break;
		case ROL:
			tempCount = timeShift % 8;
			while(tempCount != 0)
			{
				tempCF = (destination & 0x80) >> 7;
				destination = (uint8_t)(destination << 1) + tempCF;
				tempCount = tempCount - 1;
			}
			CF = destination & 0x01;
			if(timeShift == 1)
				OF = ((destination & 0x80) >> 7) ^ CF;
			else
				OF = 0xff;
			*inputNumber = destination;
			break;
		case ROR:
			tempCount = timeShift % 8;
			while(tempCount != 0)
			{
				tempCF = destination & 0x01;
				destination = (destination >> 1) + (tempCF << 7);
				tempCount = tempCount - 1;
			}
			CF = destination >> 7;
			if(timeShift == 1)
				OF = (destination >> 7) ^ ((destination & 0x40) >> 6);
			else
				OF = 0xff;
			*inputNumber = destination;
	}
	flag.OF_flag = (OF == 0)? false:true;
	flag.CF_Flag = (CF == 0)? false:true;
	return flag;
}

/* Helper */

bool securityExample::strCompare(char* str1,const char* str2, uint8_t length)
{
	for(int i = 0; i< length; i++)
	{
		if(str1[i] != str2[i])
			return false;
	}
	return true;
}

int securityExample::convertMonth(char* month)
{
	if(strCompare(month, "Jan",3))
	{
		return 1;
	} else if(strCompare(month, "Feb",3))
	{
		return 2;
	} else if(strCompare(month, "Mar",3))
	{
		return 3;
	} else if(strCompare(month, "Apr",3))
	{
		return 4;
	} else if(strCompare(month, "May",3))
	{
		return 5;
	} else if(strCompare(month, "Jun",3))
	{
		return 6;
	} else if(strCompare(month, "Jul",3))
	{
		return 7;
	} else if(strCompare(month, "Aug",3))
	{
		return 8;
	} else if(strCompare(month, "Sep",3))
	{
		return 9;
	} else if(strCompare(month, "Oct",3))
	{
		return 10;
	} else if(strCompare(month, "Nov",3))
	{
		return 11;
	} else if(strCompare(month, "Dec",3))
	{
		return 12;
	}
	return 0xff;
}

