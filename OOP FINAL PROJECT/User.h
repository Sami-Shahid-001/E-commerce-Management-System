#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
class user {
    string userID;
    string name;
    string email;
    string password;

public:
    user();
    virtual void input();
    virtual void displayInfo() const;
    string getemail();
    string getpassword();
    string getUserID();
    string getname();
    void setUserData(const string& id, const string& name, const string& email, const string& password);
    void checkgmail(string& gmail);

    ~user();
};
