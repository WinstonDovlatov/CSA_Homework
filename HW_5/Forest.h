#ifndef HW5_FOREST_H
#define HW5_FOREST_H

#include <iostream>
#include <cstddef>
#include "Bear.h"


class Forest {
public:
    /**
     * Создает лес.
     * @param size количество ячеек для поиска.
     * @param bear медведь, что спрятался.
     */
    Forest(int size, Bear bear);

    ~Forest();

    /**
     * Вовзращает размер леса в ячейках.
     * @return размер леса в ячейках.
     */
    int getSize() const;

    /**
     * Прячет медведя в указанной ячейке.
     * @param zoneNumber номер ячейки.
     */
    void hideInZone(int zoneNumber);

    /**
     * Проверяет находится ли в ячейке медведь.
     * @param zoneNumber номер ячейки.
     * @return true, если в ячейке находитмся медведь. false - иначе.
     */
    bool zoneStatus(int zoneNumber) const;

private:
    int size_;
    bool *zones_;
};

#endif
