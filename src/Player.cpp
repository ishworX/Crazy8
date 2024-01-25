#include "Player.h"

#include <iostream>
#include <fstream>
#include <string>

//***********************************************
// Function: play(Card* top);
// Purpose: To play a Card that is in the players hand
// Input: Card* top
// Return Value: nullptr if the player doesn't have a Card
// to play. top to quit the game. Pointer to the Card
// the player picked to play the Card.
//***********************************************
Card *Player::play(Card *top)
{
  int i = 0;

  cout << "Top Card : " << top->printCard() << endl
       << endl;

  if (human)
  { // If the player is human
    i = hi(top);

    // If human players want to play automatically
    if (!human)
      i = ai(top);
  }
  else
  {              // If the player isn't human -- sentient beings are scary
    i = ai(top); // AI will choose a playable Card
  }

  // If the player doesn't have a playable Card
  if (i == 0)
    return nullptr;

  // To quit the program
  // Returns the top card to quit the game
  else if (i == 99)
    return top;

  // Returns a pointer to play a card from the players hand
  else
    return onPlayersHand->pickCard(i);
}

//***********************************************
// Function: selectSuit()
// Purpose: To select a suit when the player plays an 8
// Input: None
// Return Value: int which references a suit
//***********************************************
const int Player::selectSuit()
{
  int x = 0;
  string input;

  // If the player is human
  if (human)
  {
    // Do while loop to choose a suit while
    // the players haven't chosen a valid option
    // This loop runs continuoisly until the user selects a valid input
    do
    {
      cout << "You have chosen to play an 8. Please declare a";
      cout << " suit for this 8 to take. " << endl;
      cout << "Select from the following: (1)Diamonds, (2)Spades,";
      cout << " (3)Hearts, (4) Clubs : ";

      getline(cin, input);

      // Switch to determine what to do based on the users input
      switch (input[0])
      {
      case '1':
        return 1;
      case '2':
        return 2;
      case '3':
        return 3;
      case '4':
        return 4;
      default:
        cout << "Please select a valid option" << endl;
      }
    } while (true);
  }
  else
  { // If the player isn't human
    // The AI will take modulo 4 their hand count, then add one.
    // This is the choise they will make
    // Modulo 4 options are 0, 1, 2, or 3.
    // We add one to make these the same returns as the human
    return (onPlayersHand->getRemaining() % 4) + 1;
  }
}

//***********************************************
// Function: hi(Card* top)
// Purpose: To be the human interface. Allows the human
// to make moves in the game, also get help
// Input: Card* top
// Return Value: integer 0  when their turn is done
//***********************************************
const int Player::hi(Card *top)
{
  string input;
  int number;

  do
  {
    // Showing the user their cards in hand
    cout << "===== Human Player =====" << endl;
    printCardsOnHand();
    cout << "========================" << endl;

    // Running the commands to get a command from the user
    commands();
    getline(cin, input);
    input = input.substr(0, 2);

    // Switch to do something based off the users input
    switch (input[0])
    {
    case 'a':
    case 'A':
      // Autoplay On
      setAutoPlay();
      cout << endl
           << "Autoplay started!!!!!" << endl;
      return 0;

    case 'q':
    case 'Q':
      // Quit the program
      return 99;

    case 'r':
    case 'R':
      // Show the user the rules to the game
      showRules(top);
      break;

    case 's':
    case 'S':
      // Show the player a suggestion of a card to play
      suggest(top);
      break;

    case '0':
      // Player draws a card
      number = stoi(input);
      cout << endl
           << "You drew a card" << endl;
      return 0;

    case '1' ... '9':
    {
      number = stoi(input);

      // If the player tries to play a card they don't have
      if (number < 1 || number > onPlayersHand->getRemaining())
      {
        cout << endl
             << "Out of range : Please select a valid card" << endl;
      }
      else
      { // If the player selects a valid card
        if (checkPlayable(top, number - 1))
        {
          return number;
        }
        else
        {
          cout << endl
               << "NO MATCH : Please select the right card!" << endl;
        }
      }
      cout << endl;
      cout << "Reminder: The top card is: " << top->printCard() << endl;
      break;
    }

    default:
      cout << endl
           << "Please select a valid option" << endl;
      cout << endl;
      cout << "Reminder: The top card is: " << top->printCard() << endl;
      break;
    }
  } while (true);

  return 0;
}

//***********************************************
// Function:ai(Card* top)
// Purpose: Gives the strategy for the AI player
// Input: Card* top
// Return Value: integer x which refers to the card to play.
// Returns 0 if there is no match
//***********************************************
const int Player::ai(Card *top)
{
  int x = 0;

  if (strategy)
  { // Suit first...
    x = findMatchingSuit(top->getSuit());
    if (x == 0)
    {                          // if there's no match with suit
      if (top->getRank() == 8) // play8s first
        x = findMatchingRank(8);
      else
        x = findMatchingRank(top->getRank());
    }
  }
  else
  {                          // Rank first...
    if (top->getRank() == 8) // play8s first
      x = findMatchingRank(8);
    else
      x = findMatchingRank(top->getRank());

    if (x == 0) // if there's no match with rank
      x = findMatchingSuit(top->getSuit());
  }

  return x;
}

