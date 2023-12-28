#include "drow.h"

Drow::Drow(int x, int y) : AbstractPlayer(x, y, 150, 25, 15, "Drow") {}

int Drow::attack(AbstractCharacter* c, string e) {
    float dmgCalculation = ceil((100.0 / (100 + c->def)) * atk);
    int dmg = static_cast<int>(dmgCalculation);
    c->hp -= dmg;
    
    return dmg;
}
