#include "container.h"
#include <cstring>
#include <cstdlib>
#include "plane.h"
#include "ship.h"
#include "train.h"

char *ReadString(FILE *file);

container::container(int size) {
    this->size = size;
    transports = new transport *[size];
}

container::~container() {
    for (int i = 0; i < this->size; ++i) {
        delete transports[i];
    }
    delete transports;
}

// Read container information from file.
void container::Read(FILE *file) {
    fscanf(file, "%d", &this->size);
    transports = new transport *[this->size];

    for (int i = 0; i < this->size; ++i) {
        char *transport_name = ReadString(file);

        if (!strcmp(transport_name, "ship")) {
            transports[i] = new ship();
        } else if (!strcmp(transport_name, "plane")) {
            transports[i] = new plane();
        } else if (!strcmp(transport_name, "train")) {
            transports[i] = new train();
        } else {
            exit(1);
        }
        transports[i]->Read(file);

        free(transport_name);
    }
}

// Write container information to file.
void container::Write(FILE *file) {
    fprintf(file, "%d%c", this->size, '\n');
    for (int i = 0; i < this->size; ++i) {
        transports[i]->Write(file);
        fprintf(file, "%c", '\n');
    }
}

// Generate container of given size.
void container::Generate(int len) {
    this->size = len;
    transports = new transport *[len];

    for (int i = 0; i < this->size; ++i) {
        int transport_type = rand() % 3;
        switch (transport_type) {
            case 0:
                transports[i] = new plane();
                break;
            case 1:
                transports[i] = new ship();
                break;
            case 2:
                transports[i] = new train();
                break;
        }
        transports[i]->Generate();
    }
}

// Sort transports by time.
void container::Sort() {
    for (int s = this->size / 2; s > 0; s /= 2) {
        for (int i = 0; i < this->size; i++) {
            for (int j = i + s; j < this->size; j += s) {
                if (this->transports[i]->MeasureTime() > this->transports[j]->MeasureTime()) {
                    transport *tmp = transports[i];
                    transports[i] = transports[j];
                    transports[j] = tmp;
                }
            }
        }
    }
}

