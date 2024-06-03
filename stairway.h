#ifndef STAIRWAY_H
#define STAIRWAY_H

#include "item.h"

class Stairway: public AbstractItem {
    public:
        Stairway(int x, int y);
        bool isPotion() override;
        bool isStairs() override;
        bool isGold() override;
        void applyEffect(AbstractPlayer* player) override;
        int getValue() override;
        string getName() override;
};

#endif
