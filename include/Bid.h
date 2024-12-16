#ifndef BID_H
#define BID_H

#include <iostream>
#include <string>
#include <stack> // For stack functionality
#include "User.h"
#include "Item.h"

using namespace std;

class Bid {
private:
    int bidId;               // Unique identifier for the bid
    double bidAmount;        // Amount of the bid
    User* bidder;            // The user who made the bid
    Item* item;              // The item being bid on


public:
    static stack<Bid> bidHistory; // Stack to maintain bid history
    // Constructors
    Bid();
    Bid(int bidId, double bidAmount, User* bidder, Item* item);

    // Getter functions
    int getBidId() const;
    double getBidAmount() const;
    User* getBidder() const;
    Item* getItem() const;

    // Setter functions
    void setBidId(int bidId);
    void setBidAmount(double bidAmount);
    void setBidder(User* bidder);
    void setItem(Item* item);

    // Function to display bid details
    void displayBid() const;

    // Static methods for bid history
    static void pushToHistory(const Bid& bid);
    static Bid popFromHistory();
    static void displayHistory();

    // Overload the input and output operators
    friend ostream& operator<<(ostream& os, const Bid& bid);
    friend istream& operator>>(istream& is, Bid& bid);
};

#endif
