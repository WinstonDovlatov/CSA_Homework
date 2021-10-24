#include "plane.h"

int RandInt(int min, int max);

// Read plane information from file.
void plane::Read(FILE *file) {
    transport::Read(file);
    fscanf(file, "%d", &this->maxDistance);
    fscanf(file, "%d", &this->capacity);
}

// Write plane information to file.
void plane::Write(FILE *file) {
    fprintf(file, "%s", "plane ");
    transport::Write(file);
    fprintf(file, "%c%d%c%d", ' ', this->maxDistance, ' ', this->capacity);
}

// Calculate time to cover the distance.
double plane::MeasureTime() {
    if (this->maxDistance < this->distance) {
        return 0;
    }
    return this->distance / this->velocity;
}

// Generate random plane.
void plane::Generate() {
    transport::Generate();
    this->maxDistance = RandInt(1, 1000);
    this->capacity = RandInt(0, 1000);
}

