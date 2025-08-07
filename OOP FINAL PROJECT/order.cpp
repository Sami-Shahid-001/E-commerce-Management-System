
#include "order.h"
#include "Color.h"
using namespace std;

order::order() : orderID(" "), date(" "), totalamount(0), status(" "), buyerr(nullptr) {}

void order::input(buyer* buy) {
    buyerr = buy;
    setColor(11);
    cout << "					ENTER ORDER DATA	\n";
    setColor(7);
    setColor(14);
    cout << "Enter OrderID: ";
    setColor(7);
    cin >> orderID;
    setColor(14);
    cout << "\nEnter Date (DD-MM-YYYY): ";
    setColor(7);
    cin >> date;
    status = "Peding"; // as order is input now, just added in the cart
}

void order::addproduct(product* pro) {
    productlist.push_back(pro);
}

void order::calculatetotal() {
    double totalamount = 0.0;
    for (auto it = productlist.begin(); it != productlist.end(); it++)
        totalamount += (*it)->getPrice();
}

void order::updatestatus(const string& newstatus) {
    setColor(14);
    cout << "Status updated from " << status << " to " << newstatus << endl;
    setColor(7);
    status = newstatus;
}

void order::displayOrder() const {
    setColor(11);
    cout << "\n                   ORDER DATA\n\n";
    setColor(7);
    cout << "Order ID: " << orderID << " | Data: " << date << " | Status: " << status
        << " | Total amount: " << totalamount << endl << endl;

    if (productlist.empty()) {
        setColor(12);
        cout << "No products in the order list\n";
        setColor(7);
    }
    else {
        setColor(11);
        cout << "\n                   PRODUCTS IN ORDER\n";
        setColor(7);
        for (auto it = productlist.begin(); it != productlist.end(); it++) {
            (*it)->display();
        }
        if (buyerr) {
            setColor(11);
            cout << "\n                   BUYER INFO\n";
            setColor(7);
            buyerr->displayInfo();
        }
    }
}

vector<product*> order::getproductlist() const {
    return productlist;
}

double order::getamount() const {
    return totalamount;
}

buyer* order::getbuyer() const {
    return buyerr;
}
