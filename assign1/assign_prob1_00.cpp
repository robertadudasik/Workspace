/******************************************************************************
Title:				assign_prob1_00.cpp
Author:				Ethan Blatti, Nick Biegel, Robert Dudasik
Created on:			September 24, 2016
Description:		Enter a unlimited number of integers into. Once the user terminates
					to data entering loop, display the sum to the values entered.
Purpose:			Demonstrates using the while loop to gather user input.
Usage:				Enter integers into the program, to end data entering, enter 0.
Build with:			Visual Studio 2015
Modifications:		None
******************************************************************************/
#include <iostream>

using namespace std;

//Main
int main() {
	//create int variables
	int num = 0, sum = 0;

	//ask user for first number
	cout << "Enter a number (0 to end): ";
	cin >> num;
	
	//while number is not zero, add to sum and ask for next number
	while (num != 0) {
		sum += num;
		cout << "Enter a number (0 to end): ";
		cin >> num;
	}
	
	//print the sum of numbers entered
	cout << "The total of numbers entered was: " << sum << endl;
	
	system("PAUSE");
	return 0;
}
