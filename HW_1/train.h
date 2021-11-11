#ifndef train_h
#define train_h

#include <stdio.h>

struct transport;

struct train {
    int carsNumber;
};

void ConstructTrain(transport *transport, int carsNumber);

void ReadTrain(FILE *file, transport *transport);

void WriteTrain(FILE *file, train *train);


#endif
