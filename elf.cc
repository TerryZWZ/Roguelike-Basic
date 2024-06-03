#include "elf.h"

Elf::Elf(int x, int y) : AbstractEnemy("E", x, y, 140, 30, 10, "Elf") {}

int Elf::attack(AbstractCharacter* c) {
    int dmg = 0;

    for (int i = 0; i < 2 && c->getRace() != "Drow"; i++) {
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
