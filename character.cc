#include "character.h"

AbstractCharacter::AbstractCharacter(string c, string race, int hp, int atk, int def) :
        displayChar {c}, race {race}, hp {hp}, atk {atk}, def {def} {
            baseHP = hp;
            baseAtk = atk;
            baseDef = def;
        }

string AbstractCharacter::getChar() {
    return displayChar; 
}


int AbstractCharacter::getHP() {
    return hp;
}


int AbstractCharacter::getAtk() {
    return atk;
}


int AbstractCharacter::getDef() {
    return def;
}

string AbstractCharacter::getRace() {
    return race;
}

void AbstractCharacter::setHP(int new_hp) {
    hp = new_hp;
}

ostream& operator<<(ostream &out, AbstractCharacter &character) {
    out << character.displayChar;
    return out;
}

bool operator==(const AbstractCharacter &c1, const AbstractCharacter &c2) {
    return c1.race == c2.race;
}
