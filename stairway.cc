#include "stairway.h"

Stairway::Stairway(int x, int y): AbstractItem("\033[34m\\\033[0m", x, y) {}

void Stairway::applyEffect(AbstractPlayer* player) {
    DEBUG_PRINT("Going up stairway");
}

bool Stairway::isPotion() { return false; }
bool Stairway::isStairs() { return true; }
bool Stairway::isGold() { return false; }
int Stairway::getValue() { return 0; }
string Stairway::getName() { return "Stairway"; }
