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
    Node<User> *node = FileHandler::getAllUsers().searchByUsername(username);  
    if (node == nullptr)
    {
        return true;
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
        // if (checkUsernameOrIdAleadyExist(user.getUsername(), to_string(user.getUserId())))
        // {
        //     check = true;
        //     cout << "Username or ID already exists!" << endl;
        //     attempts--;
        //     cout << "Attempts left: " << attempts << endl;
        // }
        // else
        // {
            check = false;
            // FileHandler::getAllUsers().add(user);
            FileHandler::getAllUsers().insert(user.userId,user,user.username);
            cout << "User registered successfully!" << endl;
            _getch();
            system("cls");
        // }
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
            viewActiveAuctions();
            _getch();
            system("cls");
            break;}
        case 2:{
            // Create New Auction
            // cout << "Create New Auction\n";
            createNewAuction();
            _getch();
            break;}
        case 3:{
            // View Bids on Your Items
            cout << "View Bids on Items\n";
            viewBids();
            _getch();
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
    cout<<"Enter the Id of Item : ";
    int id;
    cin>>id;
    stack<Bid> tempStack = FileHandler::getBidHistoryForItem(id);
    if(tempStack.empty()){
        cout<<"No bids on this item";
    }
    
    while (!tempStack.empty())
    {
        cout << tempStack.top() << "\n";
        tempStack.pop();
    }

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
        if (root->data.getsellerId() == id && root->data.getIsListed())
        {
            items.insert(root->key, root->data);
        }
        getItemofUserRec(root->right, id);
    }
}

void Buyer::getMenu() {
    int choice;
    do {
        // Display the menu for the Buyer
        cout << "\n===== Buyer Menu =====\n";
        cout << "1. View All Items for Auction\n";
        cout << "2. Search for Items\n";
        cout << "3. Place a Bid on an Item\n";
        cout << "4. View My Bidding History\n";
        cout << "5. View Items I Won\n";
        cout << "6. Log Out\n";
        cout << "Enter your choice: ";

        // Get user input
        cin >> choice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore bad input
            cout << "Invalid choice! Please enter a valid option.\n";
            continue;
        }

        switch (choice) {
            case 1:
                // View all items for auction
                cout << "View All Items for Auction\n";
                viewAllItems();
                break;
            case 2:{
                // Search for items
                cout << "Search for Items\n";
                searchItem();
                _getch();
                break;
                }
            case 3:
                // Place a bid on an item
                cout << "Place a Bid on an Item\n";
                placeBid();
                break;
            case 4:
                // View bidding history
                cout << "View My Bidding History\n";
                viewBiddingHistory();
                break;
            case 5:
                // View items the user won
                cout << "View Items I Won\n";
                // viewWonItems();
                break;
            case 6:
                // Log out
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
                break;
        }

    } while (choice != 6); // Repeat until the user logs out
}

void Buyer::viewAllItems()
{
    AVLTree<Item> allitems = FileHandler::getAllItems();
    getListedItemRec(allitems.getRoot());
}

void Buyer::getListedItemRec(Node<Item> *root)
{
    if (root != nullptr)
    {
        getListedItemRec(root->left);
        if ( root->data.getIsListed())
        {
            cout<<root->data;
        }
        getListedItemRec(root->right);
    }
}


void Buyer:: searchItem(){
    cout<<"Enter the id of the item you want to search: ";
    int id;
    cin>>id;
    AVLTree<Item> allitems = FileHandler::getAllItems();
    Node<Item> * item = allitems.SearchNode(id);
    if(item!=nullptr){
        cout<<item->data;
    }
    else{
        cout<<"Item not found";
    }

}

void Buyer::placeBid(){
    int id;
    cout<<"Enter the id of the item you want to place bid on: ";
    cin>>id;
    AVLTree<Item> allitems = FileHandler::getAllItems();
    Node<Item> * item = allitems.SearchNode(id);
    if(!item->data.getIsListed()){
        cout<<"You can't bid on that item because it is not listed\n";
        return;
    }
    if(item!=nullptr){
        double amount;
        cout<<"Enter the amount you want to bid: ";
        cin>>amount;
        Bid bid;
        bid.setBidAmount(amount);
        bid.setBidderId(this->getUserId());
        bid.setItemId(id);
        FileHandler::addBidToItemHistory(bid);
    }
    else{
        cout<<"Item not found";
    }

}

void Buyer::viewBiddingHistory(){
    stack<Bid>& bidderHistory = FileHandler::getBidHistoryForBidder(this->getUserId());

// Display the bids for this bidder
    while (!bidderHistory.empty()) {
        Bid currentBid = bidderHistory.top();
        cout<<currentBid;
        bidderHistory.pop();
    }
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
    int n;

    do{

    // make menu for admin
    cout << "1. Manage User\n";
    cout << "2. Manage Items\n";
    cout << "4. logout\n";
    _getch();

    cout<<"Enter your choice: ";
    cin>>n;

        switch(n){
            case 1:{
                manageUserMenu();
                break;
            }
            case 2:{
                manageItemMenu();
                break;
            }
            
        }
    }while(n!=3);



}

