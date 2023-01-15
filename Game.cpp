//
// Created by Valentin Dyrda on 10.01.2023.
//

#include <iostream>
#include "Game.h"
using std::cout, std::cin;

void Game:: playRound() {
    cout << " ----------------------------- \n";
    cout << "|                             |\n";
    cout << "|make a bet between 5 and 100 |" << "\n";
    cout << "|                             |\n";
    cout << " ----------------------------- \n";
    cout << "--->";
    cin >> bet;
    cout << "Your bet is accepted \n";
    player1.totalBank -= bet;

    dealToPlayer();
    dealToDealer();
    dealToPlayer();
    dealToDealer();

    cout << "Dealer dealt you and himself 2 cards" << "\n";
    cout << "  " << "\n";
    cout << "Your hand: \n";
    showPlayerHand();
    cout << "\n";
    cout << "And dealer's hand is: \n";
    cout << "* *  ";
    for (int i = 1; i < dealer.hand.size(); i++){
        displayCard(dealer.hand[i]);
        cout << "  \n";
    }
    hitOrStay();
}

void Game:: playAgain() {
    char yesOrNo;
    player1.hand.clear();
    dealer.hand.clear();
    cout << "would you like to start a new round?\n";
    cout << "Enter Y for Yes or N for No\n";
    cout << "--->";
    cin >> yesOrNo;
    if (yesOrNo == 'N' || yesOrNo == 'n') {
        cout << "You are leaving with " << player1.totalBank << " in your poket!\n";
        cout << "It was a pleasure playing with you\n";
        cout << "Welcome back any time!";
        exit(0);
    } else if (yesOrNo == 'y' || yesOrNo == 'Y') {
        playRound();
    } else {
        cout << "invalid choice, please choose:\n";
        playAgain();
    }
}

void Game:: dealerAction() {
    int dHandValue = 0;
    int dHandValue2 = 0;

    for (int i = 0; i < dealer.hand.size(); i++) {
        if (dealer.hand[i].value == 1) {
            dHandValue += 11;
        } else if (dealer.hand[i].value > 10) {
            dHandValue += 10;
        } else {
            dHandValue += dealer.hand[i].value;
        }
    }
    for (int i = 0; i < dealer.hand.size(); i++) {
        if (dealer.hand[i].value > 10) {
            dHandValue2 += 10;
        } else {
            dHandValue2 += dealer.hand[i].value;
        }
    }

    if (dHandValue2 > 21) {
        cout << "Dealer busted, you win twice your bet\n";
        player1.totalBank += (bet*2);
        cout << "Your total bank is now equal to " << player1.totalBank << "\n\n";
        playAgain();
    } else if (dHandValue == 21 || dHandValue2 == 21) {
        cout << "Dealer got a Blac Jack, you lost your bet \n\n";
        playAgain();
    }

    if (dHandValue < 22) {
        dealerHandValue = dHandValue;
    } else {
        dealerHandValue = dHandValue2;
    }

    if (dealerHandValue < playerHandValue && dealerHandValue < 17) {
        cout << "dealer took one more card \n";
        dealToDealer();
        dealerReveal();
        dealerAction();
    } else {
        compareHands();
    }
}

void Game:: compareHands() {
    if (dealerHandValue < playerHandValue) {
        cout << "Your hand is bigger than dealers, you win twice your bet\n";
        player1.totalBank += bet*2;
        cout << "Yor total bank is now " << player1.totalBank << "\n\n";
        playAgain();
    } else if (dealerHandValue == playerHandValue) {
        cout << "You draw with dealer, you lose your bet\n";
        cout << "Yor total bank is now " << player1.totalBank << "\n\n";
        playAgain();
    } else {
        cout << "dealer wins, you lose ypur bet\n";
        cout << "Yor total bank is now " << player1.totalBank << "\n\n";
        playAgain();
    }
}

