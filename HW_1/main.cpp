#include "container.h"
#include <ctime>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <iostream>

FILE *getFile(char *file_name, const char *mode) {
    FILE *file = fopen(file_name, mode);
    if (file == nullptr) {
        printf("%s", "Error opening file \n");
        printf(file_name);
        exit(1);
    }

    return file;
}

void wrongFormatMessage() {
    printf("%s", "Incorrect command.\n "
                 "Waited for >>>command -f input_file output_file1 output_file2 \n"
                 "or >>>command -n number output_file1 output_file2");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        wrongFormatMessage();
        return 1;
    }
    bool from_file = false;
    int container_size = 0;

    if (!strcmp("-f", argv[1])) {
        from_file = true;
    } else if (!strcmp("-n", argv[1])) {
        from_file = false;
        container_size = atoi(argv[2]);
        if (container_size > 10000 || container_size < 1) {
            printf("%s", "Error! Size in interval [1, 10000].\n");
            return 1;
        }
    } else {
        wrongFormatMessage();
    }

    double start_time = clock();

    container* container;
    std::cout<<sizeof(&container)<<std::endl;

    if (from_file) {
        container = ReadContainer(getFile(argv[2], "r"));
    } else {
        container = GenerateContainer(container_size);
    }

    WriteContainer(getFile(argv[3], "w"), container);
    Sort(container);
    WriteContainer(getFile(argv[4], "w"), container);

    double total_time = clock() - start_time;

    printf("%s%lf%s", "Passed ", total_time, " ms.\n");
    return 0;
}
