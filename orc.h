#ifndef ORC_H
#define ORC_H

#include "enemy.h"

class Orc: public AbstractEnemy {
    public:
        Orc(int x, int y);
        int attack(AbstractCharacter* c) override;
};

#endif
