#include "poisonHealthPotion.h"

poisonHealthPotion::poisonHealthPotion(int x, int y): Potion(x, y, "PH") {
    
}

void poisonHealthPotion::applyEffect(AbstractPlayer* player) {
    int effect = 10;
    if (player->getRace() == "Drow") {
        if (player->hp > (effect * 15) / 10) {
            player->hp -= (effect * 15) / 10;
        }
        else if (player->hp <= (effect * 15) / 10){
            player->hp = 1;
        }
    }
    else {
        if (player->hp > effect) {
            player->hp -= effect;
        }
        else if (player->hp <= effect){
            player->hp = 1;
        }
    }
}
