#include "utils.h"

std::pair<int, int> getDirection(std::string cmd) {
    std::pair<int, int> coords; // [?] initialized to zero
    
    if (cmd == "no") {--coords.second;}
    else if (cmd == "so") {++coords.second;}
    else if (cmd == "ea") {++coords.first;}
    else if (cmd == "we") {--coords.first;}
    else if (cmd == "ne") {++coords.first; --coords.second;}
    else if (cmd == "nw") {--coords.first; --coords.second;}
    else if (cmd == "se") {++coords.first; ++coords.second;}
    else if (cmd == "sw") {--coords.first; ++coords.second;}
    
    return coords;
}
