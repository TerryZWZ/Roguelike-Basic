#ifndef HALLWAY_H
#define HALLWAY_H

#include "cell.h"

class AbstractHallway: public AbstractCell {
    public:
        AbstractHallway(char displayChar = '#', int x=0, int y=0);
};

#endif
