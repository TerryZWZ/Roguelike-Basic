#ifndef SHADE_H
#define SHADE_H

#include "player.h"

class Shade: public AbstractPlayer {
    public:
        Shade(int x, int y);
        int attack(AbstractCharacter* c, string e) override;
};

#endif
