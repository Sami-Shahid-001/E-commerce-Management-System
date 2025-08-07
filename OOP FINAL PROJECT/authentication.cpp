#include"Authentation.h"
#include"Color.h"
using namespace std;

userAuthentication::userAuthentication() : currentUser(nullptr) {}

void userAuthentication::registeredUser(user* user)
{
	if (!userExist(user->getemail()))
	{
		registereduser.push_back(user);
		setColor(10);
		cout << "User Register Successfully\n";
		setColor(7);
	}
	else
	{
		setColor(12);
		cout << "This User already exists\n";
		setColor(7);
	}
}

bool userAuthentication::userExist(const string& email)
{
	for (auto it = registereduser.begin(); it != registereduser.end(); it++)
	{
		if ((*it)->getemail() == email)
			return true;
	}
	return false;
}

user* userAuthentication::login(const string& email, const string& password)
{
	for (auto it = registereduser.begin(); it != registereduser.end(); it++)
	{
		if ((*it)->getemail() == email && (*it)->getpassword() == password)
		{
			currentUser = (*it);
			setColor(10);
			cout << "Login successful! Welcome: " << (*it)->getname() << endl;
			setColor(7);
			return currentUser;
		}
	}
	setColor(12);
	cout << "Invalid Password or Email\n";
	setColor(7);
	return nullptr;
}

void userAuthentication::logout()
{
	if (currentUser)
	{
		setColor(14);
		cout << "User: " << currentUser->getname() << " logged out.\n";
		cout << "Thanks for using this application\n";
		setColor(7);
		currentUser = nullptr;
	}
}

user* userAuthentication::getcurrentuser()
{
	return currentUser;
}

vector<user*> userAuthentication::getalluser()
{
	return registereduser;
}


void userAuthentication::savetofile(const string& filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cout << "Error: Could not open file for saving.\n";
        return;
    }

    for (auto user : registereduser) {
        // Save: Type, ID, Name, Email, Password
        if (dynamic_cast<admin*>(user))
            outFile << "Admin ";
        else if (dynamic_cast<Seller*>(user))
            outFile << "Seller ";
        else if (dynamic_cast<buyer*>(user))
            outFile << "Buyer ";

        outFile << user->getUserID() << " "
            << user->getname() << " "
            << user->getemail() << " "
            << user->getpassword() << "\n";
    }

    outFile.close();
    cout << "Users saved successfully to " << filename << "\n";
}

void userAuthentication::loadfromUser(const string& filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cout << "No existing user file found. Starting fresh.\n";
        return;
    }

    registereduser.clear(); // clear previous data

    string type, id, name, email, password;

    while (inFile >> type >> id >> name >> email >> password) {
        user* newUser = nullptr;

        if (type == "Admin")
            newUser = new admin();
        else if (type == "Seller")
            newUser = new Seller();
        else if (type == "Buyer")
            newUser = new buyer();

        if (newUser) {
            // Directly set private members (optional: add setters or update input logic)
            // Or, alternatively, modify constructors to accept values
            // Here assuming you have parameterized constructors, if not, create setters
            newUser->setUserData(id, name, email, password);
            registereduser.push_back(newUser);
        }
    }

    inFile.close();
    cout << "Users loaded successfully from " << filename << "\n";
}