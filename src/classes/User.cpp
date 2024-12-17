#include "../../include/AvlBst.h"
#include "../../include/LinkedList.h"
#include "../../include/User.h"
#include "../../include/FileHandler.h"
#include "../../include/Bid.h"
#include <sstream>
#include <string.h>
#include <conio.h>
#include <limits>

// Default Constructor
User::User() : userId(0), username(""), password(""), role("") {
}

// Parameterized Constructor
User::User(int id, const string &uname, const string &pwd, const string &role)
    : userId(id), username(uname), password(pwd), role(role) 
{
}

// Getters
int User::getUserId() const
{
    return userId;
}

string User::getUsername() const
{
    return username;
}

string User::getPassword() const
{
    return password;
}

string User::getRole() const
{
    return role;
}

// Setters
void User::setUserId(int id)
{
    userId = id;
}

void User::setUsername(const string &uname)
{
    username = uname;
}

void User::setPassword(const string &pwd)
{
    password = pwd;
}

void User::setRole(const string &role)
{
    this->role = role;
}

void User::getMenu() {};


// Function to check if a username or ID already exists
bool User::checkUsernameOrIdAleadyExist(const string &username, const string &id)
{
    ListNode<User> *current = FileHandler::getUsers().getHead();
    while (current != nullptr)
    {
        if (current->data.getUsername() == username || to_string(current->data.getUserId()) == id)
        {
            return true;
        }
        current = current->next;
    }

    return false;
}

// Function to register a user
void User::registerUser(const string &role)
{
    User user;
    bool check = false;
    int attempts = 3;
    do
    {

        cin >> user;
        user.setRole(role);
        // check if username or id already exist
        if (checkUsernameOrIdAleadyExist(user.getUsername(), to_string(user.getUserId())))
        {
            check = true;
            cout << "Username or ID already exists!" << endl;
            attempts--;
            cout << "Attempts left: " << attempts << endl;
        }
        else
        {
            check = false;
            FileHandler::getUsers().addListNode(user);
            // FileHandler::getAllUsers().insert(user);
            cout << "User registered successfully!" << endl;
            _getch();
            system("cls");
        }
    } while (check && attempts > 0);
}

// Over load input operator
istream &operator>>(istream &in, User &user)
{
    cout << "Enter User ID: ";
    in >> user.userId;
    cout << "Enter Username: ";
    in >> user.username;
    cout << "Enter Password: ";
    in >> user.password;
    cout << "Enter Role: ";
    in >> user.role;

    return in;
}

// Overload output operator
ostream &operator<<(ostream &out, const User &user)
{
    out << "User ID: " << user.userId << endl;
    out << "Username: " << user.username << endl;
    out << "Role: " << user.role << endl;
    return out;
}

// Overload < operator
bool User::operator<(const User &user) const
{
    return userId < user.userId;
}

// Overload > operator
bool User::operator>(const User &user) const
{
    return userId > user.userId;
}

// Overload == operator
bool User::operator==(const User &user) const
{
    return userId == user.userId;
}

// Overload != operator
bool User::operator!=(const User &user) const
{
    return userId != user.userId;
}

// Overload <= operator
bool User::operator<=(const User &user) const
{
    return userId <= user.userId;
}

// Overload >= operator
bool User::operator>=(const User &user) const
{
    return userId >= user.userId;
}



// Function to display user details
void User::displayUserDetails() const
{
    cout << "User ID: " << userId << endl;
    cout << "Username: " << username << endl;
    cout << "Role: " << role << endl;
}

// Implementation of Seller's getMenu function
void Seller::getMenu()
{
    int choice;
    do
    {
        // Display the menu for the Seller
        cout << "\n===== Seller Menu =====\n";
        cout << "1. View Active Auctions\n";
        cout << "2. Create New Auction\n";
        cout << "3. View Bids on Your Items\n";
        cout << "4. End Auction\n";
        cout << "5. Log Out\n";
        cout << "Enter your choice: ";

        // Get user input
        cin >> choice;

        // Handle invalid input
        if (cin.fail())
        {
            cin.clear();                                         // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore bad input
            cout << "Invalid choice! Please enter a valid option.\n";
            continue;
        }

        switch (choice)
        {
        case 1:{
            // View Active Auctions
            cout << "View Active Auctions\n";
            _getch();
            viewActiveAuctions();
            break;}
        case 2:{
            // Create New Auction
            // cout << "Create New Auction\n";
            // _getch();
            createNewAuction();
            break;}
        case 3:{
            // View Bids on Your Items
            cout << "View Bids on Your Items\n";
            _getch();
            // viewBids();
            break;}
        case 4:{
            // End Auction
            cout << "End Auction\n";
            _getch();
            // endAuction();
            break;}
        case 5:{
            // Log Out
            cout << "Logging out...\n";
            _getch();
            // cout << "Logging out...\n";
            break;}
        default:{
            cout << "Invalid choice! Please enter a valid option.\n";
            break;}
        }

    } while (choice != 5); // Repeat until the user logs out
}

