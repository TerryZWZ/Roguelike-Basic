#include "floor.h"

using namespace std;

Floor::Floor(int level, std::string filename, int enemySpawnCount, int potionSpawnCount, int goldSpawnCount, bool testing) : 
    filename{filename}, level {level}, chamberCount {0},
    enemySpawnCount {enemySpawnCount}, potionSpawnCount {potionSpawnCount}, goldSpawnCount {goldSpawnCount},
    testing {testing}, message {""} {

    DEBUG_PRINT("Floor init");
    DEBUG_PRINT(filename);
    
    // Create filestream and read emptySingleFloor.txt
    std::string line;
    std::ifstream file{filename};

    if (file.is_open()) {
        // Counter variables for (x, y) cell coords
        int x = 0;
        int y = 0;
        int counter = 0;

        shared_ptr<AbstractEnemy> e = nullptr;
        shared_ptr<Potion> p = nullptr;
        shared_ptr<Gold> g = nullptr;
        shared_ptr<Tile> tile = nullptr;
        shared_ptr<Stairway> s = nullptr;
        
        while (getline(file, line) && counter < 25) {
            ++counter;

            // Assign objects and add to vector
            // Create a new vector for each row and append it to the main vector
            std::vector<shared_ptr<AbstractCell>> row;
            x = 0;
            
            for (auto ch : line) {
                // Case by case assignment
                switch (ch) {
                    // Empty map cases (normal game)
                    case ' ':
                        row.push_back(make_shared<Empty>(ch, x, y));
                        break;
                    case '-':
                        row.push_back(make_shared<Wall>(ch, x, y));
                        break;
                    case '|':
                        row.push_back(make_shared<Wall>(ch, x, y));
                        break;
                    case '.':
                        row.push_back(make_shared<Tile>('.', x, y));
                        break;
                    case '+':
                        row.push_back(make_shared<Doorway>(ch, x, y));
                        break;
                    case '#':
                        row.push_back(make_shared<Passage>(ch, x, y));
                        break;

                    // Test mode cases
                    case '@':
                        tile = make_shared<Tile>('.', x, y);
                        row.push_back(tile);
                        testPlayerCoords.first = x;
                        testPlayerCoords.second = y;
                        break;
                    // Items
                    case '0':
                        tile = make_shared<Tile>('.', x, y);
                        p = make_shared<restoreHealthPotion>(x, y);
                        tile->item = p;
                        row.push_back(tile);
                        this->potionList.push_back(p);
                        break;
                    case '1':
                        // boostAtkPotion
                        tile = make_shared<Tile>('.', x, y);
                        p = make_shared<boostAtkPotion>(x, y);
                        tile->item = p;
                        row.push_back(tile);
                        this->potionList.push_back(p);
                        break;
                    case '2':
                        // boostDefPotion
                        tile = make_shared<Tile>('.', x, y);
                        p = make_shared<boostDefPotion>(x, y);
                        tile->item = p;
                        row.push_back(tile);
                        this->potionList.push_back(p);
                        break;
                    case '3':
                        // poisonHealthPotion
                        tile = make_shared<Tile>('.', x, y);
                        p = make_shared<poisonHealthPotion>(x, y);
                        tile->item = p;
                        row.push_back(tile);
                        this->potionList.push_back(p);
                        break;
                    case '4':
                        // woundAtkPotion
                        tile = make_shared<Tile>('.', x, y);
                        p = make_shared<woundAtkPotion>(x, y);
                        tile->item = p;
                        row.push_back(tile);
                        this->potionList.push_back(p);
                        break;
                    case '5':
                        // woundDefPotion
                        tile = make_shared<Tile>('.', x, y);
                        p = make_shared<woundAtkPotion>(x, y);
                        tile->item = p;
                        row.push_back(tile);
                        this->potionList.push_back(p);
                        break;
                    case '6':
                        // normal pile
                        tile = make_shared<Tile>('.', x, y);
                        g = make_shared<Gold>(x, y, 2);
                        tile->item = p;
                        row.push_back(tile);
                        this->goldList.push_back(g);
                        break;
                    case '7':
                        // small hoard
                        tile = make_shared<Tile>('.', x, y);
                        g = make_shared<Gold>(x, y, 1);
                        tile->item = g;
                        row.push_back(tile);
                        this->goldList.push_back(g);
                        break;
                    case '8':
                        // merchant hoard
                        tile = make_shared<Tile>('.', x, y);
                        g = make_shared<Gold>(x, y, 4);
                        tile->item = g;
                        row.push_back(tile);
                        this->goldList.push_back(g);
                        break;
                    case '9':
                        // dragon hoard
                        tile = make_shared<Tile>('.', x, y);
                        g = make_shared<Gold>(x, y, 6);
                        tile->item = g;
                        row.push_back(tile);
                        this->goldList.push_back(g);
                        break;
                    case '\\':
                        // stairway
                        tile = make_shared<Tile>('.', x, y);
                        s = make_shared<Stairway>(x, y);
                        tile->item = s;
                        row.push_back(tile);
                        break;
                    // enemies
                    case 'H':
                        // human
                        tile = make_shared<Tile>('.', x, y);
                        row.push_back(tile);
                        enemyList.push_back( make_shared<Human>(x, y) );
                        break;
                    case 'W':
                        // dwarf
                        tile = make_shared<Tile>('.', x, y);
                        row.push_back(tile);
                        enemyList.push_back( make_shared<Dwarf>(x, y) );
                        break;
                    case 'E':
                        // elf
                        tile = make_shared<Tile>('.', x, y);
                        row.push_back(tile);
                        enemyList.push_back( make_shared<Elf>(x, y) );
                        break;
                    case 'O':
                        // orc
                        tile = make_shared<Tile>('.', x, y);
                        row.push_back(tile);
                        enemyList.push_back( make_shared<Orc>(x, y) );
                        break;
                    case 'M':
                        // merchant
                        tile = make_shared<Tile>('.', x, y);
                        row.push_back(tile);
                        enemyList.push_back( make_shared<Merchant>(x, y) );
                        break;
                    case 'D':
                        // dragon
                        tile = make_shared<Tile>('.', x, y);
                        row.push_back(tile);
                        enemyList.push_back( make_shared<Dragon>(x, y) );
                        break;
                    case 'L':
                        // halfling
                        tile = make_shared<Tile>('.', x, y);
                        row.push_back(tile);
                        enemyList.push_back( make_shared<Halfling>(x, y) );
                        break;
                    default:
                        DEBUG_PRINT("Invalid object ignored: " << ch);
                }
                ++x;
            }
            ++y;
            cells.push_back(row); // Adds each row
        }
        this->row = y;
        this->col = x;
        file.close();
    }

    if (!testing) {
        chamberList.push_back(make_shared<Chamber>(3, 3, 28, 6, *this));
        chamberCount++;
        chamberList.push_back(make_shared<Chamber>(39, 3, 61, 6, *this));
        chamberCount++;
        chamberList.push_back(make_shared<Chamber>(62, 5, 69, 6, *this));
        chamberCount++;
        chamberList.push_back(make_shared<Chamber>(62, 7, 75, 12, *this));
        chamberCount++;
        chamberList.push_back(make_shared<Chamber>(4, 15, 24, 21, *this));
        chamberCount++;
        chamberList.push_back(make_shared<Chamber>(38, 10, 49, 12, *this));
        chamberCount++;
        chamberList.push_back(make_shared<Chamber>(37, 19, 64, 21, *this));
        chamberCount++;
        chamberList.push_back(make_shared<Chamber>(65, 16, 75, 21, *this));
        chamberCount++;
    }
}

