#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<fstream>
using namespace std;


class product {
private:
	string productID;
	string name;
	string category;
	double price;
	int quantity;
	string sellerID;
		
public:
	product();
	virtual void input();
	virtual void display() const;
	virtual void applyDiscount(double percentage);
	bool isAvailable() const;

	// Getters
	string getName() const;
	double getPrice() const;
	string getCategory() const;
	string getProductID() const;
	void setQuantity(int quan);
	int getquantity();

};