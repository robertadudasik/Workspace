/******************************************************************************
Title:				assign_prob1_02.cpp
Author:				Ethan Blatti, Nick Biegel, Robert Dudasik
Created on:			September 24, 2016
Description:		Enter a unlimited number of integers into. Once the user terminates
					to data entering loop, display the sum to the values entered.
Purpose:			Demonstrates using the for loop to gather user input.
Usage:				Enter integers into the program, to end data entering, enter 0.
Build with:			Visual Studio 2015
Modifications:		None
******************************************************************************/
#include <iostream>

using namespace std;

//Main
int main() {
	//create int variables
	int num = 0, sum = 0, count = 0;
	
	//ask user for number
	for (int i = 0; i <= count; i++) {
		cout << "Enter a number (0 to end): ";
		cin >> num;
		
		//exit if the wrong value was entered
		if (!cin) {
			cout << endl << "Invalid value entered. Please restart the program and try again." << endl;
			system("PAUSE");
			return 0;
		}
		
		//add number to sum
		sum += num;
		
		//if number is not zero, increment count so for loop continues on
		if (num != 0) count++;
	}
	
	//print sum of numbers entered
	cout << "The total of numbers entered was: " << sum << endl;
	
	system("PAUSE");
	return 0;
}