#include "gold.h"

Gold::Gold(int x, int y, int value): AbstractItem("\033[33mG\033[0m", x, y), value {value} {}

void Gold::applyEffect(AbstractPlayer* player) {
    player->gold += value;
}

bool Gold::isGold() { return true; }
bool Gold::isPotion() { return true; }
bool Gold::isStairs() { return true; }
int Gold::getValue() { return value; }
string Gold::getName() { return "Gold"; }
