#include "../../include/User.h"
#include "../dataStructures/LinkedList.cpp"  
#include <string.h>


LinkedList<User> User::allUsers;

// Default Constructor
User::User() : userId(0), username(""), password(""), role("") {}

// Parameterized Constructor
User::User(int id, const string& uname, const string& pwd, const string& role)
    : userId(id), username(uname), password(pwd), role(role) {}

// Getters
int User::getUserId() const {
    return userId;
}

string User::getUsername() const {
    return username;
}

string User::getPassword() const {
    return password;
}

string User::getRole() const {
    return role;
}

// Setters
void User::setUserId(int id) {
    userId = id;
}

void User::setUsername(const string& uname) {
    username = uname;
}

void User::setPassword(const string& pwd) {
    password = pwd;
}

void User::setRole(const string& role) {
    this->role = role;
}
void User::getMenu() {
    int n = 0;
    cout << "Select Your Role: ";
    cout << "1. Admin\n";
    cout << "2. Seller\n";
    cout << "3. Buyer\n";
    cout << "4. Exit\n";
    cout << "Enter your Choice:  ";
    cin >> n;

    // Select role based on user input
    switch (n) {
    case 1:
        this->role = "Admin"; // This works because role is a std::string
        break;
    case 2:
        this->role = "Seller";
        break;
    case 3:
        this->role = "Buyer";
        break;
    default:
        cout << "Invalid option! Role not set." << endl;
        this->role = ""; // Optionally clear the role for invalid input
        break;
    }
}

// Static functions
void User::loadUsersFromFile(const string& fileName) {
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
        allUsers.addNode(User(id, uname, pwd, role));
    }

    file.close();
}

void User::saveUsersToFile(const string& fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    Node<User>* current = allUsers.getHead();
    while (current != nullptr) {
        file << current->data.getUserId() << " " << current->data.getUsername() << " "
             << current->data.getPassword() << " " << current->data.getRole() << endl;
        current = current->next;
    }

    file.close();
}

// Function to authenticate a user
User* User::authenticateUser() {
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    Node<User>* current = allUsers.getHead();
    while (current != nullptr) {
        if (current->data.getUsername() == username && current->data.getPassword() == password) {
             if (current->data.role == "Admin") {
                return new Admin(current->data);  // Return Admin object
            } else if (current->data.role == "Seller") {
                return new Seller(current->data);  // Return Seller object
            } else if (current->data.role == "Buyer") {
                return new Buyer(current->data);  // Return Buyer object
            }
        }
        current = current->next;
    }

    return nullptr;
}

// Function to check if a username or ID already exists
bool User::checkUsernameOrIdAleadyExist(const string& username, const string& id) {
    Node<User>* current = allUsers.getHead();
    while (current != nullptr) {
        if (current->data.getUsername() == username || to_string(current->data.getUserId()) == id) {
            return true;
        }
        current = current->next;
    }

    return false;
}

// Function to register a user
void User::registerUser(const string& role){
    User user;
    bool check = false;
    int attempts = 3;
    do{

    cin >> user;
    user.setRole(role);
    //check if username or id already exist
    if (checkUsernameOrIdAleadyExist(user.getUsername(), to_string(user.getUserId()))) {
        check  = true;
        cout << "Username or ID already exists!" << endl;
        attempts--;
        cout<<"Attempts left: "<<attempts<<endl;

    }
    else{
        check = false;
        allUsers.addNode(user);
        cout << "User registered successfully!" << endl;
    }
    }while(check && attempts > 0);
} 


// Over load input operator
istream& operator>>(istream& in, User& user) {
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
ostream& operator<<(ostream& out, const User& user) {
    out << "User ID: " << user.userId << endl;
    out << "Username: " << user.username << endl;   
    out << "Role: " << user.role << endl;
    return out;
}

// Function to display user details
void User::displayUserDetails() const {
    cout << "User ID: " << userId << endl;
    cout << "Username: " << username << endl;
    cout << "Role: " << role << endl;
}



void Seller::getMenu() {
    //make menu for seller
    cout<<"1. View Actions: ";
    
}

//copy constructor
Seller::Seller(const User& user) {
    // Private members of User are not accessible here
    // Use getters to access private members
    setUserId(user.getUserId());
    setUsername(user.getUsername());
    setPassword(user.getPassword());
    setRole(user.getRole());


}

void Buyer::getMenu() {
    //make menu for buyer
    cout<<"1. View Items: ";
    
}

//copy constructor
Buyer::Buyer(const User& user) {
    // Private members of User are not accessible here
    // Use getters to access private members
    setUserId(user.getUserId());
    setUsername(user.getUsername());
    setPassword(user.getPassword());
    setRole(user.getRole());
}


void Admin::getMenu() {
    //make menu for admin
    cout<<"1. View Users: ";
}


Admin::Admin(const User& user) {
    // Private members of User are not accessible here
    // Use getters to access private members
    setUserId(user.getUserId());
    setUsername(user.getUsername());
    setPassword(user.getPassword());
    setRole(user.getRole());
}