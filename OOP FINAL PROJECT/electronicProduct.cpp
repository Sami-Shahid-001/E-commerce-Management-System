

#include"ElectronicProduct.h"
#include "Color.h"
using namespace std;

ElectronicProduct::ElectronicProduct()
{
	brand = " ";
	warrantymonths = 0;
}

void ElectronicProduct::input()
{
	product::input();
	setColor(14);
	cout << "Enter Brand Name: ";
	setColor(7);
	cin >> brand;
	setColor(14);
	cout << "\nEnter warranty (in months): ";
	setColor(7);
	cin >> warrantymonths;
}

void ElectronicProduct::display() const
{
	product::display();
	setColor(10);
	cout << " | Brand name: " << brand;
	setColor(7);
	cout << " | Warranty: " << warrantymonths << endl;
}

void ElectronicProduct::applyDiscount(double percentage)
{
	if (percentage > 20) percentage = 20;
	product::applyDiscount(percentage);
}
