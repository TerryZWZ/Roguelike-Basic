#include "boostAtkPotion.h"

boostAtkPotion::boostAtkPotion(int x, int y): Potion(x, y, "BA") {
    
}

void boostAtkPotion::applyEffect(AbstractPlayer* player) {
    int effect = 5;
    if (player->getRace() == "Drow") {
        player->atk += ((effect * 15) / 10);
    }
    else {
        player->atk += effect;
    }
}
