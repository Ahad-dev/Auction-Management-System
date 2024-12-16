#include <iostream>
#include <windows.h>
using namespace std;
#include "../include/User.h"
#include <conio.h>
#include "../include/FileHandler.h"






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


void staringMenu(User * &user,int &n){
    refresh();
    cout << "Select Your Role\n";
    cout << "1. Admin\n";
    cout << "2. Seller\n";
    cout << "3. Buyer\n";
    cout << "4. Exit\n";
    cout << "Enter your Choice:  ";
    cin >> n;

    // Select role based on user input
    switch (n) {
    case 1:
        user->setRole("Admin"); // This works because role is a std::string
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


int main(){

    FileHandler::loadUsersFromFile("resources/Users.txt");
    FileHandler::loadItemsFromFile("resources/Items.txt");
    

    int n;
    User* user;
    user = new User();
    do{

    staringMenu(user,n);

    if(n!=4){
        do{
            refresh();
            cout<<"1.Register\n";
            cout<<"2.Login\n";
            cout<<"3.Exit \n";
            cout<<"Enter your Choice ";
            cin>>n;
            switch(n){
                case(1):
                    user->registerUser(user->getRole());
                break;
                case(2):{
                    refresh();
                    user = FileHandler::authenticateUser();
                    if(user!=nullptr){
                        cout<<"User Authenticated\n";
                        _getch();
                        refresh();
                        user->getMenu();
                    }else{
                        cout<<"User not Authenticated\n";
                        _getch();
                        refresh();
                    }
                }
            }
        }while(n!=3);   
    }
    }while(n!=4);
    FileHandler::saveUsersToFile("resources/Users.txt");
    FileHandler::saveItemsToFile("resources/Items.txt");

    return 0;
}