#ifndef tools_h
#define tools_h

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <random>

// Generate random number in the range [min, max).
int RandInt(int min, int max) {
    return rand() % (max - min) + min;
}

// Read string from file.
char *ReadString(FILE *file) {
    int capacity = 8, size = 0;
    char *str = (char *) malloc(sizeof(char) * capacity);
    char cur;
    bool breakSensitivity = false;

    while ((cur = fgetc(file)) != EOF) {
        if ((cur == ' ') || (cur == '\n')) {
            if (!breakSensitivity) {
                breakSensitivity = true;
                continue;
            } else {
                break;
            }
        } else {
            breakSensitivity = true;
        }
        str[size] = cur;
        ++size;

        if (capacity == size) {
            capacity *= 2;
            str = (char *) realloc(str, sizeof(char) * capacity);
        }
    }

    str[size] = '\0';
    ++size;
    return (char *) realloc(str, sizeof(char) * size);
}

#endif