// Function to view active auctions
void Seller::viewActiveAuctions()
{
    // Get all active items (those that are still up for auction)
    //TODO: maket get Item function
    // AVLTree<Item> activeItems = FileHandler::getAllItems(); // Assuming a function that loads all items
    
    cout << "\nActive Auctions:\n";

    items.inOrderTraversal();
    
}

// Function to create a new auction
void Seller::createNewAuction()
{
    string name, description;
    double startingPrice;

    // Prompt seller for auction item details
    cout << "Enter Item Name: ";
    cin.ignore(); // To ignore any leftover newline from previous input
    getline(cin, name);

    cout << "Enter Item Description: ";
    getline(cin, description);

    cout << "Enter Starting Price: $";
    cin >> startingPrice;

    // Create a new item object
    Item newItem((FileHandler::getAllItems().countNodes()+1),this->getUserId(),name , description, startingPrice, false);

    // Add the item to the AVL tree
    FileHandler::getAllItems().insert(newItem.getItemId(),newItem);
    items.insert(newItem.getItemId(),newItem);

    cout<<newItem;

    cout << "New auction created successfully.\n";
}



// // Function to view bids on seller's items
void Seller::viewBids()
{
    // Get all bids related to the seller's items
    // stack <Bid> bids = Bid::bidHistory;
    // Assuming a method that loads all bids
    cout << "\nBids on Your Items:\n";



}

// // Function to end auction
// void Seller::endAuction()
// {
//     string itemName;
//     cout << "Enter the name of the item to end the auction: ";
//     cin.ignore(); // To clear the input buffer
//     getline(cin, itemName);

//     // Find the item by name (or other identifier)
//     Item *item = FileHandler::findItemByName(itemName); // Assuming a method to find the item
//     if (item != nullptr)
//     {
//         // Mark the item as sold and finalize the auction
//         item->setIsSold(true);
//         FileHandler::updateItem(item); // Assuming a method that updates the item in storage
//         cout << "Auction ended successfully. Item has been sold.\n";
//     }
//     else
//     {
//         cout << "Item not found.\n";
//     }
// }
// copy constructor
Seller::Seller(const User &user)
{
    // Private members of User are not accessible here
    // Use getters to access private members
    setUserId(user.getUserId());
    setUsername(user.getUsername());
    setPassword(user.getPassword());
    setRole(user.getRole());
    getItemsOfUser();

}



void Seller::getItemsOfUser()
{
    AVLTree<Item> allitems = FileHandler::getAllItems();
    getItemofUserRec(allitems.getRoot(), this->getUserId());


}

void Seller::getItemofUserRec(Node<Item> *root, int id)
{
    if (root != nullptr)
    {
        getItemofUserRec(root->left, id);
        if (root->data.getsellerId() == id)
        {
            items.insert(root->key, root->data);
        }
        getItemofUserRec(root->right, id);
    }
}

void Buyer::getMenu()
{
    // make menu for buyer
    cout << "1. View Items: ";
}

// copy constructor
Buyer::Buyer(const User &user)
{
    // Private members of User are not accessible here
    // Use getters to access private members
    setUserId(user.getUserId());
    setUsername(user.getUsername());
    setPassword(user.getPassword());
    setRole(user.getRole());
}

void Admin::getMenu()
{
    // make menu for admin
    cout << "1. View Users: ";
}

Admin::Admin(const User &user)
{
    // Private members of User are not accessible here
    // Use getters to access private members
    setUserId(user.getUserId());
    setUsername(user.getUsername());
    setPassword(user.getPassword());
    setRole(user.getRole());
}