/******************************************************************************
Title:				assign_prob6.cpp
Author:				Ethan Blatti, Nick Biegel, Robert Dudasik
Created on:			October 2, 2016
Description:		Generates a report for a user's savings account with the data provided.
Purpose:			Generate a report for a savings account using data provided by the user.
Usage:				Generate a report by taking user input and manipulating it.
Build with:			Visual Studio 2015
Modifications:		None
******************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//If an input is incorrect, tell the user and clear whatever value is in "cin" and ignore it as input.
void isIncorrect() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Invaid value entered. Please try again." << endl;
}

//Generates report with the calculated data
void generateReport(vector<double> withdrawals, vector<double> deposits, double initBal, double bal, double interest) {
	double totWith = 0;
	double totDep = 0;
	cout << "\n**********Monthly Report**********\n";
	cout << "The initial balance is: $" << initBal << endl << endl;
	cout << "The withdrawals are: " << endl;
	for (unsigned int i = 0; i < withdrawals.size(); i++) {
		cout << "$" << withdrawals[i] << endl;
		totWith += withdrawals[i];
	}
	cout << endl;
	cout << "The total amount of withdrawals is: $" << totWith << endl << endl;
	cout << "The deposits are: " << endl;
	for (unsigned int i = 0; i < deposits.size(); i++) {
		cout << "$" << deposits[i] << endl;
		totDep += deposits[i];
	}
	cout << endl;
	cout << "The total amount of deposits is: $" << totDep << endl << endl;
	cout << "The ending balance is: $" << bal << endl << endl;
	cout << "The interest accrued is: $" << interest << endl << endl;
	cout << "The balance with interest is: $" << bal + interest << endl << endl;


}

//Calculate interest on an account of a given balance
double calculateInterest(double balance) {

	//InterestRate is 10% annually, which is then divided by 12 to get the rate for the month, as instructed.
	double interestRate = 0.1 / 12;
	double interest = balance * interestRate;

	//cannot accrue a negative interest
	if (interest < 0) {
		return 0;
	}
	return interest;
}

//subtract the withdrawals from a given balance
double subtractWithdrawals(vector<double> w, double balance) {
	double bal = balance;
	for (unsigned int i = 0; i < w.size(); i++) {
		bal -= w[i];
	}
	return bal;
}

//add the deposits to a given balance
double addDeposits(vector<double> d, double balance) {
	double bal = balance;
	for (unsigned int i = 0; i < d.size(); i++) {
		bal += d[i];
	}
	return bal;
}

//Read in data from user
void readData(vector<double> &w, vector<double> &d, double &iB) {
	double initBal;
	vector<double> withdrawals;
	vector<double> deposits;
	double value = 0;
	bool valid = false;

	//loop until a valid value is entered
	while (false == valid) {
		cout << "Enter the initial balance: ";
		cin >> value;

		//if value entered is not valid, call isIncorrect(), which is defined above
		if (!cin || (value<0)) {
			isIncorrect();
		}
		else
		{
			initBal = value;
			valid = true;
		}
	}
	value = 0;

	//read values into the withdrawal vector until a -1 is entered
	while (-1 != value) {
		cout << "Enter the withdrawls (Enter \"-1\" to stop): ";
		cin >> value;
		if (!cin || (value<0 && -1 != value)) {
			isIncorrect();
		}
		else {
			if (-1 != value) {
				withdrawals.push_back(value);
			}
		}


	}
	value = 0;

	//read values into the deposits vector until a -1 is entered
	while (-1 != value) {
		cout << "Enter the deposits (Enter \"-1\" to stop): ";
		cin >> value;
		if (!cin || (value<0 && -1 != value)) {
			isIncorrect();
		}
		else {
			if (-1 != value) {
				deposits.push_back(value);
			}
		}


	}

	//change the parameters' addresses so that the values read in are stored
	iB = initBal;
	d = deposits;
	w = withdrawals;

}

int main() {
	//set formatting
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//variable declaration
	double bal;
	vector<double> withdrawals;
	vector<double> deposits;
	double interest;
	double initBal;

	//read in user data
	readData(withdrawals, deposits, bal);
	initBal = bal;

	//add deposits to the balance
	bal = addDeposits(deposits, bal);

	//subtract the withdrawals from the balance
	bal = subtractWithdrawals(withdrawals, bal);

	//calculate the interest
	interest = calculateInterest(bal);

	//generate report
	generateReport(withdrawals, deposits, initBal, bal, interest);

	system("PAUSE");
	return 0;
}