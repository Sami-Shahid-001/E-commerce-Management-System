#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include "user.h"
#include "product.h"
#include "order.h"
#include "buyer.h"
#include"Authentation.h"
using namespace std;

class userAuthentication;
class admin : public user {
    vector<product*> pendingproduct;
    vector<order*> allorder;

public:
    admin();
    void input() override;
    void displayUser(userAuthentication& authUser);
    void addpendingprod(product* prod);


    void approveproduct(vector<product*>& pendingProducts, vector<product*>& allProducts);
    void viewPendingProduct(vector<product*> pendingproduct);
    void addorder(order* ord);
    void generatesalereport();
    void mostavticebuyer(vector<buyer*> buyers);
    vector<product*> filterproduct(vector<product*> allproducts, string category, double minprice, double maxprice);
};