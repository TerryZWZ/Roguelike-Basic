#ifndef TILE_H
#define TILE_H

#include "cell.h"

class Tile: public AbstractCell {
    int x, y;
    AbstractItem *i;
    public:
        int getX() const;
        int getY() const;
        bool hasItem() const;
        Tile(char displayChar = '.', int x = 0, int y = 0);
};

#endif
