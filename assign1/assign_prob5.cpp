
/******************************************************************************
Title:				assign_prob5.cpp
Author:				Ethan Blatti, Nick Biegel, Robert Dudasik
Created on:			October 4, 2016
Description:			Call a function through a pointer to verify that it works.
Purpose:			To verify that ascVal() works when called through a pointer.
Usage:				Run the program to verify that ascVal() determines the ASCII value of a character.
Build with:			Visual Studio 2015
Modifications:			None
******************************************************************************/
#include <iostream>
#include <cstring>

using namespace std;

int ascVal(size_t ip, const char* p)
{
	// Return the ASCII value of the char
	if(!p || ip > strlen(p)) {
		return  -1;
	}
	else {
	return p[ip];
	}
}

int main() {

	//create pointer to function
	int(*value)(size_t,const char*);
	value = &ascVal;


	//create character and pointer to character to test
	char character = 'a';
	char* pchar = &character;

	//call the pointer to the function and generate output
	cout << "The ascii value of " << character << " is: " << value(0, pchar) << endl;
	
	system("PAUSE");
	return 0;
}
