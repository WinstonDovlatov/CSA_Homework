#ifndef HW5_BEAR_H
#define HW5_BEAR_H

#include <random>

class Bear {
public:
    /**
     * Создает медведя.
     * @param forestSize размер леса.
     */
    explicit Bear(int forestSize);

    /**
     * Выбирает зону, в которой спрячется медведь.
     * @return номер зоны.
     */
    int choseZone() const;

private:
    int forestSize_;
};

#endif
