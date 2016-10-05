/******************************************************************************
Title:				assign_prob4.cpp
Author:				Ethan Blatti, Nick Biegel, Robert Dudasik
Created on:			September 24, 2016
Description:		Prints out each section of the string provided by the delimiter 
					provided.
Purpose:			Demonstrates the C like function of strtok
Usage:				Enter integers into the program, to end data entering, enter anything other than an integer.
					Build with:	Visual Studio 2015
Modifications:		None
******************************************************************************/
#include <iostream>
using namespace std;

char* m_strtok(char* str, char* delim);

int main() {
	char data[]{"one two three"};
	char delim = ' ';
	char* tok = m_strtok(data, &delim);
	while (tok != NULL) {
		cout << tok << endl;
		tok = m_strtok(NULL, &delim);
	}
	
	system("PAUSE");
	return 0;
}

char* m_strtok(char* str, char* delim) {
	static char* string;
	char* tmp;
	if (str == NULL && string != NULL)
		str = string;
	else if(str == NULL)
		return NULL;

	tmp = NULL;
	for (int i = 0; i < sizeof(str) / sizeof(char); i++) {
		if (str[i] == *delim) {
			tmp = &str[i];
			break;
		}
	}

	if (tmp) {
		*tmp = '\0';
		string = tmp + 1;
	} else {
		string = NULL;
	}
	return str;
}