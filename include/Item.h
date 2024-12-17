#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    int itemId;
    int sellerId;
    string name;
    string description;
    double price;
    bool isSold;
    bool listed;

public:
    // Constructors
    Item() : sellerId(0), itemId(0), name(""), description(""), price(0.0), isSold(false) ,listed(false){}
    Item(int id,int sellerId, const string& name, const string& description, double price, bool isSold , bool isListed = false)
        : itemId(id),sellerId(sellerId), name(name), description(description), price(price), isSold(isSold),listed(isListed) {}

    // Getter functions
    int getItemId() const { return itemId; }
    int getsellerId() const { return sellerId; }
    string getName() const { return name; }
    string getDescription() const { return description; }
    double getPrice() const { return price; }
    bool getIsSold() const { return isSold; }
    bool getIsListed() const { return listed; }

    // Setter functions
    void setItemId(int id) { itemId = id; }
    void setName(const string& name) { this->name = name; }
    void setDescription(const string& description) { this->description = description; }
    void setPrice(double price) { this->price = price; }
    void setIsSold(bool sold) { isSold = sold; }
    void setIsListed(bool listed) { this->listed = listed; }

    // Function to display item details
    void displayItem() const {
        cout << "Item ID: " << itemId << endl;
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Price: $" << price << endl;
        cout << "Status: " << (isSold ? "Sold" : "Available") << endl;
        cout << "Listed: " << (listed ? "Yes" : "No") << endl;
    }

    // Function to update item status as sold
    void markAsSold() { isSold = true; }

    // Overload the output operator (<<)
    friend ostream& operator<<(ostream& os, const Item& item) {
        os << "Item ID: " << item.itemId << "\n";
        os << "Name: " << item.name << "\n";
        os << "Description: " << item.description << "\n";
        os << "Price: $" << item.price << "\n";
        os << "Status: " << (item.isSold ? "Sold" : "Available") << "\n";
        os << "Listed: " << (item.listed ? "Yes" : "No") << "\n";
        return os;
    }

    // Overload the input operator (>>)
    friend istream& operator>>(istream& is, Item& item) {
        is >> item.itemId;
        is.ignore();  // Ignore the newline character
        getline(is, item.name);
        getline(is, item.description);
        is >> item.price;
        is >> item.isSold;
        return is;
    }
};

#endif
