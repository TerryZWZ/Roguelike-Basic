#ifndef CELL_H
#define CELL_H

#include "character.h"
#include "player.h"
#include "enemy.h"
#include "decorator.h"
#include "item.h"
#include "gold.h"
#include "potion.h"
#include "stairway.h"

#include <iostream>
#include <memory>

class AbstractCell {
    protected:
        int x, y;
        char displayChar;
    public:
        shared_ptr<AbstractPlayer> player;
        shared_ptr<AbstractEnemy> enemy;
        shared_ptr<AbstractItem> item;

        AbstractCell(char displayChar = '\0', int x = 0, int y = 0);

        int getX();
        int getY();
        char getChar();
        bool occupied();
};

std::ostream& operator<<(std::ostream &out, AbstractCell &cell);

#endif
