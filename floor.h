#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <memory>

#include "cell.h"
#include "tile.h"
#include "passage.h"
#include "doorway.h"
#include "wall.h"
#include "empty.h"
#include "character.h"
#include "player.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include "item.h"
#include "gold.h"

#include "potion.h"
#include "restoreHealthPotion.h"
#include "boostAtkPotion.h"
#include "boostDefPotion.h"
#include "poisonHealthPotion.h"
#include "woundAtkPotion.h"
#include "woundDefPotion.h"

#include "stairway.h"
#include "cell.h"
#include "tile.h"
#include "utils.h"

using namespace std;

class Chamber;

class StairwayReached {};

class Floor {
    string filename;
    int row, col;
    int level;
    int chamberCount;
    int enemySpawnCount;
    int potionSpawnCount;
    int goldSpawnCount;
    bool testing;
    string message;

    vector<std::vector<shared_ptr<AbstractCell>>> cells;
    shared_ptr<AbstractPlayer> player;
    vector<shared_ptr<AbstractEnemy>> enemyList;
    vector<shared_ptr<Potion>> potionList;
    vector<shared_ptr<Gold>> goldList;
    vector<shared_ptr<Chamber>> chamberList;

    public:
        Floor(int level = 0, string filename = "cc3k-emptySingleFloor.txt", int enemySpawnCount = 20, int potionSpawnCount = 10, int goldSpawnCount = 10, bool testing = false);
        void chooseRace(char race = 'S', int x = -1, int y = -1);
        void advanceLevel();
        void floorInit();
        bool winState();
        pair<int, int> testPlayerCoords;
        int getLevel() const;
        void movePlayer(string cmd, bool attack, bool potion);
        void moveEnemies(bool move);
        bool playerAlive();
        void setPlayer(shared_ptr<AbstractPlayer> p);
        shared_ptr<AbstractPlayer> getPlayer();
        
        friend ostream& operator<<(ostream &out, Floor &floor);
        friend class Chamber;
};

ostream& operator<<(ostream &out, Floor &floor);

class Chamber {
    int upperX, upperY;
    int lowerX, lowerY;
    int tilesAvailable;
    vector<shared_ptr<AbstractCell>> tileList;
    
    public:
        Chamber(int upperX, int upperY, int lowerX, int lowerY, Floor &f);
        bool isFull();
        void spawnPlayer(Floor &f, shared_ptr<AbstractPlayer> p);
        void spawnEnemy(Floor &f); 
        void spawnStairway(Floor &f);
        void spawnPotion(Floor &f); 
        void spawnGold(Floor &f);
};

#endif
