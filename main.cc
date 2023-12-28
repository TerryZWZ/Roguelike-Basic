
#include <iostream>
#include <string>
#include <utility>

#include "utils.h"
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
#include "stairway.h"
#include "floor.h"

using namespace std;

int main(int argc, char *argv[]=nullptr) {
    bool gameContain = true;

    while(gameContain){
    
        // Flags
        bool gameStarted = false;
        bool testMode = false;

        // Initialize Player
        shared_ptr<AbstractPlayer> player = nullptr;

        // Initialize Floor
        unique_ptr<Floor> floor = nullptr;

        if (argc == 2) {
            DEBUG_PRINT("test file provided");
            testMode = true;
            floor = make_unique<Floor>(0, argv[1], 20, true);
        }
        else {
            floor = make_unique<Floor>();
        }

        // Get race and start game
        while (!gameStarted) {
            cout << "Please select a valid race or [q]uit: " << "[S]hade [D]row [V]ampire [T]roll [G]oblin" << endl;
            char race;
            cin >> race;

            if ((race == 'S') || (race == 'D') || (race == 'V') || (race == 'T') || (race == 'G')) {
                gameStarted = true;

                if (!testMode) {
                    floor->chooseRace(race);
                    player = floor->getPlayer();
                    floor->floorInit();
                }
                else {
                    floor->chooseRace(race, floor->testPlayerCoords.first, floor->testPlayerCoords.second);
                }
                
                cout << *floor << endl;
                DEBUG_PRINT("Game started!");
            }
            else if (race == 'q') {
                exit(0);
            }
            else {
                cout << "Invalid input. Please try again:" << endl;
            }
        }

        bool attack = false;
        bool potion = false;
        bool enemyMovement = true;

        // Command Interpreter
        string cmd;
        while(cin >> cmd && gameStarted) {
            
            // Arguments
            if (cmd[0] == 'a') {
                attack = true;
            } 
            else if (cmd[0] == 'u') {
                potion = true;
            }
            else if (cmd[0] == 'f') {
                enemyMovement = false;
            }
            else if (cmd[0] == 'r') {
                cout << "Restarting game!" << endl;
                gameStarted = false;
                break;
            }
            else if (cmd[0] == 'q') {
                cout << "Quitting game!" << endl;
                exit(0);
            }

            // Player Movement Command
            if ((cmd.length() == 2 && (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" || cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw")) || cmd == "f") {
                try {
                    floor->movePlayer(cmd, attack, potion);
                    floor->moveEnemies(enemyMovement);
                    attack = false;
                    potion = false;

                    bool alivePlayer = floor->playerAlive();

                    cout << *floor << endl;

                    if (alivePlayer == false) {
                        cout << "Insert anything to restart" << endl;
                        gameStarted = false;
                    }

                    continue;
                }
                catch (StairwayReached) {
                    int level = floor->getLevel() + 1;
                    
                    if (level >= 5) {
                        cout << "Congradulations! You've beat the final floor. Do you want to play again? (y/n)" 
                            << endl;
                        string answer;
                        while(cin >> answer) {
                            if (answer == "n") {
                                cout << "Quitting game!" << endl;
                                exit(0);
                                break;
                            }
                            else if (answer == "y") {
                                cout << "Restarting game!" << endl;
                                gameStarted = false;
                                break;
                            }
                            else cout << "Invalid input. Please try again" << endl;
                        }
                    }
                    
                    floor = nullptr;
                    floor = make_unique<Floor>(level);
                    floor->setPlayer(player);
                    floor->floorInit();
                    cout << *floor << endl;     
                }
            }
            else {
                cout << "Invalid input" << endl;
                cout << *floor << endl;
            }
        }
    }

    return 0;
}
