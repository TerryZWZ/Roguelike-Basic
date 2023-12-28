#include "item.h"

AbstractItem::AbstractItem(string displayChar, int x, int y) : displayChar {displayChar}, x {x}, y {y} {}

void AbstractItem::set(pair<int, int> coords) {
    x = coords.first;
    y = coords.second;
}

pair<int, int> AbstractItem::getPosition() {
    return make_pair(x, y);
}

ostream& operator<<(ostream &out, AbstractItem &item) {
    out << item.displayChar;
    return out;
}

