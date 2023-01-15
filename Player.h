//
// Created by Valentin Dyrda on 10.01.2023.
//

#ifndef JACKBLACK_PLAYER_H
#define JACKBLACK_PLAYER_H
#include "Card.h"
#include <vector>

class Player {
    public:
    std:: vector<Card> hand;
    std::string name;
    int totalBank = 1000;
    bool hasAce = false;
};


#endif //JACKBLACK_PLAYER_H
