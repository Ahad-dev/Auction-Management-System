#include "../../include/FileHandler.h"
// #include "../../include/LinkedList.h"
#include "../../include/User.h"
#include "../../include/Item.h"
#include "../../include/AvlBst.h"
#include "../../include/Bid.h"
#include<Stack>



LinkedList<User> FileHandler::Users;
AVLTree<User> FileHandler::allUsers;

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
        Users.addListNode(User(id, uname, pwd, role));
        allUsers.insert(User(id, uname, pwd, role));
    }

    file.close();
}

void FileHandler::saveUsersToFile(const string& fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    ListNode<User>* current = Users.getHead();
    while (current != nullptr) {
        file << current->data.getUserId() << " " << current->data.getUsername() << " "
             << current->data.getPassword() << " " << current->data.getRole() << endl;
        current = current->next;
    }

    file.close();
}

// Function to authenticate a user
User* FileHandler::authenticateUser() {
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    ListNode<User>* current = Users.getHead();
    while (current != nullptr) {
        if (current->data.getUsername() == username && current->data.getPassword() == password) {
             if (current->data.getRole() == "Admin") {
                return new Admin(current->data);  // Return Admin object
            } else if (current->data.getRole() == "Seller") {
                return new Seller(current->data);  // Return Seller object
            } else if (current->data.getRole() == "Buyer") {
                return new Buyer(current->data);  // Return Buyer object
            }
        }
        current = current->next;
    }

    return nullptr;
}


AVLTree<User> FileHandler::getAllUsers(){
    return allUsers;
}


LinkedList<User> FileHandler::getUsers(){
    return Users;
}


// Static LinkedList to store items
AVLTree<Item> FileHandler::allItems;

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
        int id;
        string name, description;
        double price;
        bool isSold;

        ss >> id >> name >> description >> price >> isSold;
        allItems.insert(Item(id, name, description, price, isSold));
    }

    file.close();
}

// // Static function to save items to a file
void FileHandler::saveItemsToFile(const string& fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    // inset the data of each node of three into the file
    saveItemsToFileRec(file, allItems.getRoot());

    file.close();
}

// Function to insert data of each node of the tree into the file
void FileHandler::saveItemsToFileRec(ofstream& file, Node<Item>* root) {
    if (root != nullptr) {
        saveItemsToFileRec(file, root->left);
        file << root->key.getItemId() << " " << root->key.getsellerId() << root->key.getName() << " "
             << root->key.getDescription() << " " << root->key.getPrice() << " "
             << root->key.getIsSold() << endl;
        saveItemsToFileRec(file, root->right);
    }
}

void saveBidHistoryToFile(const string& fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file for writing bid history.\n";
        return;
    }

    stack<Bid> tempStack = Bid::bidHistory; // Copy stack
    while (!tempStack.empty()) {
        Bid bid = tempStack.top();
        file << bid.getBidId() << " " << bid.getBidAmount() <<" "<<bid.getBidder()->getUserId()<<" "<<bid.getItem()->getItemId()<< endl;
        tempStack.pop();
    }

    file.close();
    cout << "Bid history saved to " << fileName << ".\n";
}



// // Function to get all items (needed to access items from anywhere)
AVLTree<Item>& FileHandler::getAllItems() {
    return allItems;
}
