#include "boostDefPotion.h"

boostDefPotion::boostDefPotion(int x, int y): Potion(x, y, "BD") {
    
}

void boostDefPotion::applyEffect(AbstractPlayer* player) {
    int effect = 5;
    if (player->getRace() == "Drow") {
        player->def += ((effect * 15) / 10);
    }
    else {
        player->def += effect;
    }
}
