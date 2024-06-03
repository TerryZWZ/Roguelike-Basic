#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"

class Vampire: public AbstractPlayer {
    public:
        Vampire(int x, int y);
        int attack(AbstractCharacter* c, string e) override;
};

#endif
