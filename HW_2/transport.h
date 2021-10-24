#ifndef transport_h
#define transport_h

#include <cstdio>

class transport {
public:
    int velocity;
    double distance;

    transport();

    // Calculate time to cover the distance.
    virtual double MeasureTime();

    // Read transport information from file.
    virtual void Read(FILE *file);

    //  Write transport information to file.
    virtual void Write(FILE *file);

    // Generate random transport.
    virtual void Generate();
};

#endif