void Floor::chooseRace(char race, int x, int y) {
    if (race == 'S') {
        player = make_shared<Shade>(x, y);
    }
    else if (race == 'D') {
        player = make_shared<Drow>(x, y);
    }  
    else if (race == 'V') {
        player = make_shared<Vampire>(x, y);
    }
    else if (race == 'T') {
        player = make_shared<Troll>(x, y);
    }
    else if (race == 'G') {
        player = make_shared<Goblin>(x, y);
    }
}

int Floor::getLevel() const {
    return level;
}

void Floor::advanceLevel() {
    ++level;
    if (winState()) return;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cells[i][j]->item = nullptr;
            cells[i][j]->enemy = nullptr;
        }
    }
    potionList.clear();
    goldList.clear();
    enemyList.clear();
}

bool Floor::winState() {
    return level >= 5;
}

void Floor::floorInit() {

    // Clear all cells somehow
    // Either make a new grid or delete all items through nested loop
    vector<int> unfilledChamberIndex;
    for (int i = 0; i < chamberCount; ++i) {
        unfilledChamberIndex.push_back(i);
    }

    // Spawn player
    srand((unsigned) time(NULL));
    int playerChamber = rand() % chamberCount;
    chamberList[playerChamber]->spawnPlayer(*this, player);

    if (chamberList[unfilledChamberIndex[playerChamber]]->isFull()) {
        // Removes the chamber from the list if spawning a potion in there makes it full
        unfilledChamberIndex.erase(unfilledChamberIndex.begin() + playerChamber);
    }

    message += "Player has spawned\n";

    // Spawn stairway
    int stairwayChamber = rand() % (chamberCount - 1);
    if (stairwayChamber == playerChamber) stairwayChamber = chamberCount - 1;
    chamberList[stairwayChamber]->spawnStairway(*this);

    if (chamberList[unfilledChamberIndex[playerChamber]]->isFull()) {
        // Removes the chamber from the list if spawning a potion in there makes it full
        unfilledChamberIndex.erase(unfilledChamberIndex.begin() + playerChamber);
    }

    // Spawn Potions
    for (int i = 0; i < potionSpawnCount; ++i) {
        if (unfilledChamberIndex.size() == 0) throw "All chambers are full"; 
        
        int potionChamber = rand() % unfilledChamberIndex.size();
        chamberList[unfilledChamberIndex[potionChamber]]->spawnPotion(*this);

        if (chamberList[unfilledChamberIndex[potionChamber]]->isFull()) {
            // Removes the chamber from the list if spawning a potion in there makes it full
            unfilledChamberIndex.erase(unfilledChamberIndex.begin() + potionChamber);
        }
    }

    // Spawn Gold
    for (int i = 0; i < goldSpawnCount; ++i) {
        if (unfilledChamberIndex.size() == 0) throw "All chambers are full"; 

        int goldChamber = rand() % unfilledChamberIndex.size();
        chamberList[unfilledChamberIndex[goldChamber]]->spawnGold(*this);

        if (chamberList[unfilledChamberIndex[goldChamber]]->isFull()) {
            // Removes the chamber from the list if spawning a potion in there makes it full
            unfilledChamberIndex.erase(unfilledChamberIndex.begin() + goldChamber);
        }
    }

    // Spawn Enemies
    for (int i = 0; i < enemySpawnCount; ++i) {
        if (unfilledChamberIndex.size() == 0) throw "All chambers are full"; 

        int enemyChamber = rand() % unfilledChamberIndex.size();
        chamberList[unfilledChamberIndex[enemyChamber]]->spawnEnemy(*this);

        if (chamberList[unfilledChamberIndex[enemyChamber]]->isFull()) {
            unfilledChamberIndex.erase(unfilledChamberIndex.begin() + enemyChamber);
        }
    }
}

