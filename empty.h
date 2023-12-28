#ifndef EMPTY_H
#define EMPTY_H

#include "blockage.h"

class Empty: public AbstractBlockage {
    public:
        Empty(char displayChar = ' ', int x=0, int y=0);
};

#endif
