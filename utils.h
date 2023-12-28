// Small utility functions

#ifndef UTILS_H
#define UTILS_H


#include <string>
#include <utility>


std::pair<int, int> getDirection(std::string cmd);

#endif


#ifdef DEBUG
#define DEBUG_PRINT(msg) std::cerr << "DEBUG: " << msg << std::endl
#else
#define DEBUG_PRINT(msg)
#endif
