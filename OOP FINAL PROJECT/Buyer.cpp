#include"Buyer.h"
#include "Color.h"
using namespace std;

void buyer::displayInfo() const
{
	user::displayInfo();
}

void buyer::input()
{
	user::input();
}

void buyer::browseProducts(vector<product*>& products)
{
	if (products.empty())
	{
		setColor(12);
		cout << "\nNo product yet available!\n";
		setColor(7);
	}
	else
	{
		setColor(11);
		cout << "					AVAILABLE PRODUCTS\n";
		setColor(7);
		for (int i = 0; i < products.size(); i++)
		{
			cout << "Product: " << i + 1 << endl;
			products[i]->display();
		}
	}
}

void buyer::addToCart(product* pro)
{
	if (pro->isAvailable())
	{
		buyercart += pro;
		setColor(10);
		cout << "Product is added to cart\n";
		setColor(7);
	}
	else
	{
		setColor(12);
		cout << "\nThe product is Out of Stock\n";
		setColor(7);
	}
}

void buyer::removeFromCartp(product* p)
{
	if (p->isAvailable())
	{
		buyercart -= p;
		setColor(10);
		cout << "The Product is removed from the cart!\n";
		setColor(7);
	}
	else
	{
		setColor(12);
		cout << "\nThis product is not available.\n";
		setColor(7);
	}
}

void buyer::viewCart()
{
	setColor(11);
	cout << "					YOUR CART\n";
	setColor(7);
	cout << buyercart << endl;
	cout << "Total cost: " << buyercart.calculateTotal();
}

void buyer::checkout(vector<order*>& allorders, vector<product*>& allproducts) {

	if (buyercart.isEmpty())
	{
		string choose;
		setColor(12);
		cout << "Your Cart is empty!\n";
		setColor(14);
		cout << "Wanna go to shopping centre again?  (yes/no): ";
		setColor(7);
		cin >> choose;
		if (choose == "yes" || choose == "Yes" || choose == "Yes") {
			browseProducts(allproducts);
		}
		else
		{
			setColor(12);
			cout << "Please add items in your cart first\n";
			setColor(7);
		}
	}
	else
	{
		order* neworder = new order();
		neworder->input(this);

		//transfer cart product to order
		auto cartItems = buyercart.getItems();  // Make a local copy
		for (auto it = cartItems.begin(); it != cartItems.end(); ++it) {
			neworder->addproduct(*it);


			if ((*it)->isAvailable()) {
				int updatedQty = ((*it)->getquantity() - 1);
				(*it)->setQuantity(updatedQty);
			}
		}

			neworder->calculatetotal();
			orderHistory.push_back(neworder);
			allorders.push_back(neworder);

			setColor(10);
			cout << "\nYour Order Placed Successfully\n\n";
			setColor(7);
			neworder->displayOrder();
			buyercart.clearCart();
		}
	}



void buyer::viewOrders()
{
	setColor(11);
	cout << "					ORDER HISTORY\n\n";
	setColor(7);
	if (orderHistory.empty())
	{
		setColor(12);
		cout << "You have not placed any order yet.\n";
		setColor(7);
		return;
	}
	else
	{
		for (auto it = orderHistory.begin(); it != orderHistory.end(); it++)
		{
			(*it)->displayOrder();
			cout << "					---------------       \n";
		}
	}
}

vector<order*> buyer::getOrders()
{
	return orderHistory;
}
