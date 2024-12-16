#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include "AvlBst.h"

using namespace std;

class Item {
private:
    int itemId;
    int sellerId;
    string name;
    string description;
    double price;
    bool isSold;

public:
    // Constructors
    Item();
    Item(int id, const string& name, const string& description, double price, bool isSold);

    // Getter functions
    int getItemId() const;
    int getsellerId() const;
    string getName() const;
    string getDescription() const;
    double getPrice() const;
    bool getIsSold() const;

    // Setter functions
    void setItemId(int id);
    void setName(const string& name);
    void setDescription(const string& description);
    void setPrice(double price);
    void setIsSold(bool sold);

    // Function to display item details
    void displayItem() const;

    // Function to update item status as sold
    void markAsSold();

    //static function to display items of a seller
    static void displayItemsOfSeller(AVLTree<Item>& items, int id);
    static void displayItemsOfSellerRec(Node<Item>* root, int id);

    // Overload the input and output operators
    friend ostream& operator<<(ostream& os, const Item& item);
    friend istream& operator>>(istream& is, Item& item);
};

#endif
