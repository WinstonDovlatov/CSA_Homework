#ifndef plane_h
#define plane_h

#include <cstdio>
#include "transport.h"

class plane : public transport {
public:
    int maxDistance;
    int capacity;

    plane() = default;

    ~plane() = default;

    // Read plane information from file.
    void Read(FILE *file) override;

    // Write plane information to file.
    void Write(FILE *file) override;

    // Generate random plane.
    void Generate() override;

    // Calculate time to cover the distance.
    double MeasureTime() override;
};

#endif
