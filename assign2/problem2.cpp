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