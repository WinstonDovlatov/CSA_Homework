#include "container.h"
#include "transport.h"
#include <stdlib.h>


container *ConstructContainer(int size) {
    container *result = (container *) malloc(sizeof(transport));
    result->size = size;
    result->transports = (transport**) malloc(sizeof(transport)*size);
    return result;
}

void DestructContainer(container *container) {
    for (int i = 0; i < container->size; ++i) {
        DestructTransport(container->transports[i]);
    }

    free(container->transports);
    container->transports = nullptr;

    free(container);
    container = nullptr;
}

container *ReadContainer(FILE *file) {
    int size;
    fscanf(file, "%d", &size);

    container *container = ConstructContainer(size);

    for (int i = 0; i < container->size; ++i) {
        container->transports[i] = ReadTransport(file);
    }
    return container;
}

void WriteContainer(FILE *file, container *container) {
    fprintf(file, "%d\n", container->size);
    for (int i = 0; i < container->size; ++i) {
        WriteTransport(file, container->transports[i]);
        fprintf(file, "%s", "\n");
    }
}

container *GenerateContainer(int size){
    container* result = ConstructContainer(size);
    for(int i=0;i<result->size;++i){
        result->transports[i] = GenerateTransport();
    }
    return result;
}


void Sort(struct container *container) {
    for (int s = container->size / 2; s > 0; s /= 2) {
        for (int i = 0; i < container->size; i++) {
            for (int j = i + s; j < container->size; j += s) {
                if (MeasureTime(container->transports[i]) < MeasureTime(container->transports[j])) {
                    transport* tmp = container->transports[i];
                    container->transports[i] = container->transports[j];
                    container->transports[j] = tmp;
                }
            }
        }
    }
}