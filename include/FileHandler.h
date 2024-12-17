#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "User.h"
#include "LinkedList.h"
// #include "AvlBst.h"
using namespace std;

class Item;

class FileHandler {
private:
    static LinkedList<User> Users;  // Static LinkedList to store users
    // static AVLTree<User> allUsers;  // Static LinkedList to store users
      static LinkedList<Item> Items;  // Static LinkedList to store items
      static AVLTree<Item> allItems;  // Static LinkedList to store items
public:
    // Static functions
    static void loadUsersFromFile(const string& fileName);
    static void saveUsersToFile(const string& fileName);
    static User* authenticateUser();
    // static AVLTree<User> getAllUsers();
    static LinkedList<User> getUsers();

    static void loadItemsFromFile(const string& fileName);
    static void saveItemsToFile(const string& fileName);
    static void saveItemsToFileRec(ofstream& file, Node<Item>* node);

    // static LinkedList<Item>& getAllItems();
    static AVLTree<Item>& getAllItems();
    static LinkedList<Item> getItems();
};

#endif
