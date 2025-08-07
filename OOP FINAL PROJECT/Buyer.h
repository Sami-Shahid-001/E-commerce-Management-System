#pragma once
#include"Order.h"
#include"User.h"
#include"Product.h"
#include"Cart.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
class order;


class buyer : public user {
private:
	Cart<product> buyercart;
	vector<order*> orderHistory;

public:
	buyer(){}
	void displayInfo() const override;
	void input() override;
	void browseProducts(vector<product*>& products);
	void addToCart(product* product);
	void removeFromCartp(product* product);
	void checkout(vector<order*>& allorders,vector<product*>& allproducts);
	void viewOrders();
	void viewCart();


	// Required by Admin
	vector<order*> getOrders();

};
