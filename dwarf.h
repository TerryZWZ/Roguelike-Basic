#ifndef DWARF_H
#define DWARF_H

#include "enemy.h"

class Dwarf: public AbstractEnemy {
    public:
        Dwarf(int x, int y);
        int attack(AbstractCharacter* c) override;
};

#endif
