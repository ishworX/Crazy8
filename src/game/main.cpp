#include "Game.h"

int main()
{
    Game g;
    cout << "====== init ======" << endl;
    g.printPlayingPile();
    g.numbersInDecks();
    cout << endl
         << endl;
    g.startGame();
    return 0;
}
