//#include"Seller.h"
//using namespace std;
//
//Seller::Seller(){}
//
//void Seller::input()
//{
//	user::input();
//}
//
//void Seller::updateProduct(const string& pID,vector<product*> seepending)
//{
//	if (seepending.empty())
//	{
//		cout << "No product available\n";
//	}
//
//	else
//	{
//		for (auto it = seepending.begin(); it != seepending.end(); it++)
//		{
//			if ((*it)->getProductID() == pID)
//			{
//				cout << "Enter the Updated Product Details\n";
//				(*it)->input();
//				cout << "Product Update Successfully\n";
//			}
//		}
//	}
//
//}
//
//void Seller::deleteProduct(const string& pID, vector<product*> products)
//{
//	for (auto it = products.begin(); it != products.end(); it++)
//	{
//		if ((*it)->getProductID() == pID)
//		{
//			delete* it;
//			products.erase(it);
//			cout << "Product delete SuccessFully\n";
//		}
//	}
//}
//
//void Seller::addProduct()
//{
//	product* newproduct = new product();
//	newproduct->input();
//	productList.push_back(newproduct);
//	cout << "Product added succesfully!\n";
//}
//
//void Seller::viewOrders(vector<order*> allorder)
//{
//	if (allorder.empty())
//	{
//		cout << "No Order is Recieved by the Seller\n";
//	}
//
//	else
//	{
//		cout << "Orders received by Seller\n";
//		for (auto it = allorder.begin(); it != allorder.end(); it++)
//		{
//			(*it)->displayOrder();
//			cout << "      ------------      \n";
//
//		}
//	}
//}
// //// for admin conplete form
//vector<product*> Seller::getProducts() const
//{
//	return productList;
//}


#include"Seller.h"
#include "Color.h"
using namespace std;

Seller::Seller() {}

void Seller::input()
{
	user::input();
}

void Seller::updateProduct(const string& pID, vector<product*> seepending)
{
	if (seepending.empty())
	{
		setColor(12);
		cout << "No product available\n";
		setColor(7);
	}

	else
	{
		for (auto it = seepending.begin(); it != seepending.end(); it++)
		{
			if ((*it)->getProductID() == pID)
			{
				setColor(11);
				cout << "Enter the Updated Product Details\n";
				setColor(7);
				(*it)->input();
				setColor(10);
				cout << "Product Update Successfully\n";
				setColor(7);
			}
		}
	}

}

void Seller::deleteProduct(const string& pID, vector<product*> products)
{
	for (auto it = products.begin(); it != products.end(); it++)
	{
		if ((*it)->getProductID() == pID)
		{
			delete* it;
			products.erase(it);
			setColor(10);
			cout << "Product delete SuccessFully\n";
			setColor(7);
		}
	}
}

void Seller::addProduct()
{
	product* newproduct = new product();
	newproduct->input();
	productList.push_back(newproduct);
	setColor(10);
	cout << "Product added succesfully!\n";
	setColor(7);
}

void Seller::viewOrders(vector<order*> allorder)
{
	if (allorder.empty())
	{
		setColor(12);
		cout << "No Order is Recieved by the Seller\n";
		setColor(7);
	}

	else
	{
		setColor(11);
		cout << "Orders received by Seller\n";
		setColor(7);
		for (auto it = allorder.begin(); it != allorder.end(); it++)
		{
			(*it)->displayOrder();
			cout << "      ------------      \n";

		}
	}
}

vector<product*> Seller::getProducts() const
{
	return productList;
}
