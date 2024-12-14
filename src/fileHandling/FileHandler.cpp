// #include "../../include/FileHandler.h"




// User* FileHandler::authenticateUser(const string& username, const string& password) {
//     ifstream inFile("resources/Users.txt");
//     string line;
//     while (getline(inFile, line)) {
//         stringstream ss(line);
//         string user, pass, role;
//         getline(ss, user, ',');
//         getline(ss, pass, ',');
//         getline(ss, role, ',');

//         if (user == username && pass == password) {
//             if (role == "Admin") {
//                 // return new Admin();  // Return Admin object
//             } else if (role == "Seller") {
//                 return new Seller();  // Return Seller object
//             } else if (role == "Buyer") {
//                 // return new Buyer();  // Return Buyer object
//             }
//         }
//     }

//     inFile.close();
//     return nullptr;  // Return nullptr if authentication fails
// }


// bool FileHandler::checkUsernameOrIdAleadyExist()

// void FileHandler::resgisterUser(const string& username, const string& password, const string& role) {
//     ofstream outFile("resources/Users.txt", ios::app);
//     outFile << username << "," << password << "," << role << endl;
//     outFile.close();
// }