#include "admin.h"
#include "color.h"
using namespace std;

admin::admin() {}

void admin::input() {
    user::input();
}

void admin::displayUser(userAuthentication& authUser) {

    vector<user*> allusers = authUser.getalluser();

    if (allusers.empty())
    {
        setColor(12);
        cout << "No User Exist\n";
        setColor(7);
    }
    else
    {
        setColor(11);
        cout << "\n					DISPLAY USER DATA\n\n";
        setColor(7);
        for (int i = 0; i < allusers.size(); i++) {
            allusers[i]->displayInfo();
        }
        cout << endl;
    }
}

void admin::addpendingprod(product* prod) {
    pendingproduct.push_back(prod);
    setColor(10);
    cout << "The Product is Added in Pending List by Admin\n";
    setColor(7);
}

void admin::approveproduct(vector<product*>& pendingProducts, vector<product*>& allProducts) {
    string productID;
    setColor(14);
    cout << "Enter product ID to approve: ";
    setColor(7);
    cin >> productID;

    for (auto it = pendingProducts.begin(); it != pendingProducts.end(); ++it) {
        if ((*it)->getProductID() == productID) {
            allProducts.push_back(*it);
            pendingProducts.erase(it);
            setColor(10);
            cout << "Product approved successfully!\n";
            setColor(7);
            return;
        }
    }
    setColor(12);
    cout << "Product not found in pending list.\n";
    setColor(7);
}

void admin::viewPendingProduct(vector<product*> pendproduct) {
    if (pendproduct.empty()) {
        setColor(12);
        cout << "\nNo Product is Available for pending\n";
        setColor(7);
    }
    else
    {
        setColor(11);
        cout << "					PENDING PRODUCT\n";
        setColor(7);
        for (auto prod = pendproduct.begin(); prod != pendproduct.end(); prod++)
            (*prod)->display();
    }
}

void admin::addorder(order* ord) {
    allorder.push_back(ord);
}

void admin::generatesalereport() {
    setColor(11);
    cout << "					ORDER REPORT\n";
    setColor(7);
    for (auto it = allorder.begin(); it != allorder.end(); it++) {
        for (auto p = pendingproduct.begin(); p != pendingproduct.end(); p++) {
            cout << "Name: " << (*p)->getName() << " | Price: " << (*p)->getPrice() << endl;
        }
    }
}

void admin::mostavticebuyer(vector<buyer*> buyers) {
    double totalrevenew = 0;
    for (auto order = allorder.begin(); order != allorder.end(); order++) {
        totalrevenew += (*order)->getamount();
    }

    setColor(11);
    cout << "					ADMIN DASHBOARD\n";
    setColor(7);
    cout << "Total Revenew: " << totalrevenew << endl;

    buyer* activebuyer = nullptr;
    size_t maxorder = 0;

    for (auto buy = buyers.begin(); buy != buyers.end(); buy++) {
        auto ordercount = (*buy)->getOrders().size();
        if (ordercount > maxorder)
        {
            maxorder = ordercount;
            activebuyer = (*buy);
        }
    }

    if (activebuyer)
    {
        setColor(10);
        cout << "Most Active Buyer: ";
        setColor(7);
        activebuyer->displayInfo();
        cout << endl;
        cout << "Total order placed: " << maxorder << endl;
    }
}

vector<product*> admin::filterproduct(vector<product*> allproducts, string category, double minprice, double maxprice)
{
    vector<product*> finalproduct;
    for (auto product = allproducts.begin(); product != allproducts.end(); product++)
    {
        if (((*product)->getCategory() == category) && ((*product)->getPrice() <= maxprice) && ((*product)->getPrice() >= minprice))
        {
            finalproduct.push_back(*product);
        }
    }
    return finalproduct;
}
