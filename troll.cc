#include "troll.h"

Troll::Troll(int x, int y) : AbstractPlayer(x, y, 120, 25, 15, "Troll") {}

void Troll::move(string direction) {
    auto [dx, dy] = getDirection(direction);
    x += dx;
    y += dy;

    ability();
}

int Troll::attack(AbstractCharacter* c, string e) {
    float dmgCalculation = ceil((100.0 / (100 + c->def)) * atk);
    int dmg = static_cast<int>(dmgCalculation);
    c->hp -= dmg;
    
    ability();

    return dmg;
}

void Troll::ability() {
    if (hp <= 120) {
        hp += 5;
    }
}
