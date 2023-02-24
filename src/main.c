#include <stdio.h>
#include "include.h"
#include "tests/test_all.h"

int main(void)
{
#ifdef TEST 
    test_all();
#endif

    printf("Hello world\n");
    return 0;
}