std::ostream& operator<<(std::ostream &out, Floor &floor) {
    if (floor.player->getHP() > 0) {

        pair<int, int> playerPos = floor.player->getPosition();

        for (int y = 0; y < floor.cells.size(); y++) {
            for(int x = 0; x < floor.cells[y].size(); x++) {
                if (x == playerPos.first && y == playerPos.second) {
                    out << *floor.player;
                }
                else if (floor.cells[y][x]->enemy != nullptr) {
                    out << *(floor.cells[y][x]->enemy);
                }
                else if (floor.cells[y][x]->item != nullptr) {
                    out << *(floor.cells[y][x]->item);
                }
                else {
                    out << *(floor.cells[y][x]);
                }

            }
            out << endl;
        }

        out << "Race: " << floor.player->getRace() << " " << "Gold: " << floor.player->getGold() << endl;
        out << "HP: " << floor.player->getHP() << endl;
        out << "Atk: " << floor.player->getAtk() << endl;
        out << "Def: " << floor.player->getDef() << endl;
        out << "\033[1;36m" << floor.message << "\033[0m" << endl;
        floor.message = "";
    }
    else {
        out << "HP: " << floor.player->getHP() << endl;
        out << "You have died!" << endl;
        out << "\033[31m";
        out << " ▄▄ •  ▄▄▄· • ▌ ▄ ·. ▄▄▄ .           ▌ ▐·▄▄▄ .▄▄▄  \n";
        out << "▐█ ▀ ▪▐█ ▀█ ·██ ▐███▪▀▄.▀·    ▪     ▪█·█▌▀▄.▀·▀▄ █·\n";
        out << "▄█ ▀█▄▄█▀▀█ ▐█ ▌▐▌▐█·▐▀▀▪▄     ▄█▀▄ ▐█▐█•▐▀▀▪▄▐▀▀▄ \n";
        out << "▐█▄▪▐█▐█ ▪▐▌██ ██▌▐█▌▐█▄▄▌    ▐█▌.▐▌ ███ ▐█▄▄▌▐█•█▌\n";
        out << "·▀▀▀▀  ▀  ▀ ▀▀  █▪▀▀▀ ▀▀▀      ▀█▄▀▪. ▀   ▀▀▀ .▀  ▀\n";
        out << "\n";
        out << "\033[0m" << endl;
    }
    
    return out;
}

