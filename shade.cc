#include "shade.h"

Shade::Shade(int x, int y) : AbstractPlayer(x, y, 125, 25, 25, "Shade") {}

int Shade::attack(AbstractCharacter* c, string e) {
    float dmgCalculation = ceil((100.0 / (100 + c->def)) * atk);
    int dmg = static_cast<int>(dmgCalculation);
    c->hp -= dmg;
    return dmg;
}
