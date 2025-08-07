
#include "User.h"
#include "Color.h"
using namespace std;

user::user() : userID(" "), name(" "), email(" "), password(" ") {}

void user::checkgmail(string& email)
{
	char target[] = "@gmail.com";
	bool found = false;

	for (int i = 0; email[i] != '\0'; i++)
	{
		if (email[i] == target[i])
		{
			found = true;
		}
	}

	if (!found)
	{
		setColor(4);
		cout << "Enter the gmail again\n";
		setColor(7);
		getline(cin, email);
		checkgmail(email);
	}
	else
	{
		cout << "Gmail entered successfully\n";
	}
}

void user::input() {
	setColor(7);
	cout << "					ENTER THE USER DATA\n";
	cin.ignore();
	setColor(14);
	cout << "Enter ID: ";
	setColor(7);
	getline(cin, userID);
	setColor(14);
	cout << "\nEnter Name: ";
	setColor(7);
	getline(cin, name);
	setColor(14);
	cout << "\nEnter Email Address: ";
	setColor(7);
	getline(cin, email);
	setColor(14);
	checkgmail(email);
	setColor(14);
	cout << "\nEnter Password: ";
	setColor(7);
	getline(cin, password);
	while (password.length() < 8) {
		setColor(12);
		cout << "Password should be 8 characters! \n";
		setColor(14);
		cout << "Please Enter Password Again: ";
		setColor(7);
		getline(cin, password);
	}
}

// Display method
void user::displayInfo() const {
    setColor(10);
    cout << "\nUserID: " << userID;
    cout << " | Name: " << name;
    cout << " | Email: " << email;
    cout << " | Password: " << password << endl;
    setColor(7);
}

string user::getemail() {
    return email;
}

string user::getpassword() {
    return password;
}

string user::getUserID() {
    return userID;
}

string user::getname() {
    return name;
}

void user::setUserData(const string& id, const string& n, const string& e, const string& p) {
	userID = id;
	this->name = n;
	this->email = e;
	this->password = p;
}


user::~user() {}
