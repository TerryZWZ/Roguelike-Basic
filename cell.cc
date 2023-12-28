#include "cell.h"

AbstractCell::AbstractCell(char displayChar, int x, int y): displayChar {displayChar}, x{x}, y{y}, player {nullptr}, enemy {nullptr}, item {nullptr} {}

char AbstractCell::getChar() {
    return displayChar;
}


std::ostream& operator<<(std::ostream &out, AbstractCell &cell) {
    out << cell.getChar();

    return out;
}


int AbstractCell::getX() {
    return x;
}


int AbstractCell::getY() {
    return y;
}

bool AbstractCell::occupied() {
    if (item != nullptr && player != nullptr && enemy != nullptr) {
        return true;
    }

    return false;
}
