#ifndef _TEST_INCLUDE_H_
#define _TEST_INCLUDE_H_

#include <stdio.h>
#include "include.h"

void test_equal()
{
    float a = 1;
    float b = 2;

    printf("test_equal(): \t%s\n", equal(a, b) == false ? "PASS" : "FAIL");
    
    a = 1.0;
    b = 1.0;
    printf("test_equal(): \t%s\n", equal(a, b) ? "PASS" : "FAIL");

    a = 1.0;
    b = 1.000001;
    printf("test_equal(): \t%s\n", equal(a, b) ? "PASS" : "FAIL");
}


#endif /* _TEST_INCLUDE_H_ */