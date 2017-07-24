#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caesar.h"

//Function Declarations 
void CallAllEncodeFuncs(char* input);

//Function Definitions
void CallAllEncodeFuncs(char* input)
{
	char string[215]; //the longest input will not be greater than 210. I allocate more spaces in case.
	strcpy(string, input);
	
	Input stringInfo = GetInputStringInfo(string);
	printf("Input numshift = %d, Input string length = %d, Input actual string = %s\n", stringInfo.numShift, stringInfo.length, stringInfo.string);

	EncodedString(stringInfo);
	printf("main -> encoded string = %s\n\n", stringInfo.string);
	
	free(stringInfo.string);
	return;
}

int main(int argc, const char* argv[])
{
	//test case 1
	char* input = "0:A2c"; //input string
	CallAllEncodeFuncs(input);
	
	//test case 2 
	input = "2:A2c";
	CallAllEncodeFuncs(input);

	//test case 3
	input = "-2:A2c";
	CallAllEncodeFuncs(input);

	//test case 4
	input = "3:A 2";
	CallAllEncodeFuncs(input);

	//test case 5
	input = "4:Ab22@# c";
	CallAllEncodeFuncs(input);

	//test case 6 
	input = "24:Ab1@ X";
	CallAllEncodeFuncs(input);

	//test case 7 
	input = "-24:Ab1@ X";
	CallAllEncodeFuncs(input);

	//test case 8 
	input = "200:2b!";
	CallAllEncodeFuncs(input);

	//test case 9
	input = "-200:2b!"; 
	CallAllEncodeFuncs(input);

	//test case 10
	input = "1000000:2A%89Cd";
	CallAllEncodeFuncs(input);

	//test case 11
	input = "-1000000:2A%89Cd";
	CallAllEncodeFuncs(input);

	return(EXIT_SUCCESS);
}
