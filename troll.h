#ifndef TROLL_H
#define TROLL_H

#include "player.h"

class Troll: public AbstractPlayer {
    public:
        Troll(int x, int y);
        void move(string override) override;
        int attack(AbstractCharacter* c, string e) override;
        void ability() override;
};

#endif
