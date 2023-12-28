#ifndef DROW_H
#define DROW_H

#include "player.h"

class Drow: public AbstractPlayer {
    public:
        Drow(int x, int y);
        int attack(AbstractCharacter* c, string e) override;
};

#endif
