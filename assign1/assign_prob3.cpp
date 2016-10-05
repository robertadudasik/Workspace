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
Build with:			Visual Studio 2015
Modifications:		None
******************************************************************************/
#include <iostream>

using namespace std;

//Main
int main() {
	//create the needed int values and int array pointer
	int index = 0, size = 5, num;
	int *array = new int[size]{0};

	//for as long as we can get a valid int
	cout << "Enter a number to add to array: ";
	while (cin >> num) {
		if (index < size) {
			//if the index is smaller than the size, add to the array at index
			array[index] = num;
		} else {
			//else create new temporary array with a incremented size, the copy over values
			//and set the array pointer to the temp pointer
			size++;	
			int *temp = new int[size];
			for (int i = 0; i < size - 1; i++) temp[i] = array[i];	
			temp[index] = num;		
			delete[] array;				
			array = temp;		
		}

		//increment the index and ask for next int to be entered
		index++;						
		cout << "Enter a number to add to array: ";
	}

	//create the sum for the average
	int sum = 0;

	//print the array five to a line while adding to the sum
	for (int i = 0; i < size; i++) {
		sum += array[i];
		cout << array[i] << " ";
		if ((i + 1) % 5 == 0) cout << endl;
	}

	//print out the average
	if(index != 0)
		cout << endl << "Average: " << (sum / index) << endl;
	else
		cout << endl << "Average: Undefined" << endl;
	
	system("PAUSE");
	return 0;
}