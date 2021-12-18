#ifndef HW5_UTILITY_H
#define HW5_UTILITY_H

#include <string>

/**
 * Читает целое число из консоли с ограничениями.
 * @param minV минимальный размер числа.
 * @param maxV максимальный размер числа.
 * @param title сообщение в консоли.
 * @return корректно число, считанное из консоли.
 */
int readIntFromConsole(int minV, int maxV, const std::string &title) {

    int result;
    while (true) {
        std::cout << title << " >>>";
        std::cin >> result;
        if (result > maxV || result < minV) {
            std::cout << "Value mast be in interval [" << minV << ", " << maxV << "]\n";
        } else {
            std::cout << "Value set at " << result << std::endl;
            return result;
        }
    }

}

#endif
