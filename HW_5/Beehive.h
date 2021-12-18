#ifndef HW5_BEEHIVE_H
#define HW5_BEEHIVE_H

#include <thread>
#include <forward_list>
#include <utility>
#include <mutex>
#include <iostream>
#include <thread>
#include <chrono>
#include "Forest.h"


class Beehive {
public:
    /**
     * Создает улей.
     * @param timeForSearch времся в ms, необходимое для поиска в одной зоне.
     * @param forest лес, в котором спрятался медведь.
     */
    Beehive(int timeForSearch, Forest *forest);

    /**
     * Поиск медведя с использованием потоков.
     */
    void exploreForestParallel();

    /**
     * Поиск медведя без использования потоков, последовательно.
     */
    void exploreForestSequentially();

    /**
     * Отображение результатов поиска - номер ячейки, в которой спрятался медведь.
     */
    void printResult();

private:
    int timeForSearch_;
    Forest *forest_;

    void exploreZone(int zoneNumber);

    void saveResult(int zoneNumber, int result);

    std::forward_list<std::pair<int, bool>> results_;
    std::mutex resultsMutex_;
};

#endif
