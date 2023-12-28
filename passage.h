#ifndef PASSAGE_H
#define PASSAGE_H

#include "hallway.h"

class Passage: public AbstractHallway {
    public:
        Passage(char displayChar, int x, int y);
};

#endif
