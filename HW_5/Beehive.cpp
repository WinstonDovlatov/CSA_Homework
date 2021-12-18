#include "Beehive.h"

void Beehive::exploreZone(int zoneNumber) {
    std::this_thread::sleep_for(std::chrono::milliseconds(timeForSearch_));
    bool result = forest_->zoneStatus(zoneNumber);
    saveResult(zoneNumber, result);
}

void Beehive::exploreForestParallel() {
    results_.clear();
    std::thread threads[forest_->getSize()];
    for (int i = 0; i < forest_->getSize(); ++i) {
        threads[i] = std::thread(&Beehive::exploreZone, this, i);
    }

    for (int i = 0; i < forest_->getSize(); ++i) {
        threads[i].join();
    }
}

void Beehive::exploreForestSequentially() {
    results_.clear();
    for (int i = 0; i < forest_->getSize(); ++i) {
        exploreZone(i);
    }
}


void Beehive::saveResult(int zoneNumber, int result) {
    resultsMutex_.lock();
    results_.push_front(std::make_pair(zoneNumber, result));
    resultsMutex_.unlock();
}

Beehive::Beehive(int timeForSearch, Forest *forest) {
    timeForSearch_ = timeForSearch;
    forest_ = forest;
    results_ = std::forward_list<std::pair<int, bool>>();
}

void Beehive::printResult() {
    for (auto pair: results_) {
        if (pair.second) {
            std::cout << "Find bear in " << pair.first << "th zone." << std::endl;
            return;
        }
    }
}
