#include "include.h"
#include "tests/test_all.h"

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int opt;

    while ((opt = getopt(argc, argv, "t")) != -1) {
        switch (opt) {
            case 't':
                test_all();
                return 0;
            default:
                // fprintf(stderr, "Error: invalid option '-%c'\n", optopt);
                return 0;
        }
    }

    printf("Hello world\n");
    return 0;
}
