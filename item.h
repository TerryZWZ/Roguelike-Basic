#ifndef ITEM_H
#define ITEM_H

#include "player.h"
#include <string>
#include <map>

using namespace std;

class AbstractItem{
    protected:
        string displayChar;
        int x, y;
    public:
        AbstractItem(string displayChar, int x, int y);
        virtual bool isPotion() = 0;
        virtual bool isStairs() = 0;
        virtual bool isGold() = 0;
        virtual void applyEffect(AbstractPlayer* player=nullptr) = 0;
        virtual int getValue() = 0;
        virtual string getName() = 0;
        pair<int, int> getPosition();
        void set(pair<int, int> coords);

        friend ostream& operator<<(ostream &out, AbstractItem &item);
};

ostream& operator<<(ostream &out, AbstractItem &item);

#endif
