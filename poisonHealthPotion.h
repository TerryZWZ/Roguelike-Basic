#ifndef POTION_POISON_HEALTH_H
#define POTION_POISON_HEALTH_H

#include "potion.h"

class poisonHealthPotion: public Potion {
    public:
        poisonHealthPotion(int x, int y);
        void applyEffect(AbstractPlayer* player) override;
};

#endif
