#ifndef HALFLING_H
#define HALFLING_H

#include "enemy.h"

class Halfling: public AbstractEnemy {
    public:
        Halfling(int x, int y);
        int attack(AbstractCharacter* c) override;
        void ability(AbstractPlayer* p);
};

#endif
