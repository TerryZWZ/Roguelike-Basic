#ifndef HUMAN_H
#define HUMAN_H

#include "enemy.h"

class Human: public AbstractEnemy {
    public:
        Human(int x, int y);
        int attack(AbstractCharacter* c) override;
};

#endif
