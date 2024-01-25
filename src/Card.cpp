#include "Card.h"

#include <iostream>
#include <string>

//***********************************************
// Function: rankToString()
// Purpose: Converts an int to be a string
// Input: None
// Return Value: String of the rank
//***********************************************
const string Card::rankToString() const
{
  string rankString;

  // use switch to convert number
  // to card rank
  switch (rank)
  {
  case 1:
    rankString = "Ace";
    break;
  case 2:
    rankString = "Two";
    break;
  case 3:
    rankString = "Three";
    break;
  case 4:
    rankString = "Four";
    break;
  case 5:
    rankString = "Five";
    break;
  case 6:
    rankString = "Six";
    break;
  case 7:
    rankString = "Seven";
    break;
  case 8:
    rankString = "Eight";
    break;
  case 9:
    rankString = "Nine";
    break;
  case 10:
    rankString = "Ten";
    break;
  case 11:
    rankString = "Jack";
    break;
  case 12:
    rankString = "Queen";
    break;
  case 13:
    rankString = "King";
    break;
    // This part is just for debugging
  default:
    rankString = "Something is Wrong...";
    break;
  }

  return rankString;
}

//***********************************************
// Function: suitToString
// Purpose: Converts type Suit into a string
// Input: None
// Return Value: string of the Suit
//***********************************************
const string Card::suitToString() const
{
  string suitString;
  // switch to get suit type
  switch (suit)
  {
  case 1:
    suitString = "Diamonds";
    break;
  case 2:
    suitString = "Spades";
    break;
  case 3:
    suitString = "Hearts";
    break;
  case 4:
    suitString = "Clubs";
    break;
  default:
    suitString = "Something is Wrong...";
    break;
  }

  return suitString;
}

//***********************************************
// Function: printCard()
// Purpose: prints the Card out to the user
// Input: None
// Return Value: string of the Card
//***********************************************
const string Card::printCard() const
{
  return rankToString() + " of " + suitToString() + "";
}

//***********************************************
// Function: getRank()
// Purpose: Gets the rank of a Card
// Input: None
// Return Value: integer of the rank
//***********************************************
// Getter for Rank of a Card
const int &Card::getRank() const
{
  return rank;
}

//***********************************************
// Function: getSuit()
// Purpose: Gets the suit of a Card
// Input: None
// Return Value: integer of the suit
//***********************************************
const int &Card::getSuit() const
{
  return suit;
}

//***********************************************
// Function: setSuit()
// Purpose: Sets thesuit of a Card
// Input: None
// Return Value: None
//***********************************************
// Setter for Suit of a Card
void Card::setSuit(const int &s)
{
  suit = s;
}
