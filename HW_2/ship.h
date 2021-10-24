#ifndef ship_h
#define ship_h

#include <cstdio>
#include "transport.h"

enum shipType {
    LINER, TOW, TANKER
};


class ship : public transport {
public:
    int displacement;
    shipType type;

    ship() = default;

    ~ship() = default;

    // Read ship information from file.
    void Read(FILE *file) override;

    // Write ship information to file.
    void Write(FILE *file) override;

    // Generate random ship.
    void Generate() override;
};

#endif