#ifndef ELF_H
#define ELF_H

#include "enemy.h"

class Elf: public AbstractEnemy {
    public:
        Elf(int x, int y);
        int attack(AbstractCharacter* c) override;
};

#endif
