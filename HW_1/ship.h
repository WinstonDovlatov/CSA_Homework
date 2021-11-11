#ifndef ship_h
#define ship_h

#include <stdio.h>

struct transport;

enum shipType {
    LINER, TOW, TANKER
};

struct ship {
    enum shipType shipType;
    int displacement;
};

void ConstructShip(transport *transport, shipType shipType, int displacement);

void ReadShip(FILE *file, transport *transport);

void WriteShip(FILE *file, ship *ship);

#endif
