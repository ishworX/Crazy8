#include "Deck.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cassert>
#include <random>

using std::default_random_engine;
using std::random_device;

//***********************************************
// Function: Deck()
// Purpose: Deck constructor
// Input: None
// Return Value: None
//***********************************************
Deck::Deck()
{
}

//***********************************************
// Function: ~Deck()
// Purpose: Deck destructor
// Input: None
// Return Value: None
//***********************************************
Deck::~Deck()
{
  if (deck.size() != 0)
    for (auto a : deck)
      delete a;
}

//***********************************************
// Function: printDeck()
// Purpose: Prints the deck out to the user
// Input: None
// Return Value: None
//***********************************************
void Deck::printDeck() const
{
  if (deck.empty())
  {
    cout << "The Deck is empty!!!" << endl;
  }
  else
  {
    for (int i = 0; i < static_cast<int>(deck.size()); i++)
      cout << i + 1 << " : " << deck[i]->printCard() << endl;
  }
}

//***********************************************
// Function: showTopCard()
// Purpose: Shows the "top" card of the deck to the user
//-- store in end of vector
// Input: None
// Return Value: None
//***********************************************
void Deck::showTopCard() const
{
  if (deck.empty())
    cout << "The deck is empty!!" << endl;
  else
    cout << deck.back()->printCard() << endl;
}

//***********************************************
// Function: getTopCard()
// Purpose: Gets the "top" Card of the Deck
// Input: None
// Return Value: ullptr if there is no Cards left in the Deck.
// Otherwise returns the "top" Card of the Deck
//***********************************************
Card *Deck::getTopCard() const
{
  if (deck.empty())
  {
    cout << "The deck is empty!!" << endl;
    return nullptr;
  }
  else
  {
    return deck.back();
  }
}

//***********************************************
// Function: newFullDeck()
// Purpose: Generates a full Deck for the start of the game
// Input: None
// Return Value: True if the Deck is empty and a new one can
// be generated. Otherwise returns false
//***********************************************
bool Deck::newFullDeck()
{
  if (deck.empty())
  {
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 13; j++)
      {
        Card *c = new Card(j + 1, i + 1);
        deck.push_back(c);
      }
    }
    return true;
  }
  else
  {
    return false;
  }
}

//***********************************************
// Function: shuffleDeck()
// Purpose: Shuffles the current Deck
// Input: None
// Return Value: None
//***********************************************
// Shuffles the current deck
void Deck::shuffleDeck()
{
  random_device rdevice{};
  default_random_engine random{rdevice()};
  shuffle(deck.begin(), deck.end(), random);
}

//***********************************************
// Function: dealCard
// Purpose: Deals a Card from the Deck to the current Player
// Input: None
// Return Value: Returns nullptr is the Deck is empty.
// Otherwise returns the Card to be dealt
//***********************************************
Card *Deck::dealCard()
{
  if (deck.empty())
  {
    return nullptr;
  }
  else
  {
    Card *c = deck.back();
    deck.pop_back();
    return c;
  }
}

//***********************************************
// Function: getCard(Card* c)
// Purpose: Gets a specific Card from the Deck
// Input: Card* c
// Return Value: Returns false if Card* c is a nullptr.
// Otherwise returns true
//***********************************************
bool Deck::getCard(Card *c)
{
  if (c == nullptr)
  {
    return false;
  }
  else
  {
    deck.push_back(c);
    return true;
  }
}

//***********************************************
// Function: pickCard()
// Purpose: Picks a Card to play Game
// Input: int pick
// Return Value: Card*
//***********************************************
Card *Deck::pickCard(const int &pick)
{
  Card *c = deck[pick - 1];
  deck.erase(deck.begin() + (pick - 1));
  return c;
}

//***********************************************
// Function: getRemaining()
// Purpose: Gets the number of remaining Cards in the Deck
// Input: None
// Return Value: Integer of the remaining number of Cards in the Deck
//***********************************************
const int Deck::getRemaining() const
{
  return deck.size();
}

//***********************************************
// Function: getCardInfo(int i)
// Purpose: Gets the information of a Card
// Input: int i
// Return Value: deck[i]
//***********************************************
Card *Deck::getCardInfo(const int &i) const
{
  return deck[i];
}
