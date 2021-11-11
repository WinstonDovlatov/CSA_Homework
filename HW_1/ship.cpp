#include "tools.h"
#include "transport.h"
#include "ship.h"
#include <stdio.h>
#include "stdlib.h"

char *ReadString(FILE *file);

const char *linerName = "liner";
const char *towName = "tow";
const char *tankerName = "tanker";

void ConstructShip(struct transport *transport, enum shipType shipType, int displacement) {
    transport->ship.shipType = shipType;
    transport->ship.displacement = displacement;
}

void ReadShip(FILE *file, transport *transport) {
    fscanf(file, "%d", &transport->ship.displacement);
    char *shipTypeName = ReadString(file);

    if (!strcmp(shipTypeName, towName)) {
        transport->ship.shipType = TOW;
    } else if (!strcmp(shipTypeName, linerName)) {
        transport->ship.shipType = LINER;
    } else if (!strcmp(shipTypeName, tankerName)) {
        transport->ship.shipType = TANKER;
    }
}

void WriteShip(FILE *file, ship *ship){
    fprintf(file,"%d ", ship->displacement);
    if(ship->shipType == TOW){
        fprintf(file, towName);
    } else if (ship->shipType == TANKER){
        fprintf(file, tankerName);
    } else if (ship->shipType == LINER){
        fprintf(file, linerName);
    }
}