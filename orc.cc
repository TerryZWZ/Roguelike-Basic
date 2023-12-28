#include "orc.h"

Orc::Orc(int x, int y) : AbstractEnemy("O", x, y, 180, 30, 25, "Orc") {}

int Orc::attack(AbstractCharacter* c) {
    int dmg = 0;
    srand((unsigned) time(NULL));
    int random = rand() % 100;
    
    if (random < 50) {
        float dmgCalculation = ceil((100.0 / (100 + c->def)) * atk);
        dmg = static_cast<int>(dmgCalculation);

        if (c->getRace() == "Goblin") {
            dmg *= 15;
            dmg /= 10;
        }
        
        c->hp -= dmg;
    }

    return dmg;
}
