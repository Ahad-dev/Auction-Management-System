# Auction Management System :gavel:

## Overview :memo:

The **Auction Management System** is a console-based C++ project that simulates an online auction platform. It allows **sellers** to list items for auction, **buyers** to place bids, and **admins** to manage the system. The system utilizes Data Structures such as **Linked Lists**, **Graphs**, and **Hash Maps**, with **file handling** for persistent data storage.

## Features :star2:

### :man_singer: **Seller**:
- List items for auction.
- Set a starting bid and auction duration.
- View current bids and remove items.

### :shopping_cart: **Buyer**:
- View available auction items.
- Place bids on items.
- Track their active bids.

### :guardsman: **Admin**:
- Manage users (Sellers and Buyers).
- View all auction items and bids.
- Generate reports on auction results.

## Data Structures Used :triangular_ruler:

- **Linked List**: For managing items in the auction and bids.
- **Graph**: To model relationships between items, users, and categories.
- **Hash Map**: For quick access to user data and auction details.

## File Handling :file_folder:

- **Items, Users, Bids**: Data is stored in text files to simulate a database. These files are loaded and saved using custom file-handling classes.
- **Reports**: The system generates reports on completed auctions, which are saved in a report file.

## Folder Structure :file_cabinet:

```
AuctionManagementSystem/
├── bin/                   # Compiled executable files
├── build/                 # Build-related files (e.g., object files)
├── docs/                  # Documentation (e.g., README.md)
├── include/               # Header files for classes
│   ├── User.h
│   ├── Item.h
│   ├── Bid.h
│   ├── LinkedList.h
│   ├── Graph.h
│   ├── HashMap.h
│   ├── FileHandler.h
│   └── Report.h
├── resources/             # Files for storing data (e.g., Users.txt, Items.txt)
│   ├── Items.txt
│   ├── Users.txt
│   ├── Bids.txt
│   └── Reports.txt
├── src/                   # Source files
│   ├── main.cpp           # Main program file
│   ├── classes/           # C++ classes implementation
│   │   ├── User.cpp
│   │   ├── Item.cpp
│   │   ├── Bid.cpp
│   │   └── Admin.cpp
│   ├── dataStructures/    # Custom data structures
│   │   ├── LinkedList.cpp
│   │   ├── Graph.cpp
│   │   └── HashMap.cpp
│   ├── fileHandling/      # File handling implementation
│   │   └── FileHandler.cpp
│   └── utils/             # Utility functions
│       └── utils.cpp
└── Makefile               # Build script (if applicable)
```

## Installation :wrench:

1. Clone the repository:
    ```bash
    git clone https://github.com/Ahad-dev/Auction-Management-System.git
    cd AuctionManagementSystem
    ```

2. Compile the C++ files:
    - If you're using a `Makefile`, run:
      ```bash
      make
      ```

    - Alternatively, you can compile manually using `g++`:
      ```bash
      g++ -o auction_system src/main.cpp src/classes/*.cpp src/dataStructures/*.cpp src/fileHandling/*.cpp src/utils/*.cpp
      ```

3. Run the compiled executable:
    ```bash
    ./auction_system
    ```

## Usage :computer:

### Seller:
- As a **seller**, log in, list your items for auction, and set the starting bid and auction duration.
- View current bids and remove items if needed.

### Buyer:
- As a **buyer**, view available auction items and place bids.
- Track your active bids and see if you've won any items.

### Admin:
- As an **admin**, manage users (sellers and buyers), view auction items and bids, and generate reports for completed auctions.

## Future Enhancements :rocket:

- Implement a more robust system for tracking auction start and end times.
- Add email notifications for buyers and sellers.
- Enhance reporting with detailed statistics.
- Implement a web-based interface for easier management.

## Contributing :raised_hands:

Feel free to fork the project and submit pull requests for improvements, bug fixes, or new features. For larger changes, please open an issue first to discuss the proposed changes.

## License :page_facing_up:

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.