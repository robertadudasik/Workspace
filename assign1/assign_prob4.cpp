/******************************************************************************
Title:				assign_prob4.cpp
Author:				Ethan Blatti, Nick Biegel, Robert Dudasik
Created on:			September 24, 2016
Description:		Prints out each section of the string provided by the delimiter
					provided.
Purpose:			Demonstrates the C like function of strtok
Usage:				Run thr program, and observe the results.
Build with:			Visual Studio 2015
Modifications:		None
******************************************************************************/
#include <iostream>

using namespace std;

//Function Prototypes
/*
	m_strtok simulates the c like strtok function.
	Returns first part of the provided string up to the
	delimiter. Returns NULL if nothing is to be found.
*/
char* m_strtok(char* str, char* delim);

//Main
int main() {
	//create character array and delimiter value
	char data[]{ "one two three" };
	char delim = ' ';

	//get the first string token value
	char* tok = m_strtok(data, &delim);

	//while the token is not null, print the token and get the next token
	while (tok != NULL) {
		cout << tok << endl;
		tok = m_strtok(NULL, &delim);
	}

	system("PAUSE");
	return 0;
}

//Function definitions
char* m_strtok(char* str, char* delim) {
	//create static pointer to the provided character array and local temp char pointer
	static char* string;
	char* tmp;

	//set str to it's appropriate value, else return NULL since we are at the end.
	if (str == NULL && string != NULL)
		str = string;
	else if (str == NULL)
		return NULL;

	//set temp to NULL, then look for first instance of the delimiter
	tmp = NULL;
	for (int i = 0; i < sizeof(str) / sizeof(char); i++) {
		if (str[i] == *delim) {
			tmp = &str[i];
			break;
		}
	}

	//if delimiter was found, set to NULL and then set the static var to
	//char location after the delimiter. Otherwise the string is NULL
	if (tmp) {
		*tmp = '\0';
		string = tmp + 1;
	}
	else {
		string = NULL;
	}

	//return the token
	return str;
}
