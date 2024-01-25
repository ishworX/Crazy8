#ifndef _DECK_H
#define _DECK_H

#include "Card.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cassert>
#include <random>

using std::vector;

class Deck
{
public:
   // Default constructor for a deck
   Deck();

   // Destructor
   ~Deck();

   // Prints deck out to the console
   void printDeck() const;

   // THE LAST CARD in the Deck is THE TOP CARD
   void showTopCard() const;

   // Return the Top Card in the Deck
   // The last card in the vector is the TOP CARD!!!
   Card *getTopCard() const;

   // Generate a full Deck for a new game!!!
   bool newFullDeck();

   // Shuffles the current deck
   void shuffleDeck();

   // Deals a card to the current player
   Card *dealCard();

   // Get a card from the deck
   bool getCard(Card *c);

   // Pick a card to play games!
   // (int pick) from players starts from 1.
   Card *pickCard(const int &pick);

   // Returns the remaining amount of cards in the deck
   const int getRemaining() const;

   // Returns the Card info
   Card *getCardInfo(const int &i) const;

private:
   // A vector that is used to store the deck
   vector<Card *> deck;
};

#endif
