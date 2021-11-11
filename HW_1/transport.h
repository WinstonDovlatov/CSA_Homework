#ifndef transport_h
#define transport_h

#include <stdio.h>
#include "plane.h"
#include "ship.h"
#include "train.h"


enum transportType {
    PLANE,
    SHIP,
    TRAIN
};

struct transport {
    union {
        plane plane;
        ship ship;
        train train;
    };

    enum transportType type;
    int velocity;
    double distance;
};

transport *ConstructTransport(int velocity, double distance);

void DestructTransport(transport *transport);

double MeasureTime(transport *transport);

transport *ReadTransport(FILE *file);

void WriteTransport(FILE *file, transport *transport);

transport *GenerateTransport();


#endif
