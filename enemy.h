#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "player.h"
#include "utils.h"

class AbstractEnemy: public AbstractCharacter{
    int gold;
    int x, y;

    public:
        AbstractEnemy(string c, int x, int y, int hp, int atk, int def, string enemy);
        void move(string direction) override;
        int attack() override;
        void ability() override;
        pair<int, int> getPosition() override;
        virtual int attack(AbstractCharacter* c) = 0;
        void set(pair<int, int> coords);
};

#endif
