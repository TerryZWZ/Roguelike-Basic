#ifndef GOLD_H
#define GOLD_H

#include "item.h"

using namespace std;

class Gold: public AbstractItem {
    public:
        Gold(int x, int y, int value);
        int value;

        void applyEffect(AbstractPlayer* player) override;
        bool isPotion() override;
        bool isStairs() override;
        bool isGold() override;
        int getValue() override;
        string getName() override;
};


#endif
