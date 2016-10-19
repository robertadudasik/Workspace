#include <iostream>
#include <string>
#include <map>


using namespace std;

//create a class for a person
class person {
public:
	string name;
	person(string);
	void set_values( string, string, string, string, string);
	void printRecord();
private:
	string street_number;
	string street;
	string city;
	string state;
	string zipcode;
};


//create constructor
person::person(string name) {
	this->name = name;
}
//create the set_values method
void person::set_values(string _street_number, string _street, string _city, string _state, string _zipcode) {
	this->street_number = _street_number;
	this->street = _street;
	this->city = _city;
	this->state = _state;
	this->zipcode = _zipcode;
}
//create print record method
void person::printRecord() {
	cout << "\nName: " << this->name << endl;
	cout << "Address: " << this->street_number << " " << this->street << "\n" << this->city << ", " << this->state << ", " << this->zipcode << "\n" << endl;
}


//create a main function to prompt user
int main() {
	// create variables for temp information
	string name;
	string street_number;
	string street;
	string city;
	string state;
	string zipcode;
	string user_choice;

	//create a map for users
	map<string, person*> people;


	do{
		cout << "1: Enter a new entry\n2: Search for a name\nQ: quit\n\nChoice: ";
		cin >> user_choice;
		if (user_choice == "1") {
			cout << "Enter the person's name: ";
			cin >> name;
			cout << "Enter the street number: ";
			cin >> street_number;
			cout << "Enter the street name: ";
			cin >> street;
			cout << "Enter the City: ";
			cin >> city;
			cout << "Enter the state: ";
			cin >> state;
			cout << "Enter zipcode: ";
			cin >> zipcode;

			person *persons;
			persons = new person(name);
			//set the appropriate values
			persons->set_values(street_number, street, city, state, zipcode);

			//insert into map
			people[name] = persons;
			
		}
		if (user_choice == "2") {
			string search_name;
			cout << "Enter the name of the person you are searching for: ";
			cin >> search_name;
			//check if that name is in the table already
			map<string, person* > ::iterator iter = people.find(search_name);
			if (iter != people.end()) {
				iter->second->printRecord();
			}
			else {
				cout << "That person is not in the records" << endl;
			}
		}

	} while ((user_choice != "q") && user_choice != "Q");
}