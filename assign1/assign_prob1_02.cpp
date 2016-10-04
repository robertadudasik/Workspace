/******************************************************************************
Title:				assign_prob1_02.cpp
Author:				Nicholas Biegel
Created on:			September 24, 2016
Description:		Enter a unlimited number of integers into. Once the user terminates
					to data entering loop, display the sum to the values entered.
Purpose:			Demonstrates using the for loop to gather user input.
Usage:				assign_prob1_02
					Enter integers into the program, to end data entering, enter 0.
					Build with:	g++ -o assign_prob1_02 assign_prob1_02.cpp 
								(or Visual Studio, must set Linker>System>SubSystem to CONSOLE)
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
	return 0;
}