void Admin::manageUserMenu() {
    int n;
    do {
        cout << "1. View All Users\n";
        cout << "2. Add New User\n";
        cout << "3. Delete User\n";
        cout << "4. View User Bidding History\n";
        cout << "5. Back to User Manage\n";
        cout << "Enter your Choice: ";
        cin >> n;

        switch (n) {
            case 1: {
                viewAllUsers();
                break;
            }
            case 2: {
                addNewUser();
                break;
            }

            case 3: {
                deleteUser();
                break;
            }
            case 4: {
                viewUserBiddingHistory();
                break;
            }
            case 5: {
                system("cls"); // Clear the screen
                break;
            }
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (n != 5);
}

// View All Users
void Admin::viewAllUsers() {
    AVLTree <User> users = FileHandler::getAllUsers();

    cout << "\n===== All Users =====\n";
    users.inOrderTraversal();
    cout << "=====================\n";

}

// Add New User
void Admin::addNewUser() {
    string role;
    cout<<"Enter Role: ";
    cin>>role;
    this->registerUser(role);
    cout << "New user added successfully!\n";
}

// Delete User
void Admin::deleteUser() {
    int userId;
    cout << "Enter User ID to delete: ";
    cin >> userId;
    Node<User> * user = FileHandler::getAllUsers().SearchNode(userId);
    cout<<user->data;

    if(user!=nullptr){
        FileHandler::getAllUsers().Delete(user->data.getUserId());
        cout<<"User deleted successfully";
    }
    else{
        cout<<"User not found";
    }
    

}

// View User Bidding History
void Admin::viewUserBiddingHistory() {
    int userId;
    cout << "Enter User ID to view bidding history: ";
    cin >> userId;
    stack<Bid>& bidderHistory = FileHandler::getBidHistoryForBidder(userId);

    if(bidderHistory.empty()){
        cout<<"No bids found for this user";
    }

// Display the bids for this bidder
    while (!bidderHistory.empty()) {
        Bid currentBid = bidderHistory.top();
        cout<<currentBid;
        bidderHistory.pop();
    } 
    
}


void Admin::manageItemMenu() {
        int n;
        do {
            cout << "1 View All Items\n";
            cout << "2 Add New Item\n";
            cout << "3 Delete Item\n";
            cout << "4 View Item Bidding History\n";
            cout<<"5 Start Auction\n";
            cout << "6. Back to Main Menu\n";
            cout << "Enter your Choice: ";
            cin >> n;
            switch (n) {
                case 1:
                    viewAllItems();
                    break;
                case 2:
                    addNewItem();
                    break;
                case 3:
                    deleteItem();
                    break;
                case 4:
                    viewItemBiddingHistory();
                    break;
                case 5:
                    startAuction();
                    break;
                case 6:
                    // Return to the previous menu
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (n != 5);
    }

// View All Items
void Admin::viewAllItems() {
    AVLTree<Item> items = FileHandler::getAllItems();
    cout << "\n===== All Items =====\n";
    items.inOrderTraversal();
    cout << "=====================\n";
}

// Add New Item
void Admin::addNewItem() {
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

    cout<<newItem;

    cout << "New auction created successfully.\n";
}

// Delete Item
void Admin::deleteItem() {
    int itemId;
    cout << "Enter Item ID to delete: ";
    cin >> itemId;
    Node<Item> * item = FileHandler::getAllItems().SearchNode(itemId);
    cout<<item->data;

    if(item!=nullptr){
        FileHandler::getAllItems().Delete(item->data.getItemId());
        cout<<"Item deleted successfully";
    }
    else{
        cout<<"Item not found";
    }
}

// View Item Bidding History
void Admin::viewItemBiddingHistory() {
    int itemId;
    cout << "Enter Item ID to view bidding history: ";
    cin >> itemId;
    stack<Bid>& itemHistory = FileHandler::getBidHistoryForItem(itemId);

    if(itemHistory.empty()){
        cout<<"No bids found for this item";
    }

// Display the bids for this bidder
    stack<Bid> tempStack = itemHistory;
        while (!tempStack.empty()) {
            Bid currentBid = tempStack.top();
            cout<<currentBid;
            tempStack.pop();
    }

}

void Admin::startAuction(){
    Item  i =  FileHandler::getAuctionQueue();
    if(i.getItemId()==0){
        cout<<"No items in the auction queue";
        return;
    }
    
    cout<<"The "<<i.getName()<<" is up for auction with starting Price of "<<i.getPrice();
    cout<<"Do you want to start the auction? (y/n)";
    char c;
    cin>>c;
    if(c!='y'){
        cout<<"Auction not started";
        return;
    }

    Node<Item> * item = FileHandler::getAllItems().SearchNode(i.getItemId());
    if(item!=nullptr){
        item->data.setIsListed(true);
        cout<<"Auction started successfully";
    }
    else{
        cout<<"Item not found";
    }
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