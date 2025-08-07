//#include"Product.h"
//
//using namespace std;
//
//product::product() : productID(" "), name(" "), category(" "), price(0.0), quantity(0), sellerID(" ") {}
//
//void product::input() {
//	cout << "					ENTER PRODUCT DATA\n";
//	cout << "Enter ProductID: ";
//	cin >> productID;
//	cout << "\nEnter Product Name: ";
//	cin >> name;
//	cout << "\nEnter Product Category: ";
//	cin >> category;
//	cout << "\nEnter product price: ";
//	cin >> price;
//	while (price < 0) {
//		cout << "Price should be positive!\n";
//		price = 0.0;
//		cout << "Enter Price Again: ";
//		cin >> price;
//	}
//	cin.ignore();
//	cout << "\nEnter Product Quantity: ";
//	cin >> quantity;
//	cout << "\nEnter seller ID: ";
//	cin >> sellerID;
//}
//
//void product::display() const {
//	cout << endl<<"ID: " << productID << " | " << "Name: " << name << " | "
//		<< "Category: " << category << " | Price: " << price
//		<< " | Quantity: " << quantity << " | SellerID: " << sellerID;
//}
//
//void product::applyDiscount(double penctg) {
//	price -= price * (penctg / 100);
//	cout << penctg << "% discount, ";
//	cout << "Price updated...\n";
//}
//
//bool product::isAvailable() const {
//	return quantity > 0;
//}
//
//string product::getName() const {
//	return name;
//}
//
//double product::getPrice()const {
//	return price;
//}
//
//string product::getCategory()const {
//	return category;
//}
//
//string product::getProductID()const {
//	return productID;
//}

#include"Product.h"
#include "Color.h"

using namespace std;

product::product() : productID(" "), name(" "), category(" "), price(0.0), quantity(0), sellerID(" ") {}

void product::input() {
	setColor(11);
	cout << "					ENTER PRODUCT DATA\n";
	setColor(7);
	setColor(14);
	cout << "Enter ProductID: ";
	setColor(7);
	cin >> productID;
	setColor(14);
	cout << "\nEnter Product Name: ";
	setColor(7);
	cin >> name;
	setColor(14);
	cout << "\nEnter Product Category: ";
	setColor(7);
	cin >> category;
	setColor(14);
	cout << "\nEnter product price: ";
	setColor(7);
	cin >> price;
	while (price < 0) {
		setColor(12);
		cout << "Price should be positive!\n";
		setColor(14);
		cout << "Enter Price Again: ";
		setColor(7);
		cin >> price;
	}
	cin.ignore();
	setColor(14);
	cout << "\nEnter Product Quantity: ";
	setColor(7);
	cin >> quantity;
	setColor(14);
	cout << "\nEnter seller ID: ";
	setColor(7);
	cin >> sellerID;
}

void product::display() const {
	setColor(10);
	cout << endl << "ID: " << productID;
	setColor(7);
	cout << " | Name: " << name;
	cout << " | Category: " << category;
	setColor(14);
	cout << " | Price: " << price;
	setColor(7);
	cout << " | Quantity: " << quantity;
	cout << " | SellerID: " << sellerID;
}

void product::applyDiscount(double penctg) {
	price -= price * (penctg / 100);
	setColor(10);
	cout << penctg << "% discount, ";
	cout << "Price updated...\n";
	setColor(7);
}

bool product::isAvailable() const {
	return quantity > 0;
}

string product::getName() const {
	return name;
}

double product::getPrice() const {
	return price;
}

string product::getCategory() const {
	return category;
}

string product::getProductID() const {
	return productID;
}

void product::setQuantity(int quan)  {
	 quantity = quan;
}

int product::getquantity() {
	return quantity;
}
