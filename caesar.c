#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "caesar.h"

//Function Declarations
int _CheckChar(char chr);
int _CheckNumOfShifts(int num, int* ALPshift, int* DGshift);
void _EncodeChar(char* add_char, int shiftDirect, int modValue, int numShift, int arraySize);

//Function Definitions 
Input GetInputStringInfo(char* inputString)
{
	Input stringInfo;
	//Get number of shifts
	stringInfo.numShift = atoi(strtok(inputString, ":"));
	
	//Get the actual Input string and malloc it 
	char* actualString = strtok(NULL, "\0");
	char* malactstring = malloc(sizeof(*malactstring) * (strlen(actualString) + 1)); 
	strcpy(malactstring, actualString);
	stringInfo.string = malactstring;

	//Get length of the actual Input string
	stringInfo.length = strlen(actualString);
	
	return(stringInfo);
}

int _CheckNumOfShifts(int num, int* ALPshift, int* DGshift)
{
	//check if it is right or left shift and return the number of shifts for aplabet and digit
	
	int ComMult = 26*9; //the least common multiple for 26 & 9
	if(num == 0 || (num % ComMult) == 0)
	{
		return(SAME);
	}
	else
	{
		*ALPshift = num > 0 ? num % 26 : -num % 26;
		*DGshift = num > 0 ? num % 10 : -num % 10;
		int direction = num > 0 ? RIGHT : LEFT;
		return(direction);
	}
}

int _CheckChar(char chr)
{
	//check if the charater is upper, lower case, digit or neither 
	if(chr >= 48 && chr <= 57)
	{
		return(DIGIT);
	}
	else if(chr >= 65 && chr <= 90)
	{
		return(UPALP);
	}
	else if(chr >= 97 && chr <= 122)
	{
		return(LWALP);
	}
	else
	{
		return(NEITHER);
	}
}

void _EncodeChar(char* add_char, int shiftDirect, int modValue, int numShift, int arraySize)
{
	int pos = add_char[0] % modValue; //position of the character in array of alphabets or array of digits 
	//eg: ABCDEF...., abcd..., 012345...
	//arraySize for array of alphabets = 26, arraySize for array of digits = 10

	//calculate the ASCII value for encoded character
	*add_char = (pos + shiftDirect * numShift + arraySize) % arraySize + modValue; 
}


void EncodedString(Input stringInfo)
{
	int num = stringInfo.numShift; //number of shifts from input 
	int length = stringInfo.length; //length of string to be encoded
	int ALPshift = 0;
	int DIGshift = 0;
	int shiftDirect = _CheckNumOfShifts(num, &ALPshift, &DIGshift);

	//no need to encode when num of shift is 0 
	if(shiftDirect == SAME)
	{	
		return;
	}

	char* actualString = stringInfo.string; 
	//encode when num of shift is not 0 
    	int c = 0; //count the current pointer position in actual string
	while(c < length)
	{
		char current = actualString[c]; 
		int attribute = _CheckChar(current); //attribute of that char
		if(attribute == UPALP && ALPshift != 0)
		{
			_EncodeChar(&(actualString[c]), shiftDirect, 65, ALPshift, 26);
		}
		else if(attribute == LWALP && ALPshift != 0)
		{
			_EncodeChar(&(actualString[c]), shiftDirect, 97, ALPshift, 26);
		}
		else if(attribute == DIGIT && DIGshift != 0)
		{
			_EncodeChar(&(actualString[c]), shiftDirect, 48, DIGshift, 10);
		}
		c++;
	}
	
	return;
}


