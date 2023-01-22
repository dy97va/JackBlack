
#ifndef JACKBLACK_STRATEGY_H
#define JACKBLACK_STRATEGY_H
#include <string>

using std:: string;

const int MAX_HAND_VALUE = 21;
const int MIN_HAND_VALUE = 4;
const int NUM_DEALER_UPCARDS = 12;

// The strategy table
// The first dimension represents the player's hand value (5-20)
// The second dimension represents the dealer's upcard (2-11)
// The value in the table represents the recommended action
enum Action {
    HIT,
    STAND
};
class Strategy {
public:
    Action strategyTable[MAX_HAND_VALUE - MIN_HAND_VALUE + 1][NUM_DEALER_UPCARDS + 1] = {
            // 4
            { HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT },
            // 5
            { HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT },
            // 6
            { HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT },
            // 7
            { HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT },
            // 8
            { HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT },
            // 9
            { HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT },
            // 10
            { HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT },
            // 11
            { HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT, HIT },
            // 12
            { HIT, HIT, HIT, HIT, HIT, HIT, STAND, STAND, STAND, HIT, HIT, HIT, HIT },
            // 13
            { HIT, HIT, HIT, HIT, HIT, HIT, STAND, STAND, STAND, HIT, HIT, HIT, HIT },
            // 14
            { HIT, HIT, HIT, HIT, HIT, HIT, STAND, STAND, STAND, HIT, HIT, HIT, HIT },
            // 15
            { HIT, STAND, STAND,STAND, STAND, STAND,HIT, HIT, HIT, HIT, HIT, HIT, HIT },
            // 16
            { HIT, STAND, STAND,STAND, STAND, STAND,HIT, HIT, HIT, HIT, HIT, HIT, HIT },
            // 17
            { HIT, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND},
            // 18
            { STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND},
            // 19
            { STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND},
            // 20
            { STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND, STAND},
    };
};



#endif //JACKBLACK_STRATEGY_H
