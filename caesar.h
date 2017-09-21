#ifndef _CAESAR_H_
#define _CAESAR_H_

#define UPALP 0 //upper case
#define LWALP 1 //lower case
#define DIGIT 2
#define NEITHER 3
#define LEFT -1
#define RIGHT 1
#define SAME 6

typedef struct {
	int numShift;
	int length;
	char* string;
} Input;

Input GetInputStringInfo(char* string);
void EncodedString(Input stringInfo);

#endif 

