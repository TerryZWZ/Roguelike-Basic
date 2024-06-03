#include "player.h"

AbstractPlayer::AbstractPlayer(int x, int y, int hp, int atk, int def, string race):
    AbstractCharacter("\033[34m@\033[0m", race, hp, atk, def), x {x}, y {y}, maxHp{hp} {
        gold = 0;
    }

void AbstractPlayer::move(string direction) {
    auto [dx, dy] = getDirection(direction);
    x += dx;
    y += dy;
}

int AbstractPlayer::attack() {
    return 0;
}

void AbstractPlayer::ability() {
    
}

void AbstractPlayer::set(pair<int, int> coords) {
    x = coords.first;
    y = coords.second;
}

pair<int, int> AbstractPlayer::getPosition() {
    return make_pair(x, y);
}

int AbstractPlayer::getGold() {
    return gold;
}

void AbstractPlayer::removePotionEffect() {
    hp = baseHP;
    atk = baseAtk;
    def = baseDef;
}
