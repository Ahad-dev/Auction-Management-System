#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../include/User.h"
#include "../include/FileHandler.h"
using namespace std;

void refresh() {
    system("cls");
    cout << R"(
                \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
                \\                                 \\
                \\              __  __     _____   \\
                \\     /\      |  \/  |   / ____|  \\
                \\    /  \     | \  / |  | (___    \\
                \\   / /\ \    | |\/| |   \___ \   \\
                \\  / ____ \   | |  | |   ____) |  \\
                \\ /_/    \_\  |_|  |_|  |_____/   \\
                \\                                 \\
                \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
)" << endl;
}

void startingMenu(User*& user, int& n) {
    refresh();
    cout << "Select Your Role\n";
    cout << "1. Admin\n";
    cout << "2. Seller\n";
    cout << "3. Buyer\n";
    cout << "4. Exit\n";
    cout << "Enter your Choice: ";
    cin >> n;

    switch (n) {
        case 1:
            user->setRole("Admin");
            break;
        case 2:
            user->setRole("Seller");
            break;
        case 3:
            user->setRole("Buyer");
            break;
        default:
            cout << "Exiting ...." << endl;
            break;
    }
}

int main() {
    FileHandler::loadUsersFromFile("resources/Users.txt");
    FileHandler::loadItemsFromFile("resources/Items.txt");
    FileHandler::loadBidHistory("resources/Bids.txt");

    int n;
    User* user = new User();

    do {
        startingMenu(user, n);
        if (n != 4) {
                int m;
            do {
                refresh();
                cout << "1. Register\n";
                cout << "2. Login\n";
                cout << "3. Exit\n";
                cout << "Enter your Choice: ";
                cin >> m;

                switch (m) {
                    case 1:{
                        refresh();
                        FileHandler::registerUser(user->getRole());
                        _getch();
                        }
                        break;
                    case 2: {
                        refresh();
                        user = FileHandler::authenticateUser();
                        if (user != nullptr) {
                            // delete user; // Clean up previous user
                            // user = authenticatedUser; // Assign authenticated user
                            cout << "User Authenticated\n";
                            _getch();
                            refresh();
                            user->getMenu(); // Display menu for authenticated user
                        } else {
                            cout << "User not Authenticated\n";
                            delete user; // Clean up dynamically allocated user
                            _getch();
                            refresh();
                        }
                        break;
                    }
                }
            } while (m != 3);
        }
    } while (n != 4);

    // delete user; // Clean up dynamically allocated user
    FileHandler::saveUsersToFile("resources/Users.txt");
    FileHandler::saveItemsToFile("resources/Items.txt");
    FileHandler::saveBidHistory("resources/Bids.txt");

    return 0;
}
