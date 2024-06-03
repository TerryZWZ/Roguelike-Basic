#ifndef POTION_POISON_DEF_H
#define POTION_POISON_DEF_H

#include "potion.h"

class woundDefPotion: public Potion {
    public:
        woundDefPotion(int x, int y);
        void applyEffect(AbstractPlayer* player) override;
};

#endif
