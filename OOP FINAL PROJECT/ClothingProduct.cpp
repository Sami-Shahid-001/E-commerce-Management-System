

#include"ClothingProduct.h"
#include "Color.h"
using namespace std;

ClothingProduct::ClothingProduct()
{
	size = " ";
	material = " ";
}

void ClothingProduct::input()
{
	product::input();
	cin.ignore();
	setColor(14);
	cout << "\nEnter Cloth size: ";
	setColor(7);
	cin >> size;
	setColor(14);
	cout << "\nEnter material: ";
	setColor(7);
	cin >> material;
}

void ClothingProduct::display() const
{
	product::display();
	setColor(10);
	cout << " | Size: " << size;
	setColor(7);
	cout << " | Material: " << material << endl;
}

void ClothingProduct::applyDiscount(double percentage)
{
	if (percentage > 30) percentage = 30;
	product::applyDiscount(percentage);
}

string ClothingProduct::getsize() const
{
	return size;
}

string ClothingProduct::getmaterial() const
{
	return material;
}
