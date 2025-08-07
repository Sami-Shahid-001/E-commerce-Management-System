#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include"Product.h"
using namespace std;


class ClothingProduct : public product
{
	string size;
	string material;
public:
	ClothingProduct();
	void input() override;
	void display() const override;
	void applyDiscount(double percentage) override;

	string getsize() const;
	string getmaterial() const;
};
