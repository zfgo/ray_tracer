#include <stdio.h>
#include "include.h"

void test_equal()
{
    float a = 1.0;
    float b = 2.0;

    printf(TEST_PRINT_FORMAT, "test_equal()", equal(a, b) == false ? PASS : FAIL);
    
    a = 1.0;
    b = 1.0;
    printf(TEST_PRINT_FORMAT, "test_equal()", equal(a, b) ? PASS : FAIL);

    a = 1.0;
    b = 1.000001;
    printf(TEST_PRINT_FORMAT, "test_equal()", equal(a, b) ? PASS : FAIL);
}
