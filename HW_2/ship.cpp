#include <cstdlib>
#include <cstring>
#include "ship.h"


int RandInt(int min, int max);

char *ReadString(FILE *file);

const char *liner_name = "liner";
const char *tow_name = "tow";
const char *tanker_name = "tanker";

// Read ship information from file.
void ship::Read(FILE *file) {
    transport::Read(file);
    fscanf(file, "%d", &this->displacement);
    char *current_type = ReadString(file);

    if (!strcmp(current_type, liner_name)) {
        this->type = shipType::LINER;
    } else if (!strcmp(current_type, tow_name)) {
        this->type = shipType::TOW;
    } else if (!strcmp(current_type, tanker_name)) {
        this->type = shipType::TANKER;
    } else {
        exit(1);
    }
    free(current_type);
}

// Write ship information to file.
void ship::Write(FILE *file) {
    fprintf(file, "%s", "ship ");
    transport::Write(file);
    fprintf(file, "%c%d%c", ' ', this->displacement, ' ');
    if (this->type == shipType::TANKER) {
        fprintf(file, "%s", tanker_name);
    } else if (this->type == shipType::TOW) {
        fprintf(file, "%s", tow_name);
    } else {
        fprintf(file, liner_name);
    }
}

// Generate random ship.
void ship::Generate() {
    transport::Generate();
    this->displacement = RandInt(10, 350);
    this->type = (shipType)(rand() % 3);
}