Chamber::Chamber(int upperX, int upperY, int lowerX, int lowerY, Floor &f) :
    upperX {upperX}, upperY {upperY}, lowerX {lowerX}, lowerY {lowerY} {
        tilesAvailable = 0;
        for (int i = upperY; i <= lowerY; i++) {
            for (int j = upperX; j <= lowerX; j++) {
                if (f.cells[i][j]->player == nullptr && f.cells[i][j]->enemy == nullptr) {
                    tileList.push_back(f.cells[i][j]);
                }
                tilesAvailable++;
            }
        }
    }

void Chamber::spawnPlayer(Floor &f, shared_ptr<AbstractPlayer> p) {
    srand((unsigned) time(NULL));
    int tileChoice = rand() % tilesAvailable;

    while (tileList[tileChoice]->player != nullptr || tileList[tileChoice]->enemy != nullptr || tileList[tileChoice]->item != nullptr) {
        tileChoice = rand() % tilesAvailable;
    }

    pair<int, int> coords;
    coords.first = tileList[tileChoice]->getX();
    coords.second = tileList[tileChoice]->getY();

    f.player = p;
    tileList[tileChoice]->player = p;
    tileList[tileChoice]->player->set(coords);

    tilesAvailable--;
}

void Chamber::spawnStairway(Floor &f) {
    int tileChoice = rand() % tilesAvailable;

    while (tileList[tileChoice]->player != nullptr || tileList[tileChoice]->enemy != nullptr || tileList[tileChoice]->item != nullptr) {
        tileChoice = rand() % tilesAvailable;
    }

    pair<int, int> coords;
    coords.first = tileList[tileChoice]->getX();
    coords.second = tileList[tileChoice]->getY();

    tileList[tileChoice]->item = make_shared<Stairway>(coords.first, coords.second);
}

