#include "woundDefPotion.h"

woundDefPotion::woundDefPotion(int x, int y): Potion(x, y, "WD") {
    
}

void woundDefPotion::applyEffect(AbstractPlayer* player) {
    int effect = 5;
    if (player->getRace() == "Drow") {
        if (player->def - ((effect * 15) / 10) < 0) {
            player->def = 0;
        }
        else {
            player->def -= ((effect * 15) / 10);
        }
    }
    else {
        if (player->def - effect < 0) {
            player->def = 0;
        }
        else {
            player->def -= effect;
        }
    }
}

