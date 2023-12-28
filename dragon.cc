#include "dragon.h"

Dragon::Dragon(int x, int y) : AbstractEnemy("D", x, y, 150, 20, 20, "Dragon") {}

void Dragon::move(string override) {
    
}

int Dragon::attack(AbstractCharacter* c) {
    int dmg = 0;
    srand((unsigned) time(NULL));
    int random = rand() % 100;
    
    if (random < 50) {
        float dmgCalculation = ceil((100.0 / (100 + c->def)) * atk);
        dmg = static_cast<int>(dmgCalculation);
        c->hp -= dmg;
    }

    return dmg;
}
