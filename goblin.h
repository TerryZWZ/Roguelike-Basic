#ifndef GOBLIN_H
#define GOBLIN_H

#include "player.h"

class Goblin: public AbstractPlayer {
    public:
        Goblin(int x, int y);
        int attack(AbstractCharacter* c, string e) override;
        void ability() override;
};

#endif
