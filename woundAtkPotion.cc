#include "woundAtkPotion.h"

woundAtkPotion::woundAtkPotion(int x, int y): Potion(x, y, "WA") {
    
}

void woundAtkPotion::applyEffect(AbstractPlayer* player) {
    int effect = 5;
    if (player->getRace() == "Drow") {
        if (player->atk - ((effect * 15) / 10) < 0) {
            player->atk = 0;
        }
        else {
            player->atk -= ((effect * 15) / 10);
        }
    }
    else {
        if (player->atk - effect < 0) {
            player->atk = 0;
        }
        else {
            player->atk -= effect;
        }
    }
}

