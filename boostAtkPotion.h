#ifndef POTION_BOOST_ATK_H
#define POTION_BOOST_ATK_H

#include "potion.h"

class boostAtkPotion: public Potion {
    public:
        boostAtkPotion(int x, int y);
        void applyEffect(AbstractPlayer* player) override;
};

#endif
