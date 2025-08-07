#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include"Product.h"



class BookProduct :public product
{
	string author;
	string publisher;
public:

	BookProduct();
	void input() override;
	void display() const override;
	void applyDiscount(double percentage) override;

	string getauthor() const;
	string getpublisher() const;
};