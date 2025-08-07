#pragma once
#include<iostream>
#include"Product.h"
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;




template<class T>
class Cart {
    vector<T*> items;

public:
    Cart<T>();

    void operator-=(T* p);
    void operator+=(T* p);
    template<class U>
    friend ostream& operator<<(ostream& out, const Cart<U>& obj);

    double calculateTotal() const;
    bool isEmpty() const;
    vector<T*> getItems() ;
    const vector<T*> getItems() const ;

    void clearCart();
};


template<class T>
Cart<T>::Cart() {}

template<class T>
void Cart<T>::operator-=(T* p) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == p) {
            items.erase(it);
            break;
        }
    }
}

template<class T>
void Cart<T>::operator+=(T* p) {
    items.push_back(p);
}

template<class U>
ostream& operator<<(ostream& out, const Cart<U>& obj) {
    if (obj.items.empty()) {
        out << "The cart is empty!\n";
    }
    else {
        for (auto it = obj.items.begin(); it != obj.items.end(); ++it)
        {
            (*it)->display();
        }
    }
    return out;
}

template<class T>
double Cart<T>::calculateTotal() const {
    double total = 0.0;
    for (auto it = items.begin(); it != items.end(); ++it) {
        total += (*it)->getPrice();
    }
    return total;
}

template<class T>
bool Cart<T>::isEmpty() const {
    return items.empty();
}

template<class T>
vector<T*> Cart<T>::getItems() {
    return items;
}

template<class T>
const vector<T*> Cart<T>::getItems() const {
    return items;

}

template<class T>
void Cart<T>::clearCart()
{
    items.clear();
}
