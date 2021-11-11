#include "transport.h"
#include <stdlib.h>
#include <string.h>

int RandInt(int min, int max);

char *ReadString(FILE *file);


transport *ConstructTransport(int velocity, double distance) {
    transport *result = (transport *) malloc(sizeof(transport));
    result->velocity = velocity;
    result->distance = distance;

    return result;
}

void DestructTransport(transport *transport) {
    free(transport);
    transport = nullptr;
}

double MeasureTime(transport *transport) {
    if (((transport->type == PLANE) && (transport->plane.maxDistance < transport->distance)) ||
        transport->velocity == 0) {
        return 10000000;
    } else {
        return transport->distance / transport->velocity;
    }
}

transport *ReadTransport(FILE *file) {
    int velocity;
    double distance;
    char *transportType = ReadString(file);

    fscanf(file, "%d", &velocity);
    fscanf(file, "%lf", &distance);

    transport *result = ConstructTransport(velocity, distance);

    if (!strcmp(transportType, "Ship")) {
        ReadShip(file, result);
        result->type = SHIP;
    } else if (!strcmp(transportType, "Plane")) {
        ReadPlane(file, result);
        result->type = PLANE;
    } else if (!strcmp(transportType, "Train")) {
        ReadTrain(file, result);
        result->type = TRAIN;
    }

    free(transportType);

    return result;
}

void WriteTransport(FILE *file, transport *transport) {

    if (transport->type == PLANE) {
        fprintf(file, "%s", "Plane ");
    } else if (transport->type == SHIP) {
        fprintf(file, "%s", "Ship ");
    } else if (transport->type == TRAIN) {
        fprintf(file, "%s", "Train ");
    }

    fprintf(file, "%d %lf ", transport->velocity, transport->distance);

    if (transport->type == PLANE) {
        WritePlane(file, &transport->plane);
    } else if (transport->type == SHIP) {
        WriteShip(file, &transport->ship);
    } else if (transport->type == TRAIN) {
        WriteTrain(file, &transport->train);
    }
}

transport *GenerateTransport() {
    transport *result = ConstructTransport(RandInt(0, 100), (double)RandInt(1, 500));

    int type = RandInt(0, 3);

    if (type == 0) {
        result->type = PLANE;
        ConstructPlane(result, RandInt(290, 1000), RandInt(10, 30));
    } else if (type == 1) {
        result->type = SHIP;
        int shipTypeIdx = RandInt(0, 3);
        shipType shipType = LINER;
        if (shipTypeIdx == 0) {
            shipType = TANKER;
        } else if (shipTypeIdx == 1) {
            shipType = TOW;
        } else if (shipTypeIdx == 2) {
            shipType = LINER;
        }
        ConstructShip(result, shipType, RandInt(40, 130));
    } else if (type == 2) {
        result->type = TRAIN;
        ConstructTrain(result, RandInt(10, 50));
    }

    return result;
}

