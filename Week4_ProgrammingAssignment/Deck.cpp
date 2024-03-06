#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
#include "Deck.h"
#include "Card.h"
using namespace std;


/* Constructs a Deck of 52 cards:
       Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
       Cards should start off in this order with the order of suits being:
       Clubs, Diamonds, Hearts, Spades. So, the Card at the top of the
       Deck should be the Ace of Clubs.
       
       For best efficiency, the top of Deck should be stored at 
       back end of vector.
    */
Deck::Deck() {
    for (unsigned i = 0; i < 4; i++) {

        for (unsigned j = 13; j > 0; j--) {
            if (i == 3) {
                Card c ('c', j);
                theDeck.push_back(c);
            }

            if (i == 2) {
                Card d ('d', j);
                theDeck.push_back(d);
            }

            if (i == 1) {
                Card h ('h', j);
                theDeck.push_back(h);
            }

            if (i == 0) {
                Card s ('s', j);
                theDeck.push_back(s);
            }
        }
    }
}

/* Deals (returns) the top card of the deck. 
    Removes this card from theDeck and places it in dealtCards.
    As mentioned in comments for the constructor, 
    for best efficiency, the top card should come from the 
    back end of vector.
*/
Card Deck::dealCard() {
    Card topOne;
    topOne = theDeck.back();
    theDeck.pop_back();
    dealtCards.push_back(topOne);
    return topOne;
}

/* Places all cards back into theDeck and shuffles them into random order.
    Use random_shuffle function from algorithm library.
    To pass test harness, this function must go forward through dealtCards
    pushing each Card onto the back end of theDeck, then clear dealtCards.
    Do not use pop_back on dealtCards.
*/
void Deck::shuffleDeck() {
    for (unsigned i = 0; i < dealtCards.size(); i++) {
        theDeck.push_back(dealtCards.at(i));
    }
    dealtCards.clear();
    random_shuffle(theDeck.begin(), theDeck.end());
}

/* returns the size of the Deck (how many cards have not yet been dealt).
*/
unsigned Deck::deckSize() const {
    return theDeck.size();
}