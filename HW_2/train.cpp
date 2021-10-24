#include "train.h"

int RandInt(int min, int max);

// Write train information in file.
void train::Write(FILE *file) {
    fprintf(file, "%s", "train ");
    transport::Write(file);
    fprintf(file, "%c%d", ' ', this->carsNumber);
}

// Read train information from file.
void train::Read(FILE *file) {
    transport::Read(file);
    fscanf(file, "%d", &this->carsNumber);
}

// Generate random train.
void train::Generate() {
    transport::Generate();
    this->carsNumber = RandInt(1, 50);
}