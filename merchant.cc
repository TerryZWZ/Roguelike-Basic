#include "merchant.h"

Merchant::Merchant(int x, int y) : AbstractEnemy("M", x, y, 30, 70, 5, "Merchant") {}

int Merchant::attack(AbstractCharacter* c) {
    int dmg = 0;
    if (hp < baseHP) {
        srand((unsigned) time(NULL));
        int random = rand() % 100;
        
        if (random < 50) {
            float dmgCalculation = ceil((100.0 / (100 + c->def)) * atk);
            dmg = static_cast<int>(dmgCalculation);
            c->hp -= dmg;
        }
    }

    return dmg;
}
