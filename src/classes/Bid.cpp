#include "../../include/Bid.h"

// Initialize static member
stack<Bid> Bid::bidHistory;

// Default Constructor
Bid::Bid() : bidId(0), bidAmount(0.0), bidder(nullptr), item(nullptr) {}

// Parameterized Constructor
Bid::Bid(int bidId, double bidAmount, User* bidder, Item* item) 
    : bidId(bidId), bidAmount(bidAmount), bidder(bidder), item(item) {}

// Getter functions
int Bid::getBidId() const { return bidId; }
double Bid::getBidAmount() const { return bidAmount; }
User* Bid::getBidder() const { return bidder; }
Item* Bid::getItem() const { return item; }

// Setter functions
void Bid::setBidId(int bidId) { this->bidId = bidId; }
void Bid::setBidAmount(double bidAmount) { this->bidAmount = bidAmount; }
void Bid::setBidder(User* bidder) { this->bidder = bidder; }
void Bid::setItem(Item* item) { this->item = item; }

// Function to display bid details
void Bid::displayBid() const {
    cout << "Bid ID: " << bidId << ", Amount: " << bidAmount
         << ", Bidder: " << (bidder ? bidder->getUsername() : "N/A")
         << ", Item: " << (item ? item->getName() : "N/A") << endl;
}

// Static function to push a bid to history
void Bid::pushToHistory(const Bid& bid) {
    bidHistory.push(bid);
    cout << "Bid with ID " << bid.bidId << " added to history.\n";
}

// Static function to pop a bid from history
Bid Bid::popFromHistory() {
    if (bidHistory.empty()) {
        throw runtime_error("No bid history available.");
    }
    Bid lastBid = bidHistory.top();
    bidHistory.pop();
    cout << "Bid with ID " << lastBid.bidId << " removed from history.\n";
    return lastBid;
}

// Static function to display bid history
void Bid::displayHistory() {
    if (bidHistory.empty()) {
        cout << "No bid history available.\n";
        return;
    }

    stack<Bid> tempStack = bidHistory; // Copy the stack for traversal
    cout << "\n===== Bid History =====\n";
    while (!tempStack.empty()) {
        Bid bid = tempStack.top();
        bid.displayBid();
        tempStack.pop();
    }
}

// Overload the input operator
istream& operator>>(istream& is, Bid& bid) {
    cout << "Enter Bid ID: ";
    is >> bid.bidId;
    cout << "Enter Bid Amount: ";
    is >> bid.bidAmount;
    // Bidder and item pointers must be assigned externally
    bid.bidder = nullptr;
    bid.item = nullptr;
    return is;
}

// Overload the output operator
ostream& operator<<(ostream& os, const Bid& bid) {
    os << "Bid ID: " << bid.bidId << ", Amount: " << bid.bidAmount
       << ", Bidder: " << (bid.bidder ? bid.bidder->getUsername() : "N/A")
       << ", Item: " << (bid.item ? bid.item->getName() : "N/A");
    return os;
}
