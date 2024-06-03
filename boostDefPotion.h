#ifndef POTION_BOOST_DEF_H
#define POTION_BOOST_DEF_H

#include "potion.h"

class boostDefPotion: public Potion {
    public:
        boostDefPotion(int x, int y);
        void applyEffect(AbstractPlayer* player) override;
};

#endif
