

#include <iostream>
#include "Game.h"

int main() {
    Game game;
    game.deckInit();
    game.rules();
    game.playRound();


    return 0;
}