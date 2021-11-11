#ifndef container_h
#define container_h

#include "transport.h"

struct container {
    int size;
    transport *(*transports);
};

container *ConstructContainer(int size);

void DestructContainer(container *container);

container *ReadContainer(FILE *file);

void WriteContainer(FILE *file, container *container);

container *GenerateContainer(int size);

void Sort(container *container);

#endif