void Game:: hitOrStay(){
    char hs = 's';
    cout << "\n";
    cout << "Would you like to Stand or Hit\n";
    cout << "Enter S for stand or H for Hit\n";
    cout << "--->";
    cin >> hs;

    if (hs == 'H' || hs == 'h') {
        dealToPlayer();
        cout << "dealer gave you one more card, it is: \n";
        showPlayerHand();
        cout << "\n";
        checkForBJorBust();
    } else if (hs == 'S' || hs == 's') {
        cout << "Your hand is: \n";
        showPlayerHand();
        cout << "\n\n";
        cout << "And dealers hand is: \n";
        dealerReveal();
        cout << "\n\n";
        checkForBJorBust();
        dealerAction();
    } else {
        cout << "this is not a valid answer, please choose H for hit of S for stay \n";
        hitOrStay();
    }
}

void Game:: checkForBJorBust() {
    int pHandValue = 0;
    int pHandValue2 = 0;

    for (int i = 0; i < player1.hand.size(); i++) {
        if (player1.hand[i].value == 1) {
            pHandValue2 += 11;
        } else if (player1.hand[i].value > 10) {
            pHandValue2 += 10;
        } else {
            pHandValue2 += player1.hand[i].value;
        }
    }

    for (int i = 0; i < player1.hand.size(); i++) {
        if (player1.hand[i].value < 11) {
            pHandValue += player1.hand[i].value;

        } else {
            pHandValue += 10;
        }
    }

    if (pHandValue > 21) {
        cout << "You busted! You, bastard \n";
        cout << "your total bank is now equal to " << player1.totalBank << "\n\n";
        playAgain();
    } else if (pHandValue == 21 || pHandValue2 == 21) {
        cout << " You got a Black Jack! \n";
        cout << " You win 1.5 times your bet\n";
        player1.totalBank += (bet*1.5);
        cout << "your total bank is now equal to " << player1.totalBank << "\n\n";
        playAgain();
    }

    if (pHandValue2 < 22) {
        playerHandValue = pHandValue2;
    } else {
        playerHandValue = pHandValue;
    }

}

void Game:: displayCard(Card card) {
    if(card.value > 1 && card.value < 11) {
        cout << card.value;
    } else if(card.value == 1) {
        cout << "A";
    } else if(card.value == 11) {
        cout << "J";
    } else if(card.value == 12) {
        cout << "Q";
    } else {
        cout << "K";
    }

    if (card.suit == 1){
        cout << " ♠";
    } else if(card.suit == 2) {
        cout << " ♥";
    } else if (card.suit == 3) {
        cout << " ♦";
    } else {
        cout << " ♣";
    }
}

void Game:: showPlayerHand() {
    for (int i = 0; i < player1.hand.size(); i++){
        displayCard(player1.hand[i]);
        cout << "   ";
    }
}

void Game::  dealerReveal() {
    for (int i = 0; i < dealer.hand.size(); i++) {
        displayCard(dealer.hand[i]);
        cout << "  ";
    }
}

void Game:: dealToPlayer() {
    Card card = deck[51];
    player1.hand.push_back(card);
    if (card.value == 1) {
        player1.hasAce = true;
    }
    for (int i = 51; i > 0; i--) {
        deck[i] = deck[i - 1];
    }
    deck[0] = card;
}

void Game:: dealToDealer() {
    Card card = deck[51];
    if (card.value == 1) {
        dealer.hasAce = true;
    }
    dealer.hand.push_back(card);
    for (int i = 51; i > 0; i--) {
        deck[i] = deck[i - 1];
    }
    deck[0] = card;
}

void Game:: deckInit() {
    int i = 0;
    for(int suit = 1; suit < 5; suit++) {
        for(int value = 1; value < 14; value++) {
            if (deck[i].value == 1) {
                deck[i].ace = true;
            }
            deck[i].suit = suit;
            deck[i].value = value;
            i++;
        }
    }

    shuffleDeck(deck);
}

void Game:: swap(Card *a, Card *b) {
    Card temp = *a;
    *a = *b;
    *b = temp;
}

void Game:: shuffleDeck(Card deck[]) {
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&deck[i], &deck[j]);
    }
}

void Game:: rules(){
    cout<<" ------------------------------------------- "<<"\n";
    cout<<"|         Welcome to blackjack house        |"<<"\n";
    cout<<"| The Rules Are Simple:                     |"<<"\n";
    cout<<"| Aces can be either 1 or 11 points         |"<<"\n";
    cout<<"| In case of a tie dealer wins              |"<<"\n";
    cout<<"| If you get 21 - you win automatically     |"<<"\n";
    cout<<" ------------------------------------------- "<<std::endl;
}