//***********************************************
// Function:findMatchingSuit(int x)
// Purpose: Finds a Card with matching suit in the players hand
// Input: int x
// Return Value: Returns the position of the matching Card or
// Returns 0 if there is no match
//***********************************************
const int Player::findMatchingSuit(const int &x) const
{
  for (int i = 0; i < onPlayersHand->getRemaining(); i++)
  {
    if (onPlayersHand->getCardInfo(i)->getSuit() == x)
    {
      return i + 1;
    }
  }
  return 0;
}

//***********************************************
// Function:findMatchingRank(int x)
// Purpose: Finds a Card with matching rank in the players hand
// Input: int x
// Return Value: Returns the position of the matching Card or
// Returns 0 if there is no match
//***********************************************
const int Player::findMatchingRank(const int &x) const
{
  for (int i = 0; i < onPlayersHand->getRemaining(); i++)
  {
    // The game will try and play an 8 first if available
    if ((onPlayersHand->getCardInfo(i)->getRank() == x) ||
        (onPlayersHand->getCardInfo(i)->getRank() == 8))
      return i + 1;
  }
  return 0;
}

//***********************************************
// Function: checkPlayable(Card* top, int input)
// Purpose: Checks to see if the player has a playable Card
// Input: Card* top, int input
// Return Value: True if the Card is playable, false otherwise
//***********************************************
bool Player::checkPlayable(Card *top, int input) const
{
  if (onPlayersHand->getCardInfo(input)->getRank() == 8)
  {
    return true;
  }
  else if (onPlayersHand->getCardInfo(input)->getRank() == top->getRank())
  {
    cout << endl
         << "**** You chose The Same Rank ****" << endl;
    return true;
  }
  else if (onPlayersHand->getCardInfo(input)->getSuit() == top->getSuit())
  {
    cout << endl
         << "**** You chose The Same Suit ****" << endl;
    return true;
  }
  else
  {
    return false;
  }
}

//***********************************************
// Function: suggest(Card* top)
// Purpose: Suggests a Card for the user to play
// Input: Card* top
// Return Value: None
//***********************************************
void Player::suggest(Card *top) const
{
  int x = 0;

  cout << endl
       << "=================================" << endl
       << "You can select... ";

  x = findMatchingSuit(top->getSuit());

  if (x != 0)
    cout << x << " or ";

  x = findMatchingRank(top->getRank());
  if (x != 0)
    cout << x << " or ";
  cout << "0" << endl
       << "=================================" << endl
       << endl;
  cout << "Reminder: The top card is: " << top->printCard() << endl;
}

//***********************************************
// Function: commands()
// Purpose: Gives the user a list of commands they can enter
// Input: None
// Return Value: None
//***********************************************
void Player::commands() const
{
  cout << endl;
  cout << "Enter the command : (R)ules, (S)uggesting a card, ";
  cout << "(A)utoplay, (Q)uit the game" << endl;
  cout << "or Please select a card from 1 to ";
  cout << onPlayersHand->getRemaining() << endl;
  cout << "Input 0 to draw a card : ";
}

//***********************************************
// Function: showRules(Card* top)
// Purpose: Shows the rules of the game to the user
// Input: Card* top
// Return Value: None
//***********************************************
void Player::showRules(Card *top)
{
  cout << endl;
  string reading;
  ifstream inFile;

  inFile.open("./Rules.txt");

  while (!inFile.eof() && !inFile.fail())
  {
    getline(inFile, reading);
    cout << reading << endl;
  }

  inFile.close();
  cout << endl;

  cout << "Reminder: The top card is: " << top->printCard() << endl;

  return;
}

//***********************************************
// Function: getCard(Card* c)
// Purpose: Draws a card from the cardsDeck
// Input: Card* c
// Return Value: False if a nullptr wwas passed, True otherwise
//***********************************************
bool Player::getCard(Card *c)
{
  if (c == nullptr)
    return false;

  onPlayersHand->getCard(c);
  return true;
}

//***********************************************
// Function: printCardsOnHand()
// Purpose: Prints the Cards to user has to the screen
// Input: None
// Return Value: None
//***********************************************
void Player::printCardsOnHand() const
{
  onPlayersHand->printDeck();
}

//***********************************************
// Function: isWinner()
// Purpose: Checks to see if the game has a winner yet
// Input: None
// Return Value: True if there's a winner, otherwise false
//***********************************************
bool Player::isWinner() const
{
  if (onPlayersHand->getRemaining() == 0)
    return true;
  else
    return false;
}

//***********************************************
// Function: score()
// Purpose: Calculates a player's score at the end of the game
// Input: None
// Return Value: Integer of the player's score
//***********************************************
// Calculate a Player's Score
const int Player::score()
{
  int x = 0;
  int temp = 0;
  for (int i = 0; i < onPlayersHand->getRemaining(); i++)
  {
    temp = onPlayersHand->getCardInfo(i)->getRank();
    if (temp > 9)
      x += 10;
    else if (temp == 8)
      x += 50;
    else
      x += temp;
  }

  return x;
}

//***********************************************
// Function: setAutoPlay()
// Purpose: Play games automatically
// Input: None
// Return Value: None
//***********************************************
void Player::setAutoPlay()
{
  human = false;
}
