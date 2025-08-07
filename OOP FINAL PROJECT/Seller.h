#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include"User.h"
#include"Product.h"
#include"Order.h"
class order;
class Seller : public user {
private:
	vector<product*> productList;
	vector<order*> receivedOrders;

public:
	Seller();
	void input() override;
	void addProduct();
	void updateProduct(const string& pID, vector<product*> seepending);
	void deleteProduct(const string& pID, vector<product*> products);
	void viewOrders(vector <order*> allorder);

	// Required by Admin
	string getUserID()
	{
		return (user::getUserID());
	}
	vector<product*> getProducts() const;
};