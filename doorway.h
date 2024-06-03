#ifndef DOORWAY_H
#define DOORWAY_H

#include "hallway.h"

class Doorway: public AbstractHallway {
    public:
        Doorway(char displayChar, int x, int y);
};

#endif
