/******************************************************************************
Title:				assign_prob1_02.cpp
Author:				Ethan Blatti, Nick Biegel, Robert Dudasik
Created on:			September 24, 2016
Description:		Enter a unlimited number of integers into. Once the user terminates
					to data entering loop, display the sum to the values entered.
Purpose:			Demonstrates using the for loop to gather user input.
Usage:				Enter integers into the program, to end data entering, enter 0.
					Build with:	Visual Studio 2015
Modifications:		None
******************************************************************************/
#include <iostream>
using namespace std;

int main() {
	int num = 0, sum = 0, count = 0;
	for (int i = 0; i <= count; i++) {
		cout << "Enter a number (0 to end): ";
		cin >> num;
		sum += num;
		if (num != 0) count++;
	}
	cout << "The total of numbers entered was: " << sum << endl;
	
	system("PAUSE");
	return 0;
}