void Chamber::spawnEnemy(Floor &f) {

    int tileChoice = rand() % tilesAvailable;

    while (tileList[tileChoice]->player != nullptr || tileList[tileChoice]->enemy != nullptr || tileList[tileChoice]->item != nullptr) {
        tileChoice = rand() % tilesAvailable;
    }

    pair<int, int> coords;
    coords.first = tileList[tileChoice]->getX();
    coords.second = tileList[tileChoice]->getY();

    int enemyChoice = rand() % 18;
    shared_ptr<AbstractEnemy> e = nullptr;

    if (enemyChoice < 4) {
        e = make_shared<Human>(coords.first, coords.second);
    }
    else if (enemyChoice < 7) {
        e = make_shared<Dwarf>(coords.first, coords.second);
    }
    else if (enemyChoice < 12) {
        e = make_shared<Halfling>(coords.first, coords.second);
    }
    else if (enemyChoice < 14) {
        e = make_shared<Elf>(coords.first, coords.second);
    }
    else if (enemyChoice < 16) {
        e = make_shared<Orc>(coords.first, coords.second);
    }
    else {
        e = make_shared<Merchant>(coords.first, coords.second);
    }

    f.enemyList.push_back(e);
    tileList[tileChoice]->enemy = e;

    tilesAvailable--;
}

void Chamber::spawnPotion(Floor &f) {
    int tileChoice = rand() % tilesAvailable;

    while (tileList[tileChoice]->player != nullptr || tileList[tileChoice]->enemy != nullptr || tileList[tileChoice]->item != nullptr) {
        tileChoice = rand() % tilesAvailable;
    }

    pair<int, int> coords;
    coords.first = tileList[tileChoice]->getX();
    coords.second = tileList[tileChoice]->getY();

    int potionChoice = rand() % 6;
    shared_ptr<Potion> p = nullptr;

    
    if (potionChoice == 0) {
        p = make_shared<restoreHealthPotion>(coords.first, coords.second);
    }
    else if (potionChoice == 1) {
        p = make_shared<boostAtkPotion>(coords.first, coords.second);
    }
    else if (potionChoice == 2) {
        p = make_shared<boostDefPotion>(coords.first, coords.second);
    }
    else if (potionChoice == 3) {
        p = make_shared<poisonHealthPotion>(coords.first, coords.second);
    }
    else if (potionChoice == 4) {
        p = make_shared<woundAtkPotion>(coords.first, coords.second);
    }
    else if (potionChoice == 5) {
        p = make_shared<woundDefPotion>(coords.first, coords.second);
    }

    f.potionList.push_back(p);
    tileList[tileChoice]->item = p;

    tilesAvailable--;
}

