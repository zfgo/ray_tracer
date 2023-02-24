#include <stdio.h>
#include "include.h"

void test_equal()
{
    float a = 1.0;
    float b = 2.0;

    printf("test_equal(): \t%s\n", equal(a, b) == false ? "PASS" : "FAIL");
    
    a = 1.0;
    b = 1.0;
    printf("test_equal(): \t%s\n", equal(a, b) ? "PASS" : "FAIL");

    a = 1.0;
    b = 1.000001;
    printf("test_equal(): \t%s\n", equal(a, b) ? "PASS" : "FAIL");
}
