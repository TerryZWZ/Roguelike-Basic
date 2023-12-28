#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "utils.h"

class AbstractPlayer: public AbstractCharacter{
    protected:
        int x, y;
    public:
        AbstractPlayer(int x, int y, int hp, int atk, int def, string race);
        int gold;
        int maxHp;
        void move(string direction) override;
        int attack() override;
        void ability() override;
        virtual int attack(AbstractCharacter* c, string e) = 0;
        pair<int, int> getPosition() override;
        void set(pair<int, int> coords);
        int getGold();
        void removePotionEffect();
};

#endif
