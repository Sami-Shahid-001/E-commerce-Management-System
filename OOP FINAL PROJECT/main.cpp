#include <iostream>
#include <vector>
#include <string>
#include "admin.h"
#include "seller.h"
#include "buyer.h"
#include "product.h"
#include "ElectronicProduct.h"
#include "ClothingProduct.h"
#include "BookProduct.h"
#include "order.h"
#include "Authentation.h"
#include "color.h"

int main() {
    userAuthentication auth;
    vector<product*> allProducts;
    vector<order*> allOrders;
    vector<buyer*> allBuyers;
    vector<Seller*> allSellers;
    vector<product*> pendingProduct;

    // Load users at startup
    auth.loadfromUser("users.txt");

    int choice;
    do {
        setColor(12);
        cout << "\n                                             E-COMMERCE MANAGEMENT SYSTEM\n";
        setColor(14);
        cout << "1. Register User\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        setColor(15);
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int type;
            setColor(14);
            cout << "\nSelect User Type:\n1. Admin\n2. Seller\n3. Buyer\n";
            setColor(15);
            cout << "Enter type: ";
            cin >> type;

            if (type == 1) {
                admin* a = new admin();
                a->input();
                auth.registeredUser(a);
            }
            else if (type == 2) {
                Seller* s = new Seller();
                s->input();
                allSellers.push_back(s);
                auth.registeredUser(s);
            }
            else if (type == 3) {
                buyer* b = new buyer();
                b->input();
                allBuyers.push_back(b);
                auth.registeredUser(b);
            }
            else {
                setColor(4);
                cout << "Invalid user type.\n";
                setColor(7);
            }
            break;
        }
        case 2: {
            string email, password;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Password: ";
            cin >> password;

            user* loggedIn = auth.login(email, password);
            if (!loggedIn) break;

            if (admin* a = dynamic_cast<admin*>(loggedIn)) {
                int adminChoice;
                do {
                    setColor(2);
                    cout << "\n             ADMIN MENU \n";
                    setColor(11);
                    cout << "1. Display Users\n";
                    cout << "2. View Pending Products\n";
                    cout << "3. Approve Product\n";
                    cout << "4. Generate Sale Report\n";
                    cout << "5. View Most Active Buyer\n";
                    cout << "6. Logout\n";
                    setColor(15);

                    cout << "Choice: ";
                    cin >> adminChoice;

                    switch (adminChoice) {
                    case 1:
                        a->displayUser(auth);
                        break;
                    case 2:
                        a->viewPendingProduct(pendingProduct);
                        break;
                    case 3:
                        a->approveproduct(pendingProduct, allProducts);
                        break;
                    case 4:
                        a->generatesalereport();
                        break;
                    case 5:
                        a->mostavticebuyer(allBuyers);
                        break;
                    case 6:
                        auth.logout();
                        break;
                    default:
                        setColor(4);
                        cout << "Invalid choice.\n";
                        setColor(7);
                    }
                } while (adminChoice != 6);
            }
            else if (Seller* s = dynamic_cast<Seller*>(loggedIn)) {
                int sellerChoice;
                do {
                    setColor(2);
                    cout << "\n=== SELLER MENU ===\n";
                    setColor(11);
                    cout << "1. Add Product\n";
                    cout << "2. Update Product\n";
                    cout << "3. Delete Product\n";
                    cout << "4. View Orders\n";
                    cout << "5. Logout\n";
                    setColor(15);

                    cout << "Choice: ";
                    cin >> sellerChoice;

                    switch (sellerChoice) {
                    case 1: {
                        int pType;
                        setColor(14);
                        cout << "                   Product Type\n1. Electronics\n2. Clothing\n3. Book\n";
                        setColor(15);
                        cout << "Enter Product Type: ";
                        cin >> pType;

                        product* p = nullptr;
                        if (pType == 1) p = new ElectronicProduct();
                        else if (pType == 2) p = new ClothingProduct();
                        else if (pType == 3) p = new BookProduct();
                        if (p) {
                            p->input();
                            pendingProduct.push_back(p);
                            cout << "Product added successfully! Waiting for admin approval.\n";
                        }
                        else {
                            setColor(4);
                            cout << "Invalid Product\n";
                            setColor(7);
                        }
                        break;
                    }
                    case 2: {
                        string pid;
                        setColor(15);
                        cout << "Enter Product ID to update: ";
                        cin >> pid;
                        s->updateProduct(pid, allProducts);
                        break;
                    }
                    case 3: {
                        string pid;
                        setColor(15);
                        cout << "Enter Product ID to delete: ";
                        cin >> pid;
                        s->deleteProduct(pid, allProducts);
                        break;
                    }
                    case 4:
                        s->viewOrders(allOrders);
                        break;
                    case 5:
                        auth.logout();
                        break;
                    default:
                        setColor(4);
                        cout << "Invalid choice.\n";
                        setColor(7);
                    }
                } while (sellerChoice != 5);
            }
            else if (buyer* b = dynamic_cast<buyer*>(loggedIn)) {
                int buyerChoice;
                do {
                    setColor(2);
                    cout << "\n=== BUYER MENU ===\n";
                    setColor(11);
                    cout << "1. Browse Products\n";
                    cout << "2. Add to Cart\n";
                    cout << "3. Remove from Cart\n";
                    cout << "4. View Cart\n";
                    cout << "5. Checkout\n";
                    cout << "6. View Orders\n";
                    cout << "7. Filter Product\n";
                    cout << "8. Logout\n";
                    setColor(15);

                    cout << "Choice: ";
                    cin >> buyerChoice;

                    switch (buyerChoice) {
                    case 1:
                        b->browseProducts(allProducts);
                        break;
                    case 2: {
                        string pid;
                        setColor(15);
                        cout << "Enter Product ID to add to cart: ";
                        cin >> pid;
                        for (auto product = allProducts.begin(); product != allProducts.end(); product++) {
                            if ((*product)->getProductID() == pid) {
                                b->addToCart(*product);
                                break;
                            }
                        }
                        break;
                    }
                    case 3: {
                        string pid;
                        setColor(15);
                        cout << "Enter Product ID to remove from cart: ";
                        cin >> pid;
                        for (auto product = allProducts.begin(); product != allProducts.end(); product++) {
                            if ((*product)->getProductID() == pid) {
                                b->removeFromCartp(*product);
                                break;
                            }
                        }
                        break;
                    }
                    case 4:
                        b->viewCart();
                        break;
                    case 5:
                        b->checkout(allOrders, allProducts);
                        break;
                    case 6:
                        b->viewOrders();
                        break;
                    case 7: {
                        string category;
                        double minPrice, maxPrice;
                        setColor(14);
                        cout << "Enter category to filter: ";
                        cin >> category;
                        cout << "Enter minimum price: ";
                        cin >> minPrice;
                        cout << "Enter maximum price: ";
                        cin >> maxPrice;

                        admin tempAdmin;
                        vector<product*> filtered = tempAdmin.filterproduct(allProducts, category, minPrice, maxPrice);

                        if (filtered.empty()) {
                            setColor(12);
                            cout << "No products found for the given filters.\n";
                            setColor(7);
                        }
                        else {
                            setColor(10);
                            cout << "\nFiltered Products:\n";
                            for (auto p : filtered) {
                                p->display();
                                cout << endl;
                            }
                            setColor(7);
                        }
                        break;
                    }
                    case 8:
                        auth.logout();
                        break;
                    default:
                        setColor(4);
                        cout << "Invalid choice.\n";
                        setColor(7);
                    }
                } while (buyerChoice != 8);
            }
            break;
        }
        case 3:
            auth.savetofile("users.txt");
            setColor(5);
            cout << "Exiting system...\n";
            break;

        default:
            setColor(4);
            cout << "Invalid choice. Try again.\n";
            setColor(7);
        }
    } while (choice != 3);

    return 0;
}
