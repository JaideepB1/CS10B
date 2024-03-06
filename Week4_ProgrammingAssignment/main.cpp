#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

#include "Deck.h"
#include "Card.h"

bool isOrdered(const vector<double>& hand) {
    bool isOrder = true;
    for (unsigned i = 0; i + 1 < hand.size(); i++) {
        if (hand.at(i) > hand.at(i + 1)) {
            isOrder = false;
        }
    }

    if (isOrder) {
        return true;
    }

    else {
        return false;
    }
}

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand) {
    vector<Card> handCopy;
    handCopy = hand;
    bool isOrder = false;
    while (!isOrder) {
        for (unsigned int i = 0; i + 1 < handCopy.size(); i++) {
            if (handCopy.at(i).getRank() > handCopy.at(i + 1).getRank()) {
                swap(handCopy.at(i), handCopy.at(i + 1));
            }
        }

        isOrder = true;
        for (unsigned i = 0; i + 1 < handCopy.size(); i++) {
            if (handCopy.at(i).getRank() > handCopy.at(i + 1).getRank()) {
                isOrder = false;
            }
        }

    }
    
    bool check = false;
    for (unsigned i = 0; i + 1 < handCopy.size(); i++) {
        if (handCopy.at(i).getRank() == handCopy.at(i + 1).getRank()) {
            check = true;
        }
    }

    if (check) {
        return true;
    }

    else {
        return false;
    }
}

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &out, const vector<Card> &dealtCards) {
    char ccpy;
    string suitName;
    ccpy = dealtCards.at(0).getSuit();
    if (ccpy == 'c') {
        suitName = "Clubs";
    }

    else if (ccpy == 'd') {
        suitName = "Diamond";
    }

    else if (ccpy == 'h') {
        suitName = "Hearts";
    }

    else {
        suitName = "Spades";
    }

    if (dealtCards.at(0).getRank() == 11) {
        out << "Jack of " << suitName;
    }

    else if (dealtCards.at(0).getRank() == 12) {
        out << "Queen of " << suitName;
    }

    else if (dealtCards.at(0).getRank() == 13) {
        out << "King of " << suitName;
    }

    else if (dealtCards.at(0).getRank() == 1) {
        out << "Ace of " << suitName;
    }

    else {
        out << dealtCards.at(0).getRank() << " of " << suitName;
    }
    
    
    if (dealtCards.size() > 1) {
        for (unsigned i = 1; i < dealtCards.size(); i++) {

            ccpy = dealtCards.at(i).getSuit();

            if (ccpy == 'c') {
                suitName = "Clubs";
            }

            else if (ccpy == 'd') {
                suitName = "Diamond";
            }

            else if (ccpy == 'h') {
                suitName = "Hearts";
            }

            else {
                suitName = "Spades";
            }


            if (dealtCards.at(i).getRank() == 11) {
                out << ", Jack of " << suitName;
            }

            else if (dealtCards.at(i).getRank() == 12) {
                out << ", Queen of " << suitName;
            }

            else if (dealtCards.at(i).getRank() == 13) {
                out << ", King of " << suitName;
            }

            else if (dealtCards.at(i).getRank() == 1) {
                out << ", Ace of " << suitName;
            }

            else {
                out << ", " << dealtCards.at(i).getRank() << " of " << suitName;
            }

        }
    }

    out << endl;

    return out;
}

int main() {
    srand(2222);

    string outputFile;
    ofstream outFS;
    string fileName;
    unsigned numCards;
    unsigned numDeals;
    Deck cardDeck;
    double count = 0;

    cout << "Do you want to output all hands to a file? (Yes/No)" << endl;

    cin >> outputFile;

    if (outputFile == "Yes") {
        cout << "Enter name of output file: " << endl;
        cin >> fileName;
        outFS.open(fileName);

        cout << "Enter number of cards per hand: " << endl;

        cin >> numCards;

        cout << "Enter number of deals (simulations) : " << endl;

        cin >> numDeals;
        
        vector<Card> dealtCopy (numCards);

        for (unsigned i = 0; i < numDeals; i++) {
            for (unsigned j = 0; j < numCards; j++) {
                dealtCopy.at(j) = cardDeck.dealCard();
            }
            if (hasPair(dealtCopy)) {
                count += 1;
                outFS << "Found Pair!! ";
            }

            outFS << dealtCopy;
            cardDeck.shuffleDeck();
        }

        cout << "Chances of receiving a pair in a hand of " << numCards << " cards is: ";

        cout << (count / numDeals) * 100 << "%" << endl;

        outFS.close();

    }

    else {

        cout << "Enter number of cards per hand: " << endl;

        cin >> numCards;

        cout << "Enter number of deals (simulations) : " << endl;

        cin >> numDeals;
        
        vector<Card> dealtCopy (numCards);

        for (unsigned i = 0; i < numDeals; i++) {
            for (unsigned j = 0; j < numCards; j++) {
                dealtCopy.at(j) = cardDeck.dealCard();
            }
            if (hasPair(dealtCopy)) {
                count += 1;
            }
            cardDeck.shuffleDeck();
        }

        cout << "Chances of receiving a pair in a hand of " << numCards << " cards is: ";

        cout << (count / numDeals) * 100 << "%" << endl;

    }

    

    return 0;
}