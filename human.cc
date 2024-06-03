#include "human.h"

Human::Human(int x, int y) : AbstractEnemy("H", x, y, 140, 30, 10, "Human") {}

int Human::attack(AbstractCharacter* c) {
    int dmg = 0;
    srand((unsigned) time(NULL));
    int random = rand() % 100;
    
    if (random < 50) {
        float dmgCalculation = ceil((100.0 / (100 + c->def)) * atk);
        int dmg = static_cast<int>(dmgCalculation);
        c->hp -= dmg;
    }

    return dmg;
}
