#include "halfling.h"

Halfling::Halfling(int x, int y) : AbstractEnemy("L", x, y, 100, 15, 20, "Halfling") {}

int Halfling::attack(AbstractCharacter* c) {
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

void Halfling::ability(AbstractPlayer* p) {
    
}
