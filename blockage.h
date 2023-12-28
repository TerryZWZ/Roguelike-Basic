#ifndef BLOCKAGE_H
#define BLOCKAGE_H

#include "cell.h"

class AbstractBlockage: public AbstractCell {
    public:
        AbstractBlockage(char displayChar, int x, int y);
};

#endif
