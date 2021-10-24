#ifndef container_h
#define container_h

#include "transport.h"

struct container{
public:
    int size;
    transport*(*transports);

    explicit container(int size);

    container() = default;

    ~container();

    // Read container information from file.
    void Read(FILE *file);

    // Write container information to file.
    void Write(FILE *file);

    // Generate container of given size.
    void Generate(int len);

    // Sort transports by time.
    void Sort();
};

#endif
