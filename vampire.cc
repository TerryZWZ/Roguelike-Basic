#include "vampire.h"

Vampire::Vampire(int x, int y) : AbstractPlayer(x, y, 50, 25, 25, "Vampire") {}

int Vampire::attack(AbstractCharacter* c, string e) {
    float dmgCalculation = ceil((100.0 / (100 + c->def)) * atk);
    int dmg = static_cast<int>(dmgCalculation);
    c->hp -= dmg;
    
    if (c->getRace() == "Dwarf") {
        hp -= 5;
    }
    else {
        hp += 5;
    }

    return dmg;
}
