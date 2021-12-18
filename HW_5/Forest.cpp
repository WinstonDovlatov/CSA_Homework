#include "Forest.h"

Forest::Forest(int size, Bear bear) {
    this->size_ = size;
    this->zones_ = new bool[size];
    for (size_t i = 0; i < size; ++i) {
        zones_[i] = false;
    }
    int zone = bear.choseZone();
    hideInZone(zone);

    std::cout << "Bear hide in " << zone << "th zone." << std::endl;
}

Forest::~Forest() {
    delete[] zones_;
    zones_ = nullptr;
}

int Forest::getSize() const {
    return size_;

}

void Forest::hideInZone(int zoneNumber) {
    zones_[zoneNumber] = true;
}

bool Forest::zoneStatus(int zoneNumber) const {
    return zones_[zoneNumber];
}