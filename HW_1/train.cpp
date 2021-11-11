#include "train.h"
#include "transport.h"
#include <stdio.h>

void ConstructTrain(struct transport *transport, int carsNumber){
    transport->train.carsNumber = carsNumber;
}

void ReadTrain(FILE *file, struct transport *transport){
    fscanf(file, "%d", &transport->train.carsNumber);
}

void WriteTrain(FILE *file, struct train *train){
    fprintf(file,"%d", train->carsNumber);
}
