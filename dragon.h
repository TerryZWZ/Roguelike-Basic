#ifndef DRAGON_H
#define DRAGON_H

#include "enemy.h"

class Dragon: public AbstractEnemy {
    public:
        Dragon(int x, int y);
        void move(string direction) override;
        int attack(AbstractCharacter* c) override;
};

#endif
