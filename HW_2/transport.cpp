#include "transport.h"

transport::transport() {

}

int RandInt(int min, int max);

// Calculate time to cover the distance.
double transport::MeasureTime() {
    if (this->velocity == 0) {
        return 0;
    }
    return this->distance / this->velocity;
}

// Read transport information from file.
void transport::Read(FILE *file) {
    fscanf(file, "%d", &this->velocity);
    fscanf(file, "%lf", &this->distance);
}

//  Write transport information to file.
void transport::Write(FILE *file) {
    fprintf(file, "%d%c%f", this->velocity, ' ', this->distance);
}

// Generate random transport.
void transport::Generate() {
    this->velocity = RandInt(1, 500);
    this->distance = RandInt(1, 1000);
}