#ifndef _GAME_H
#define _GAME_H

#include "Deck.h"
#include "Player.h"

#include <vector>

class Game
{
public:
  // Constructor
  Game();

  // Destructor
  ~Game();

  // The main loop of the Crazy8s
  void startGame();

  // Each players get 5 cards
  void initPlayers();

  // Generate a new full deck and shuffle it
  void initCardsDeck();

  // Just shuffle cardsDeck
  void mixCardsDeck();

  // Shows the results of a finished Game
  void showTheResults() const;

  // Print all cards in the deck
  void printCardsDeck() const;

  // Print all cards in the playing pile
  void printPlayingPile() const;

  // Get a card from players and put it to the playing pile
  bool getCard(Card *c);

  // Deals a card to the current player
  Card *dealCard();

  // for debugging...
  void numbersInDecks() const;

private:
  vector<Player *> player;
  Deck *cardsDeck;
  Deck *playingPile;
  int eightsSuit;
  Card *eightsCard;
};

#endif
