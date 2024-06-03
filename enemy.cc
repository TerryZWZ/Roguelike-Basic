#include "enemy.h"

AbstractEnemy::AbstractEnemy(string c, int x, int y, int hp, int atk, int def, string enemy) :
    AbstractCharacter(c, enemy, hp, atk, def), x {x}, y {y} {
        
        // Adds red color around display character of all enemies
        displayChar.insert(0, "\033[31m");
        displayChar.append("\033[0m");
    }

void AbstractEnemy::move(string direction) {
    auto [dx, dy] = getDirection(direction);
    x += dx;
    y += dy;
}

int AbstractEnemy::attack() {
    return 0;
}

void AbstractEnemy::ability() {
    
}

void AbstractEnemy::set(pair<int, int> coords) {
    x = coords.first;
    y = coords.second;
}

pair<int, int> AbstractEnemy::getPosition() {
    return make_pair(x, y);
}
