#ifndef WALL_H
#define WALL_H

#include "blockage.h"

class Wall: public AbstractBlockage {
    public:
        Wall(char displayChar, int x, int y);
};

#endif
