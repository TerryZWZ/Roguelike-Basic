#include "potion.h"

Potion::Potion(int x, int y, string name): AbstractItem("\033[32mP\033[0m", x, y), name {name} {}

void Potion::applyEffect(AbstractPlayer* player) {
    DEBUG_PRINT("Apply potion effect");
}

bool Potion::isPotion() { return true; }
bool Potion::isStairs() { return false; }
bool Potion::isGold() { return false; }
int Potion::getValue() { return 0; }
string Potion::getName() { return name; }
