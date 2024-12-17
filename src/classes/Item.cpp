// #include "../../include/Item.h"

// Item::Item() :sellerId(0), itemId(0), name(""), description(""), price(0.0), isSold(false) {}

// Item::Item(int id, const string& name, const string& description, double price, bool isSold)
//     : itemId(id), name(name), description(description), price(price), isSold(isSold) {}

// int Item::getItemId() const {
//     return itemId;
// }

// int Item::getsellerId() const {
//     return sellerId;
// }

// string Item::getName() const {
//     return name;
// }

// string Item::getDescription() const {
//     return description;
// }

// double Item::getPrice() const {
//     return price;
// }

// bool Item::getIsSold() const {
//     return isSold;
// }

// void Item::setItemId(int id) {
//     itemId = id;
// }

// void Item::setName(const string& name) {
//     this->name = name;
// }

// void Item::setDescription(const string& description) {
//     this->description = description;
// }

// void Item::setPrice(double price) {
//     this->price = price;
// }

// void Item::setIsSold(bool sold) {
//     isSold = sold;
// }

// void Item::displayItem() const {
//     cout << "Item ID: " << itemId << endl;
//     cout << "Name: " << name << endl;
//     cout << "Description: " << description << endl;
//     cout << "Price: $" << price << endl;
//     cout << "Status: " << (isSold ? "Sold" : "Available") << endl;
// }

// void Item::markAsSold() {
//     isSold = true;
// }

// // Function to display items of a seller
// // void Item::displayItemsOfSeller(AVLTree<Item>& items,int id) {
// //     // In-order traversal of the AVL tree
// //     displayItemsOfSellerRec(items.getRoot(), id);
// // }

// //recusive function to display items of a seller
// // void Item::displayItemsOfSellerRec(Node<Item>* root, int id) {
// //     if (root != nullptr) {
// //         displayItemsOfSellerRec(root->left, id);
// //         if (root->key.getsellerId() == id) {
// //             cout<<root->key;
// //         }
// //         displayItemsOfSellerRec(root->right, id);
// //     }
// // }

// // Overload the output operator (<<)
// ostream& operator<<(ostream& os, const Item& item) {
//     os << "Item ID: " << item.itemId << "\n";
//     os << "Name: " << item.name << "\n";
//     os << "Description: " << item.description << "\n";
//     os << "Price: $" << item.price << "\n";
//     os << "Status: " << (item.isSold ? "Sold" : "Available") << "\n";
//     return os;
// }

// // Overload the input operator (>>)
// istream& operator>>(istream& is, Item& item) {
//     is >> item.itemId;
//     is.ignore();  // Ignore the newline character
//     getline(is, item.name);
//     getline(is, item.description);
//     is >> item.price;
//     is >> item.isSold;
//     return is;
// }