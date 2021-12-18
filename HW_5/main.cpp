#include <iostream>
#include <ctime>
#include "Forest.h"
#include "Beehive.h"
#include "Utility.h"

using namespace std;

int main() {
    int forestSize, timeForSearch;
    std::cout << "Enter forest size.\n";
    forestSize = readIntFromConsole(1, 100, "forest size");

    std::cout << "\nEnter time in ms to search in one cell of the forest by bees.\n";
    timeForSearch = readIntFromConsole(1, 2000, "time for search");

    std::cout << "\n\n";

    Bear bear(forestSize);
    Forest forest(forestSize, bear);
    Beehive beehive(timeForSearch, &forest);

    std::cout << std::endl << "Looking for bear in parallel..." << std::endl;
    auto startParallel = clock();
    beehive.exploreForestParallel();
    auto endParallel = clock();
    std::cout << "Bear caught!\n";
    beehive.printResult();

    std::cout << std::endl << "Looking for bear step by step..." << std::endl;
    auto startSeq = clock();
    beehive.exploreForestSequentially();
    auto endSeq = clock();
    std::cout << "Bear caught!\n";
    beehive.printResult();

    std::cout << "\n\n";

    std::cout << "Time passed for parallel execution: " << endParallel - startParallel << "ms." << std::endl;
    std::cout << "Time passed for sequential execution: " << endSeq - startSeq << "ms." << std::endl;

    return 0;
}
