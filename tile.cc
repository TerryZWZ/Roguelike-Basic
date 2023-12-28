#include "tile.h"

Tile::Tile(char displayChar, int x, int y): AbstractCell(displayChar, x, y) {}

int Tile::getX() const {
    return x;
}

int Tile::getY() const {
   return y;
}
