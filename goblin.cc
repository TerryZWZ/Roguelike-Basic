#include "goblin.h"

Goblin::Goblin(int x, int y) : AbstractPlayer(x, y, 110, 15, 20, "Goblin") {}

int Goblin::attack(AbstractCharacter* c, string e) {
    float dmgCalculation = ceil((100.0 / (100 + c->def)) * atk);
    int dmg = static_cast<int>(dmgCalculation);
    c->hp -= dmg;

    if (c->hp <= 0) {
        ability();
    }

    return dmg;
}

void Goblin::ability() {
    gold += 5;
};
