#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"

class Merchant: public AbstractEnemy {
    public:
        Merchant(int x, int y);
        int attack(AbstractCharacter* c) override;
};

#endif
