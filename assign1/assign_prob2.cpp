/******************************************************************************
Title:				assign_prob2.cpp
Author:				Ethan Blatti, Nick Biegel, Robert Dudasik
Created on:			September 24, 2016
Description:		Enter a unlimited number of characters into the program. Once the user
					terminates the loop with q or Q, display the number of vowels
					the user entered.
Purpose:			Demonstrates using a do while loop to gather input from the user 
					and a switch statment to count the vowels that were entered.
Usage:				Enter chars into the program, to end data entering, q or Q
Build with:			Visual Studio 2015
Modifications:		None
******************************************************************************/
#include <iostream>

using namespace std;

//Main
int main() {
	//create char variable and vowel counter
	char c;
	int vCnt = 0;
	
	//get the next char from the user as long as it is not
	//a Q or q
	do {
		//since Q is not a vowel, it does not matter if it goes through the loop
		cout << "Enter a character: ";
		cin >> c;
		
		//if the char is any of the cases, increment the vowel counter by 1
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

	//print out vowel count
	cout << "There were " << vCnt << " vowels in the characters you entered." << endl;
	
	system("PAUSE");
	return 0;
}