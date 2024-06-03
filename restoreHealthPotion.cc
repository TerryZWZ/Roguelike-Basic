#include "restoreHealthPotion.h"

restoreHealthPotion::restoreHealthPotion(int x, int y): Potion(x, y, "RH") {
    
}

void restoreHealthPotion::applyEffect(AbstractPlayer* player) {
    int effect = 10;
    if (player->hp + effect < player->maxHp || player->getRace() == "Vampire") {
        player->hp += effect;
    }
    else {
        player->hp = player->maxHp;
    }

    if (player->getRace() == "Drow") {
        player->hp += (effect * 15) / 10;
    }
}
