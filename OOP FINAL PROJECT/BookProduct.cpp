#include "BookProduct.h"
#include "Color.h"
using namespace std;

BookProduct::BookProduct()
    : product(), author(" "), publisher(" ") {
}

void BookProduct::input() {
    product::input();

    setColor(14);
    cout << "\nEnter Author Name: ";
    setColor(7);
    cin.ignore();
    getline(cin, author);

    setColor(14);
    cout << "Enter Publisher Name: ";
    setColor(7);
    getline(cin, publisher);
}

void BookProduct::display() const
{
    product::display();
    setColor(10);
    cout << " | Author: " << author;
    setColor(7);
    cout << " | Publisher: " << publisher << "\n";
}

void BookProduct::applyDiscount(double percentage) {
    if (percentage > 20) percentage = 20;
    product::applyDiscount(percentage);
}

string BookProduct::getauthor() const {
    return author;
}

string BookProduct::getpublisher() const {
    return publisher;
}
