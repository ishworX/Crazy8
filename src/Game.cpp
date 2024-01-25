#include "Game.h"

#include <iostream>

//***********************************************
// Function: Game()
// Purpose: Default constructor fow making a new Game
// Input: None
// Return Value: None
//***********************************************
Game::Game()
{
  Player *p1 = new Player(true); // Human
  // Player* p1 = new Player(false, true); // For Debugging...
  Player *p2 = new Player(false, true);
  Player *p3 = new Player(false, false);
  player.push_back(p1);
  player.push_back(p2);
  player.push_back(p3);

  eightsSuit = 0;                       // For storing the Suit from players who play 8s
  eightsCard = new Card(8, eightsSuit); // a Dummy card for 8s
  cardsDeck = new Deck;
  playingPile = new Deck;
  initCardsDeck();
  initPlayers();
  getCard(dealCard()); // for the first card on the playingPile
}

//***********************************************
// Function: ~Game()
// Purpose: Destructor for Game
// Input: None
// Return Value: None
//***********************************************
Game::~Game()
{
  delete cardsDeck;
  delete playingPile;
  delete eightsCard;

  if (player.size() != 0)
    for (auto a : player)
      delete a;
}

//***********************************************
// Function: startGame()
// Purpose: Main loop of the Game, also starts the Game
// Input: None
// Return Value: None
//***********************************************
void Game::startGame()
{
  cout << "If you need help, or would like ";
  cout << " a suggestion for a card to play: on your turn,";
  cout << " there will be a prompt." << endl;
  while (true)
  {
    for (int i = 0; i < static_cast<int>(player.size()); i++)
    {
      cout << endl
           << "======== Player " << i + 1 << " ========" << endl;
      player[i]->printCardsOnHand(); // for debugging
      cout << endl
           << "======== Player " << i + 1 << " ========" << endl;

      // Players turn...
      Card *c;
      if (eightsSuit == 0) // IF the top card of playingPile is not 8s card
        c = player[i]->play(playingPile->getTopCard());
      else // IF the top card of playingPile is 8s card
        c = player[i]->play(eightsCard);

      if ((c == playingPile->getTopCard()) || (c == eightsCard))
      {
        cout << "Bye!!!!!!!" << endl
             << endl;
        return;
      }
      else if (c != nullptr)
      { // When Players can play
        cout << "--> Player to PlayingPile : " << c->printCard() << endl;
        eightsSuit = 0;   // reset the Suit
        this->getCard(c); // if players can play

        // When player played 8s card
        if (c->getRank() == 8)
        {                                       // asks playeres which suit
          eightsSuit = player[i]->selectSuit(); // Get players selected Suit
          eightsCard->setSuit(eightsSuit);      // Update the dummy 8s card
        }
      }
      else
      { // When players don't have any matched cards...
        cout << "<-- NO MATCH on Player's Hand" << endl;
        player[i]->getCard(dealCard()); // if players can't play, get a card
      }

      // Check if a current player is winner...
      if (player[i]->isWinner())
      {
        cout << endl
             << "========== Congratulations!!! ==========" << endl;
        cout << "      The Winner is Player " << i + 1 << " !!!" << endl;
        cout << "========================================" << endl
             << endl;
        showTheResults();
        return;
      }

      // When there's no card on the cardsDeck
      if (cardsDeck->getRemaining() == 0)
      {
        cout << endl
             << "====== No More Cards";
        cout << " in the CardsDeck ======" << endl;
        cout << "============ There No Winner... ============" << endl;
        showTheResults();
        return;
      }
    }
  }
}

//***********************************************
// Function: initPlayers()
// Purpose: Initiates the Players to have 5 Cards in their hand
// Input: None
// Return Value: None
//***********************************************
void Game::initPlayers()
{
  for (auto a : player)
    for (int i = 0; i < 5; i++)
      a->getCard(dealCard());
}

//***********************************************
// Function: initCardsDeck()
// Purpose: Initiates a Deck to be full of Cards and shuffles it
// Input: None
// Return Value: None
//***********************************************
void Game::initCardsDeck()
{
  cardsDeck->newFullDeck();
  cardsDeck->shuffleDeck();
}

//***********************************************
// Function: mixCardsDeck
// Purpose: Shuffles the Deck of Cards
// Input: None
// Return Value: None
//***********************************************
void Game::mixCardsDeck()
{
  cardsDeck->shuffleDeck();
}

//***********************************************
// Function: showTheResults
// Purpose: Shows the reults of a finished Game to the user
// Input: None
// Return Value: None
//***********************************************
void Game::showTheResults() const
{
  for (int i = 0; i < static_cast<int>(player.size()); i++)
  {
    cout << "## Player " << i + 1 << "'s Score : ";
    cout << player[i]->score() << endl;
  }
  cout << endl;
  printPlayingPile(); // To check playing pile deck
}

//***********************************************
// Function: printCardsDeck()
// Purpose: Prints the Cards in the Deck to the user
// Input: None
// Return Value: None
//***********************************************
void Game::printCardsDeck() const
{
  cout << "====== Deck ======" << endl;
  cardsDeck->printDeck();
  cout << "==================" << endl;
}

//***********************************************
// Function: printPlayingPile()
// Purpose: Prints all Cards in the playing pile
// Input: None
// Return Value: None
//***********************************************
void Game::printPlayingPile() const
{
  cout << "====== Pile ======" << endl;
  playingPile->printDeck();
  cout << "==================" << endl;
}

//***********************************************
// Function: getCard(Card* c)
// Purpose: Gets a Card from a Player and puts it into the playing pile
// Input: Card* c
// Return Value: Returns false if a nullptr is passed.
// Otherwise returns true
//***********************************************
bool Game::getCard(Card *c)
{
  if (c == nullptr)
    return false;

  playingPile->getCard(c);
  return true;
}

//***********************************************
// Function: dealCard()
// Purpose: Deals a Card to the current Player
// Input: None
// Return Value: Card*
//***********************************************
Card *Game::dealCard()
{
  if (cardsDeck->getRemaining() == 0)
    return nullptr;

  return cardsDeck->dealCard();
}

//***********************************************
// Function: numberInDeck()
// Purpose: Just a debugging tool to help implement the project
// Input: None
// Return Value: None
//***********************************************
void Game::numbersInDecks() const
{
  cout << "### Cards Deck: " << cardsDeck->getRemaining() << endl;
  cout << "### Playing Pile: " << playingPile->getRemaining() << endl;
}
