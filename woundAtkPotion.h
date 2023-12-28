#ifndef POTION_POISON_ATK_H
#define POTION_POISON_ATK_H

#include "potion.h"

class woundAtkPotion: public Potion {
    public:
        woundAtkPotion(int x, int y);
        void applyEffect(AbstractPlayer* player) override;
};

#endif
