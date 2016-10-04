/******************************************************************************
Title:				assign_prob2.cpp
Author:				Nicholas Biegel
Created on:			September 24, 2016
Description:		Enter a unlimited number of characters into the program. Once the user
					terminates the loop with q or Q, display the number of vowels
					the user entered.
Purpose:			Demonstrates using a do while loop to gather input from the user 
					and a switch statment to count the vowels that were entered.
Usage:				Enter integers into the program, to end data entering, enter anything other than an integer.
					Build with:	Visual Studio 2015
Modifications:		None
******************************************************************************/
#include <iostream>
using namespace std;

int main() {
	char c;
	int vCnt = 0;
	do {
		cout << "Enter a character: ";
		cin >> c;
		switch (c) {
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			vCnt++;
			break;
		}
	} while (c != 'Q' && c != 'q');

	cout << "There were " << vCnt << " vowels in the characters you entered." << endl;
	
	system("PAUSE");
	return 0;
}