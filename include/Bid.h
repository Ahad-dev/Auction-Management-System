#ifndef BID_H
#define BID_H

#include <iostream>
#include <stack>
using namespace std;

class Bid {
private:
    int bidId;               // Unique identifier for the bid
    double bidAmount;        // Amount of the bid
    int bidderId;            // The user ID who made the bid
    int itemId;              // The item ID being bid on

public:

    // Constructors
    Bid() : bidId(0), bidAmount(0.0), bidderId(0), itemId(0) {}
    Bid(int bidId, double bidAmount, int bidderId, int itemId)
        : bidId(bidId), bidAmount(bidAmount), bidderId(bidderId), itemId(itemId) {
    }

    // Getter functions
    int getBidId() const { return bidId; }
    double getBidAmount() const { return bidAmount; }
    int getBidderId() const { return bidderId; }
    int getItemId() const { return itemId; }

    // Setter functions
    void setBidId(int bidId) { this->bidId = bidId; }
    void setBidAmount(double bidAmount) { this->bidAmount = bidAmount; }
    void setBidderId(int bidderId) { this->bidderId = bidderId; }
    void setItemId(int itemId) { this->itemId = itemId; }

    // Display bid details
    void displayBid() const {
        cout << "Bid ID: " << bidId << "\n"
             << "Amount: " << bidAmount << "\n"
             << "Bidder ID: " << bidderId << "\n"
             << "Item ID: " << itemId << "\n";
    }

    // Overload output operator <<
    friend ostream& operator<<(ostream& os, const Bid& bid) {
        os << "Bid ID: " << bid.bidId << "\n"
           << "Bid Amount: " << bid.bidAmount << "\n"
           << "Bidder ID: " << bid.bidderId << "\n"
           << "Item ID: " << bid.itemId << "\n";
        return os;
    }

    // Overload input operator >>
    friend istream& operator>>(istream& is, Bid& bid) {
        cout << "Enter Bid ID: ";
        is >> bid.bidId;
        cout << "Enter Bid Amount: ";
        is >> bid.bidAmount;
        cout << "Enter Bidder ID: ";
        is >> bid.bidderId;
        cout << "Enter Item ID: ";
        is >> bid.itemId;

        // Automatically push to history
        return is;
    }

    // Static methods for bid history
    // static void displayHistory() {
    //     stack<Bid> tempStack = FileHandler::getBidHistoryForItem(); // Copy the stack
    //     cout << "\n===== Bid History =====\n";
    //     while (!tempStack.empty()) {
    //         cout << tempStack.top();
    //         cout << "-------------------------\n";
    //         tempStack.pop();
    //     }
    // }
};

#endif
