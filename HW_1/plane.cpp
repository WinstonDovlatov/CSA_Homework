#include "plane.h"
#include "transport.h"
#include <stdio.h>

void ConstructPlane(transport *transport, int maxDistance, int capacity){
    transport->plane.maxDistance = maxDistance;
    transport->plane.capacity = capacity;
}

void ReadPlane(FILE *file, transport *transport){
    fscanf(file, "%d", &transport->plane.maxDistance);
    fscanf(file, "%d", &transport->plane.capacity);
}

void WritePlane(FILE *file, plane *plane){
    fprintf(file,"%d %d", plane->maxDistance, plane->capacity);
}

