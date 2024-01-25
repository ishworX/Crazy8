#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

class Card
{
public:
  // Default constructor for class object Card -- is empty
  Card() {}

  // Constructor for a class object Card given its Suit and Rank
  Card(int r, int s) : rank(r), suit(s) {}

  // Converts an int to be a string
  const string rankToString() const;

  // Converts type Suit into string
  const string suitToString() const;

  // Converts both type Rank and type Suit into string
  const string printCard() const;

  // Getter for Rank of a Card
  const int &getRank() const;

  // Getting for Suit of a Card
  const int &getSuit() const;

  // Setter for Suit of a Card
  void setSuit(const int &s);

private:
  // The respectives suits and ranks for the Card
  int rank;
  int suit;
};

#endif
