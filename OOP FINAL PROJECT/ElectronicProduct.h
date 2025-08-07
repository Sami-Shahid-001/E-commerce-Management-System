#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include"Product.h"
using namespace std;


class ElectronicProduct : public product
{
	string brand;
	int warrantymonths;
public:
	ElectronicProduct();
	void input() override;
	void display() const override; 
	void applyDiscount(double percentage) override;
};