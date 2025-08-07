#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include"Product.h"
#include"Order.h"
#include"User.h"
#include"Buyer.h"
#include<fstream>
#include"admin.h"
using namespace std;


class userAuthentication
{
	user* currentUser;
	vector<user*> registereduser;
public:
	userAuthentication();
	void registeredUser(user* user);
	user* login(const string& email, const string& password);
	void logout();
	void loadfromUser(const string& filename);
	void savetofile(const string& filename);
	bool userExist(const string& email);
	user* getcurrentuser();
	vector<user*> getalluser();

};