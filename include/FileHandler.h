#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "User.h"
#include "LinkedList.h"
#include "Bid.h"
#include <Stack>
#include <map>
#include <queue>

// #include "AvlBst.h"
using namespace std;

class Item;

class FileHandler {
private:
      static LinkedList<User> Users;  // Static LinkedList to store users
      static AVLTree<User> allUsers;  // Static LinkedList to store users
      static LinkedList<Item> Items;  // Static LinkedList to store items
      static AVLTree<Item> allItems;  // Static LinkedList to store items
        static map<int, stack<Bid>> bidHistoryMap; // Static stack to store bid history
        static map<int, stack<Bid>> bidderHistoryMap; // To store bid history by bidderId // Static stack to store bid history
        static queue<Item> auctionQueue; // Static stack to store bid history
public:
    // Static functions
    static void loadUsersFromFile(const string& fileName);
    static void saveUsersToFile(const string& fileName);
    static User* authenticateUser();
    static LinkedList<User> getUsers();

    static void loadItemsFromFile(const string& fileName);
    static void saveItemsToFile(const string& fileName);
    static void saveItemsToFileRec(ofstream& file, Node<Item>* node);
    static void loadBidHistory(const string& filename);
    static void saveBidHistory(const string& filename);
    static void addBidToItemHistory(const Bid& bid);
    static void saveUsersToFileRec(ofstream& file, Node<User>* node);
    static stack<Bid>& getBidHistoryForItem(int itemId);
    static void registerUser(const string& role);
    static stack<Bid>& getBidHistoryForBidder(int bidderId);
    static AVLTree<Item>& getAllItems();
    static AVLTree<User>& getAllUsers();
    static LinkedList<Item> getItems();
    static Item getAuctionQueue();
};

#endif
