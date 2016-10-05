/******************************************************************************
Title:				assign_prob3.cpp
Author:				Ethan Blatti, Nick Biegel, Robert Dudasik
Created on:			September 24, 2016
Description:		Enter a unlimited number of integers into the program. Once the user
					terminates the loop, display 5 to a line until all numbers entered
					are displayed. Also display the average to the user.
Purpose:			Demonstrates expanding an array once its size is excceeded. As well
					demonstrating how to loop through the array and show 5 numbers
					to a line.
Usage:				Enter integers into the program, to end data entering, enter anything other than an integer.
					Build with:	Visual Studio 2015
Modifications:		None
******************************************************************************/
#include <iostream>
using namespace std;
int main() {
	int index = 0, size = 5, num;
	int *array = new int[size];

	cout << "Enter a number to add to array: ";
	while (cin >> num) {
		if (index < size) {
			array[index] = num;
		} else {
			size++;						//Increment array size
			int *temp = new int[size];	//Create new array with that size
			for (int i = 0; i < size - 1; i++) temp[i] = array[i];		//Copy the values of the original array into the new one
			temp[index] = num;			//Set the added element to the number entered
			delete[] array;				//Free up memory taken up by array
			array = temp;				//Set array to new array
		}
		index++;						//Increase the index for next go around
		cout << "Enter a number to add to array: ";
	}

	int sum = 0;;
	for (int i = 0; i < size; i++) {
		sum += array[i];
		cout << array[i] << " ";
		if ((i + 1) % 5 == 0) cout << endl;
	}

	cout << endl << "Average: " << (sum / index) << endl;
	
	system("PAUSE");
	return 0;
}