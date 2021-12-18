#include "Bear.h"

Bear::Bear(int forestSize) {
    forestSize_ = forestSize;
}

int Bear::choseZone() const {
    std::random_device device;
    std::mt19937 random(device());

    return std::abs((int) random()) % forestSize_;
}
