//
// Created by Valentin Dyrda on 10.01.2023.
//

#ifndef JACKBLACK_GAME_H
#define JACKBLACK_GAME_H
#include "Card.h"
#include "Player.h"


class Game {
public:
    int playerHandValue;
    int dealerHandValue;
    Player player1;
    Player dealer;
    int bet;
    Card deck[52];
    void rules();
    void playRound();
    void deckInit();
    void swap(Card *a, Card *b);
    void shuffleDeck(Card deck[]);
    void displayCard(Card card);
    void dealToPlayer();
    void dealToDealer();
    void checkForBJorBust();
    void hitOrStay();
    void playAgain();
    void dealerReveal();
    void dealerAction();
    void compareHands();
    void showPlayerHand();
};

#endif //JACKBLACK_GAME_H
