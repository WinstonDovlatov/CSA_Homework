#ifndef plane_h
#define plane_h

#include <stdio.h>

struct transport;

struct plane {
    int maxDistance, capacity;
};

void ConstructPlane(transport *transport, int maxDistance, int capacity);

void ReadPlane(FILE *file, transport *transport);

void WritePlane(FILE *file, plane *plane);

#endif
