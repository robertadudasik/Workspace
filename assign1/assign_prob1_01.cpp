/******************************************************************************
Title:				assign_prob1_01.cpp
Author:				Ethan Blatti, Nick Biegel, Robert Dudasik
Created on:			September 24, 2016
Description:		Enter a unlimited number of integers into. Once the user terminates
					to data entering loop, display the sum to the values entered.
Purpose:			Demonstrates using the do-while loop to gather user input.
Usage:				Enter integers into the program, to end data entering, enter 0.
					Build with:	Visual Studio 2015
Modifications:		None
******************************************************************************/
#include <iostream>
using namespace std;

int main() {
	int num, sum = 0;

	do {
		cout << "Enter a number (0 to end): ";
		cin >> num;
		sum += num;
	} while (num != 0);

	cout << "The total of numbers entered was: " << sum << endl;
	
	system("PAUSE");
	return 0;
}