void Chamber::spawnGold(Floor &f) {
    int tileChoice = rand() % tilesAvailable;

    while (tileList[tileChoice]->player != nullptr || tileList[tileChoice]->enemy != nullptr || tileList[tileChoice]->item != nullptr) {
        tileChoice = rand() % tilesAvailable;
    }

    pair<int, int> coords;
    coords.first = tileList[tileChoice]->getX();
    coords.second = tileList[tileChoice]->getY();

    int goldChoice = rand() % 8;
    shared_ptr<Gold> g = nullptr;

    if (goldChoice <= 1) {
        g = make_shared<Gold>(coords.first, coords.second, 1);
    }
    else if (goldChoice <= 6) {
        g = make_shared<Gold>(coords.first, coords.second, 2);
    }
    else {
        g = make_shared<Gold>(coords.first, coords.second, 6);
    }
    
    if (g->value == 6) {
        pair<int, int> directions[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        
        for (int i = 0; i < 8; ++i) {
            int randIndex = rand() % 8;
            
            int dragonX = coords.first + directions[randIndex].first;
            int dragonY = coords.second + directions[randIndex].second;

            if (f.cells[dragonY][dragonX]->getChar() == '.' && f.cells[dragonY][dragonX]->player == nullptr && f.cells[dragonY][dragonX]->enemy == nullptr && f.cells[dragonY][dragonX]->item == nullptr) {
                shared_ptr<AbstractEnemy> dragon = make_shared<Dragon>(dragonX, dragonY);
                f.enemyList.push_back(dragon);
                f.cells[dragonY][dragonX]->enemy = dragon;
                break;
            }
        }
    }

    f.goldList.push_back(g);
    tileList[tileChoice]->item = g;

    tilesAvailable--;
}

bool Chamber::isFull() {
    for (auto n: tileList) {
        if (!n->occupied()) return false;
    }
    return true;
}

void Floor::movePlayer(string direction, bool attack, bool potion) {
    
    // Player Movement Initialization
    auto [dx, dy] = getDirection(direction);
    pair<int, int> oldPos = player->getPosition();
    pair<int, int> newPos = make_pair(oldPos.first + dx, oldPos.second + dy);

    char cell = cells[newPos.second][newPos.first]->getChar();
    string nextCell;
    nextCell += cell;

    // Player Attack
    if (cells[newPos.second][newPos.first]->enemy != nullptr) {
        string isEnemy = cells[newPos.second][newPos.first]->enemy->getRace();

        if ((isEnemy == "Human" || isEnemy == "Dwarf" || isEnemy == "Elf" || isEnemy == "Orc" || isEnemy == "Merchant" || isEnemy == "Dragon" || isEnemy == "Halfling") && attack == true) {
            if (isEnemy == "Halfling") {
                int random = rand() % 100;
                
                if (random < 50) {
                    int dmg = player->attack(cells[newPos.second][newPos.first]->enemy.get(), isEnemy);
                    message += "Player dealt " + to_string(dmg) + " Damage\n";
                }
            }
            else {
                int dmg = player->attack(cells[newPos.second][newPos.first]->enemy.get(), isEnemy);
                message += "Player dealt " + to_string(dmg) + " Damage\n";
            }

            if (cells[newPos.second][newPos.first]->enemy->hp <= 0) {
                cells[newPos.second][newPos.first]->enemy->hp = 0;

                for (auto it = enemyList.begin(); it != enemyList.end(); ++it) {
                    if (*it == cells[newPos.second][newPos.first]->enemy) {
                        enemyList.erase(it);
                        break;
                    }
                }

                if (isEnemy == "Human" || isEnemy == "Merchant") {
                    shared_ptr<Gold> g = make_shared<Gold>(newPos.first, newPos.second, 4);
                    cells[newPos.second][newPos.first]->item = g;
                    goldList.push_back(g);
                }

                cells[newPos.second][newPos.first]->enemy = nullptr;
                message += "Enemy has died\n";
            }
            else {
                message += "Enemy HP: " + to_string(cells[newPos.second][newPos.first]->enemy->hp) + "\n";
            }
        }
    }
    // Player Collect Item
    else if (cells[newPos.second][newPos.first]->item != nullptr) {
        DEBUG_PRINT("Item collect");
        // Potion handling
        if (potion && cells[newPos.second][newPos.first]->item->isPotion()) {
            DEBUG_PRINT("Potion collect");
            message += "Player consumed " + cells[newPos.second][newPos.first]->item->getName() + " Potion\n";
            cells[newPos.second][newPos.first]->item->applyEffect(player.get());

            for (auto it = potionList.begin(); it != potionList.end(); ++it) {
                if (*it == cells[newPos.second][newPos.first]->item) {
                    potionList.erase(it);
                    break;
                }
            }

            cells[newPos.second][newPos.first]->item = nullptr;

        // Gold handling
        }
        else if (cells[newPos.second][newPos.first]->item->isGold()) {
            DEBUG_PRINT("Gold collect");
            message += "Player collected " + to_string(cells[newPos.second][newPos.first]->item->getValue()) + " Gold\n";
            cells[newPos.second][newPos.first]->item->applyEffect(player.get());

            for (auto it = goldList.begin(); it != goldList.end(); ++it) {
                if (*it == cells[newPos.second][newPos.first]->item) {
                    goldList.erase(it);
                    break;
                }
            }

            cells[newPos.second][newPos.first]->item = nullptr;
            this->movePlayer(direction, false, false);

        // Stairway handling
        }
        else if (cells[newPos.second][newPos.first]->item->isStairs()) {
            DEBUG_PRINT("Stairway");
            throw StairwayReached{};
        }

    }
    // Player Movement
    else if ((nextCell == "." || nextCell == "+" || nextCell == "#") && cells[newPos.second][newPos.first]->enemy == nullptr && cells[newPos.second][newPos.first]->item == nullptr) {
        
        if (direction == "no") {
            message += "Player moves North\n";
        }
        else if (direction == "so") {
            message += "Player moves South\n";
        }
        else if (direction == "ea") {
            message += "Player moves East\n";
        }
        else if (direction == "we") {
            message += "Player moves West\n";
        }
        else if (direction == "nw") {
            message += "Player moves North West\n";
        }
        else if (direction == "ne") {
            message += "Player moves North East\n";
        }
        else if (direction == "sw") {
            message += "Player moves South West\n";
        }
        else if (direction == "se") {
            message += "Player moves South East\n";
        }

        player->set(newPos);
        cells[oldPos.second][oldPos.first]->player = nullptr;
        cells[newPos.second][newPos.first]->player = player;
    }
}

void Floor::moveEnemies(bool move) {
    if (move == true) {
        srand((unsigned) time(NULL));
        
        for (shared_ptr<AbstractEnemy>& enemy : enemyList) {
            int random = rand() % 8;
            pair<int, int> movement;

            if (random == 0) {
                movement = getDirection("no");
            }
            else if (random == 1) {
                movement = getDirection("so");
            }
            else if (random == 2) {
                movement = getDirection("ea");
            }
            else if (random == 3) {
                movement = getDirection("we");
            }
            else if (random == 4) {
                movement = getDirection("ne");
            }
            else if (random == 5) {
                movement = getDirection("nw");
            }
            else if (random == 6) {
                movement = getDirection("se");
            }
            else if (random == 7) {
                movement = getDirection("sw");
            }

            pair<int, int> oldPos = enemy->getPosition();
            pair<int, int> newPos = make_pair(oldPos.first + movement.first, oldPos.second + movement.second);

            char cell = cells[newPos.second][newPos.first]->getChar();
            string nextCell;
            nextCell += cell;
            bool stand = false;
            
            // Enemy Attack
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (cells[oldPos.second + i][oldPos.first + j]->player != nullptr && cells[oldPos.second][oldPos.first]->enemy != nullptr) {
                        int dmg = enemy->attack(player.get());
                        message += "Enemy dealt " + to_string(dmg)  + " Damage\n";
                        stand = true;
                    }

                    if (player->hp <= 0) {
                        player->hp = 0;
                    }
                }
            }
            // Enemy Movement
            if (nextCell == "." && stand == false && cells[newPos.second][newPos.first]->enemy == nullptr && cells[newPos.second][newPos.first]->item == nullptr) {
                if (enemy->getRace() != "Dragon") {
                    enemy->set(newPos);
                    cells[oldPos.second][oldPos.first]->enemy = nullptr;
                    cells[newPos.second][newPos.first]->enemy = enemy;
                }
            }
        }
    }
}

bool Floor::playerAlive() {
    if (player->getHP() <= 0) {
        return false;
    }

    return true;
}

void Floor::setPlayer(shared_ptr<AbstractPlayer> p) {
    player = p;
}

shared_ptr<AbstractPlayer> Floor::getPlayer() {
    return player;
}
