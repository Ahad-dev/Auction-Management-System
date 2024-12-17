#include "../../include/FileHandler.h"
// #include "../../include/LinkedList.h"
#include "../../include/Item.h"
#include "../../include/Bid.h"
#include "../../include/User.h"
#include "../../include/AvlBst.h"
#include<Stack>
#include <conio.h>



AVLTree<User> FileHandler::allUsers;  
LinkedList<User> FileHandler::Users;
map<int, stack<Bid>> FileHandler:: bidHistoryMap; // Static stack to store bid history
map<int, stack<Bid>> FileHandler:: bidderHistoryMap; // To store bid history by bidderId
queue<Item> FileHandler:: auctionQueue; // Static stack to store bid history

// AVLTree<User> FileHandler::allUsers;

// Static functions
void FileHandler::loadUsersFromFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int id;
        string uname, pwd, role;

        ss >> id >> uname >> pwd >> role;
        
        allUsers.insert(id,User(id, uname, pwd, role),uname);
        // allUsers.insert(User(id, uname, pwd, role));

    }
    allUsers.inOrderTraversal();
    _getch();

    file.close();
}

void FileHandler::saveUsersToFile(const string& fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    saveUsersToFileRec(file, allUsers.getRoot());

    file.close();
}
//Recursive function to save users to file
void FileHandler::saveUsersToFileRec(ofstream& file, Node<User>* root) {
    if (root != nullptr) {
        saveUsersToFileRec(file, root->left);
        file << root->data.getUserId() << " " << root->data.getUsername() << " "
             << root->data.getPassword() << " " << root->data.getRole() << endl;
        saveUsersToFileRec(file, root->right);
    }
}

// Function to authenticate a user
User* FileHandler::authenticateUser() {
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    
    //find the user in the tree
    Node<User> * user = allUsers.searchByUsername(username);
    cout<<user->data;
    if (user != nullptr && user->data.getPassword() == password) {
        //based on the role of the user, return the user
        if(user->data.getRole() == "Admin"){
            return new Admin(user->data);
        }
        else if(user->data.getRole() == "Seller"){
            return new Seller(user->data);
        }
        else if(user->data.getRole() == "Buyer"){
            return new Buyer(user->data);
        }
        return nullptr;
    }

    return nullptr;
}

// Function to register a user
void FileHandler::registerUser(const string& role) {
    User user;
    // bool check = false;
    // int attempts = 3;
    // do {
        // cin.ignore();
        cin >> user;
        user.setRole(role);
        // // check if username or id already exist
        // if (allUsers.searchByUsername(user.getUsername()) == nullptr) {
        //     check = true;
        //     cout << "Username or ID already exists!" << endl;
        //     attempts--;
        //     cout << "Attempts left: " << attempts << endl;
        // } else {
            // check = false;
            allUsers.insert(user.getUserId(),user,user.getUsername());
            cout << "User registered successfully!" << endl;
            _getch();
        // }
    // } while (!check && attempts > 0);
}


// AVLTree<User> FileHandler::getAllUsers(){
//     return allUsers;
// }


LinkedList<User> FileHandler::getUsers(){
    return Users;
}


// Static LinkedList to store items
AVLTree<Item> FileHandler::allItems;
LinkedList<Item> FileHandler::Items;

// // Static function to load items from a file
void FileHandler::loadItemsFromFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int id,sellerId;
        string name, description;
        double price;
        bool isSold,listed;

        ss >> id >> sellerId >>name >> description >> price >> isSold >> listed;
            allItems.insert(id,Item(id,sellerId, name, description, price, isSold,listed));
        if(!listed){
            auctionQueue.push(Item(id,sellerId, name, description, price, isSold,listed));
        }
    }

    file.close();
}

// // Static function to save items to a file
void FileHandler::saveItemsToFile(const string& fileName) {
    cout << "Saving items to file...\n";
    _getch();
    ofstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    saveItemsToFileRec(file, allItems.getRoot());


    file.close();
}

// Function to insert data of each node of the tree into the file
void FileHandler::saveItemsToFileRec(ofstream& file, Node<Item>* root) {
    if (root != nullptr) {
        saveItemsToFileRec(file, root->left);
        file << root->data.getItemId() << " " << root->data.getsellerId()<<" " << root->data.getName() << " "
             << root->data.getDescription() << " " << root->data.getPrice() << " "
             << root->data.getIsSold() <<" "<< root->data.getIsListed() << endl;
        saveItemsToFileRec(file, root->right);
    }
}

// void saveBidHistoryToFile(const string& fileName) {
//     ofstream file(fileName);
//     if (!file.is_open()) {
//         cerr << "Error opening file for writing bid history.\n";
//         return;
//     }

//     stack<Bid> tempStack = Bid::bidHistory; // Copy stack
//     while (!tempStack.empty()) {
//         Bid bid = tempStack.top();
//         file << bid.getBidId() << " " << bid.getBidAmount() <<" "<<bid.getBidder()->getUserId()<<" "<<bid.getItem()->getItemId()<< endl;
//         tempStack.pop();
//     }

//     file.close();
//     cout << "Bid history saved to " << fileName << ".\n";
// }


LinkedList <Item> FileHandler::getItems(){
    return Items;
}


// Function to get all items (needed to access items from anywhere)
AVLTree<Item>& FileHandler::getAllItems() {
    return allItems;
}

AVLTree <User>& FileHandler::getAllUsers(){
    return allUsers;
}


// Load bid history from file and populate the map
void FileHandler::loadBidHistory(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file: " << filename << "\n";
        return;
    }

    int bidId, bidderId, itemId;
    double bidAmount;
    
    while (inFile >> bidId >> bidAmount >> bidderId >> itemId) {
        // Create a Bid object
        Bid bid(bidId, bidAmount, bidderId, itemId);

        // Add to bid history map by itemId
        bidHistoryMap[itemId].push(bid);

        // Add to bidder history map by bidderId
        bidderHistoryMap[bidderId].push(bid);
    }

    inFile.close();
    cout << "Bid history loaded successfully!\n";
}


// Save bid history back to the file
void FileHandler::saveBidHistory(const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error opening file: " << filename << "\n";
        return;
    }

    for (auto& pair : bidHistoryMap) { // Iterate through the map
        stack<Bid> tempStack = pair.second;

        while (!tempStack.empty()) {
            const Bid& bid = tempStack.top();
            outFile << bid.getBidId() << " "
                    << bid.getBidAmount() << " "
                    << bid.getBidderId() << " "
                    << bid.getItemId() << "\n";
            tempStack.pop();
        }
    }

    outFile.close();
    cout << "Bid history saved successfully!\n";
}


// Add a bid to a specific item's history
void FileHandler::addBidToItemHistory(const Bid& bid) {
    bidHistoryMap[bid.getItemId()].push(bid);
}

// Get bid stack for a specific item
stack<Bid>& FileHandler::getBidHistoryForItem(int itemId) {
    return bidHistoryMap[itemId];
}

//get the stack of bid history for particular bidder
stack<Bid>& FileHandler::getBidHistoryForBidder(int bidderId) {
    return bidderHistoryMap[bidderId];
}

//get the queue of items that are not listed
Item FileHandler::getAuctionQueue(){
    while(!auctionQueue.empty()){
        Item i = auctionQueue.front();
        auctionQueue.pop();
        return i;
    }
    return Item();
}