#ifndef train_h
#define train_h

#include <cstdio>
#include "transport.h"

class train : public transport {
public:
    int carsNumber;

    train() = default;

    ~train() = default;

    // Read train information from file.
    void Read(FILE *file) override;

    // Write train information to file.
    void Write(FILE *file) override;

    // Generate random train.
    void Generate() override;
};

#endif
