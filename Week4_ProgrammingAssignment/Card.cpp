#include <iostream>
#include "Card.h"
using namespace std;


/* Assigns a default value of 2 of Clubs
*/
Card::Card() {
    this->suit = 'c';
    this->rank = 2;
}

/* Assigns the Card the suit and rank provided.
       suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
       If an invalid suit is provided, sets the suit to Clubs
       ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
       If an invalid rank is provided, sets the rank to 2
       Accepts lower or upper case characters for suit
*/
Card::Card(char type, int num) {
    this->suit = type;
    this->rank = num;
    
    if ((type != 'c') && (type != 'C') && (type != 'd') && (type != 'D') && (type != 'h') && (type != 'H') && (type != 's') && (type != 'S')) {
        this->suit = 'c';
    }

    if ((type == 'C')) {
        this->suit = 'c';
    }

    if ((type == 'D')) {
        this->suit = 'd';
    }

    if ((type == 'H')) {
        this->suit = 'h';
    }

    if ((type == 'S')) {
        this->suit = 's';
    }

    if ((num < 1) || (num > 13)) {
        this->rank = 2;
    }

}

/* Returns the Card's suit
*/
char Card::getSuit() const {
    return suit;
}

/* Returns the Card's rank as an integer
*/
int Card::getRank() const {
    return rank;
}

/* Outputs a Card in the following format: Rank of Suit
       For example, if the rank is 3 and the suit is h: 3 of Hearts
       Or, if the rank is 1 and the suit is d: Ace of Diamonds
       Or, if the rank is 12 and the suit is c: Queen of Clubs
       etc.
*/
ostream & operator<<(ostream &out, const Card &dealtCards) {

    if (dealtCards.suit == 'c') {
        if (dealtCards.rank == 11) {
            out << "Jack of Clubs";
        }

        else if (dealtCards.rank == 12) {
            out << "Queen of Clubs";
        }

        else if (dealtCards.rank == 13) {
            out << "King of Clubs";
        }

        else if (dealtCards.rank == 1) {
            out << "Ace of Clubs";
        }

        else {
            out << dealtCards.rank << " of Clubs";
        }
    }

    else if (dealtCards.suit == 'd') {
        if (dealtCards.rank == 11) {
            out << "Jack of Diamonds";
        }

        else if (dealtCards.rank == 12) {
            out << "Queen of Diamonds";
        }

        else if (dealtCards.rank == 13) {
            out << "King of Diamonds";
        }

        else if (dealtCards.rank == 1) {
            out << "Ace of Diamonds";
        }

        else {
            out << dealtCards.rank << " of Diamonds";
        }
    }

    else if (dealtCards.suit == 'h') {
        if (dealtCards.rank == 11) {
            out << "Jack of Hearts";
        }

        else if (dealtCards.rank == 12) {
            out << "Queen of Hearts";
        }

        else if (dealtCards.rank == 13) {
            out << "King of Hearts";
        }

        else if (dealtCards.rank == 1) {
            out << "Ace of Hearts";
        }

        else {
            out << dealtCards.rank << " of Hearts";
        }
    }

    else {
        if (dealtCards.rank == 11) {
            out << "Jack of Spades";
        }

        else if (dealtCards.rank == 12) {
            out << "Queen of Spades";
        }

        else if (dealtCards.rank == 13) {
            out << "King of Spades";
        }

        else if (dealtCards.rank == 1) {
            out << "Ace of Spades";
        }

        else {
            out << dealtCards.rank << " of Spades";
        }
    }

    return out;
}