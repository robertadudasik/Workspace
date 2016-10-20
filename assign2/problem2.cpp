/******************************************************************************
Title:				problem2.cpp
Author:				Ethan Blatti, Nick Biegel, Robert Dudasik
Created on:			October 15, 2016
Description:		Generates a report for a user's savings account with the data provided.
Purpose:			Generate a report for a savings account using data provided by the user.
Usage:				Generate a report by taking user input and manipulating it.
Build with:			Visual Studio 2015
Modifications:		None
******************************************************************************/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	vector<float> scores;
	float score, curve;

	cout << "===== Test Score Normalizer =====" <<endl<<endl;
	//Get the test scores
	while (true) {
		cout << "Enter a test score(non-whole number to exit): ";
		cin >> score;

		//Bad non-number, less than zero, greater than 100(Assuming no extra credit given before hand)
		if (!cin || score < 0 || score > 100) break;
		
		scores.push_back(score);
	}

	cout << endl;
	if (scores.size() > 0) {
		//Find the highest value to set curve to
		curve = -1;
		for (float s : scores) {
			if (s > curve) curve = s;
		}

		//Print out the curved scores
		cout << fixed << setprecision(2);
		cout << "Curve: 100.00% based on " << curve << "%" << endl;
		for (unsigned int i = 0; i < scores.size(); i++) {
			float n = scores.at(i);
			cout << "Score " << (i + 1) << ": " << n << "%, Curved to: " << ((n/curve)*100) << "%" << endl;
		}
		cout << endl;
	} else {
		cout << "No scores have been entered." << endl << endl;
	}

	system("PAUSE");
	return 0;
}