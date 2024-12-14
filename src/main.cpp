#include <iostream>
using namespace std;
#include "../include/User.h"

int main(){

    User::loadUsersFromFile("resources/Users.txt");

    int n;
    User* user;
    user = new User();
    user->getMenu();
    
    while(n!=3){
        cout<<"1.Register\n ";
        cout<<"2.Login\n ";
        cout<<"3.Exit \n ";
        cout<<"Enter your Choice ";
        cin>>n;
            switch(n){
                case(1):
                    user->registerUser(user->getRole());
                break;
                case(2):{
                    user = User::authenticateUser();
                    if(user!=nullptr){
                        cout<<"User Authenticated\n";
                        user->getMenu();
                    }else{
                        cout<<"User not Authenticated\n";
                    }
                }
            }
    }

    User::saveUsersToFile("resources/Users.txt");

    return 0;
}