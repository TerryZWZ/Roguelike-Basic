#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "player.h"


class Potion: public AbstractItem {
    string name;
    public:
        Potion(int x, int y, string name);
        bool isPotion() override;
        bool isStairs() override;
        bool isGold() override;
        void applyEffect(AbstractPlayer* player) override;
        int getValue() override;
        string getName() override;
};


#endif
