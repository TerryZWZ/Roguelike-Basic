#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <ostream>
#include <fstream>
#include <map>
#include <string>
#include <cmath>
#include <memory>

using namespace std;

class AbstractCharacter{
protected:
    string displayChar;
    string race;
    int baseHP, baseAtk, baseDef;
public:
    int hp, atk, def;

    AbstractCharacter(string c, string race, int hp, int atk, int def);
    virtual void move(string direction) = 0;
    virtual int attack() = 0;
    virtual void ability() = 0;
    virtual pair<int, int> getPosition() = 0;

    void setHP(int new_health);
    int getHP();
    int getDef();
    int getAtk();
    string getChar();
    string getRace();

    friend ostream& operator<<(ostream &out, AbstractCharacter &character);
    friend bool operator==(const AbstractCharacter &c1, const AbstractCharacter &c2);
};

ostream& operator<<(ostream &out, AbstractCharacter &character);

#endif
