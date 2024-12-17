#ifndef USER_H
#define USER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "LinkedList.h"  // Assuming LinkedList is defined in this file
#include "AvlBst.h"
#include "Item.h"

// class Item;

using namespace std;

class User {
private:
    int userId;
    string username;
    string password;
    string role;  // Ensure this is a non-const string


public:
    // Constructors
    User();
    User(int id, const string& uname, const string& pwd, const string& role);

    // Getters
    int getUserId() const;
    string getUsername() const;
    string getPassword() const;
    string getRole() const;

    // Setters
    void setUserId(int id);
    void setUsername(const string& uname);
    void setPassword(const string& pwd);
    void setRole(const string& role);

    // Utility Functions
    virtual void getMenu();



    static User* authenticateUser();
    static bool checkUsernameOrIdAleadyExist(const string& username, const string& id);
    // static void registerUser(const string& role);

    // Static functions
    static void loadUsersFromFile(const string& fileName); // Load users at the start
    static void saveUsersToFile(const string& fileName);  // Save users before exiting
    // static LinkedList<User> getAllUsers();  // Display all users

    void displayUserDetails() const;
    void registerUser(const string& role);

    friend ostream& operator<<(ostream& , const User& );
    friend istream& operator>>(istream& , User& );

    // overloaad <,>,== operators
    bool operator<(const User& user) const;
    bool operator>(const User& user) const;
    bool operator==(const User& user) const;
    bool operator!=(const User& user) const;
    bool operator<=(const User& user) const;
    bool operator>=(const User& user) const;
    
};

// Derived Classes
class Seller: public User {
    AVLTree<Item> items; // AVL tree to store item ids

public:

    //copy constructor
    Seller(const User& user);

    void getMenu() override;

    void viewActiveAuctions();
    void createNewAuction();
    void viewBids();
    void endAuction();

    void getItemsOfUser();
    void getItemofUserRec(Node<Item>* root, int id) ; 
};

class Buyer: public User {
public:
    //copy constructor
    Buyer(const User& user);
    void getMenu() override;


    //Utitiles Functions
    void viewAllItems();
    void searchItem();
    void placeBid();
    void viewBiddingHistory();
    void getListedItemRec(Node<Item> * );

};

class Admin: public User {
public:
    //copy constructor
    Admin(const User& user);
    void getMenu() override;
    void manageUserMenu();

      // Manage User Menu

    // View All Users
    void viewAllUsers();

    // Add New User
    void addNewUser();

    // Edit User Detail

    // Delete User
    void deleteUser();

    // View User Bidding History
    void viewUserBiddingHistory();

    // Manage Items Menu
    void manageItemMenu();

    // View All Items
    void viewAllItems();

    // Add New Item
    void addNewItem();

    


    // Delete Item
    void deleteItem();

    // View Item Bidding History
    void viewItemBiddingHistory();

    void startAuction();



};

#endif // USER_H
