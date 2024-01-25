#ifndef _Player_H
#define _Player_H

#include "Deck.h"

class Player
{
public:
  // Constructors
  Player() : human(false), strategy(false)
  {
    onPlayersHand = new Deck;
  }

  // Constructor for a potential Human player with no strategy
  Player(bool h) : human(h), strategy(false)
  {
    onPlayersHand = new Deck;
  }

  // Constructor for a potential human with a potential strategy
  Player(bool h, bool s) : human(h), strategy(s)
  {
    onPlayersHand = new Deck;
  }

  // Destructor
  ~Player()
  {
    delete onPlayersHand;
  }

  // The Main Function for Players
  Card *play(Card *top);

  // When players play 8s, players will also select the Suit
  const int selectSuit();

  // Human interface
  const int hi(Card *top);

  // CI interface
  const int ai(Card *top);

  // Finds a matching suit
  const int findMatchingSuit(const int &x) const;

  // Finds a matching rank
  const int findMatchingRank(const int &x) const;

  // Checks to see if the player has a playable card
  bool checkPlayable(Card *top, int input) const;

  // Suggest a card to the player
  void suggest(Card *top) const;

  // Gives the user their list of commands available to them
  void commands() const;

  // Shows the user the rules to the game
  void showRules(Card *top);

  // Get a card from the cardsDeck
  bool getCard(Card *c);

  // Print all cards on players' hand
  void printCardsOnHand() const;

  // Check if the player is the Winner!
  bool isWinner() const;

  // Calculate a Player's Score
  const int score();

  // Play games automatically
  void setAutoPlay();

private:
  Deck *onPlayersHand;
  bool human;
  bool strategy;
};

#endif
