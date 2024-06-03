#ifndef POTION_RESTORE_H
#define POTION_RESTORE_H

#include "potion.h"

class restoreHealthPotion: public Potion {
    public:
        restoreHealthPotion(int x, int y);
        void applyEffect(AbstractPlayer* player) override;
};

#endif
