#pragma once
#include"Product.h"
#include"Buyer.h"
#include"Seller.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;


class Seller;
class buyer;

class order {
	string orderID;
	string date;
	double totalamount;
	string status;
	buyer* buyerr;                // has-a
	vector<product*> productlist; // has-a 
	vector<Seller*> seller;

public:
	order();
	void input(buyer* buy);
	void addproduct(product* pro);
	void calculatetotal();
	void updatestatus(const string& newstatus);
	void displayOrder() const;

	// Getters
	vector<product*> getproductlist() const;
	double getamount() const;
	buyer* getbuyer() const;
};
