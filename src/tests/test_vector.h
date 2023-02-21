#ifndef _TEST_VECTOR_H_
#define _TEST_VECTOR_H_

#include <stdio.h>
#include "datatypes/vector.h"

/* test that the if_point function works correctly
 */
void test_if_point()
{
    Vector p = {
        .x = 2.3,
        .y = 3.9,
        .z = -12.6,
        .w = 1.0
    };
    
    printf("test_if_point(): \t%s\n", if_point(p) ? "PASS" : "FAIL");
}

/* test that the if_vector function works correctly
 */
void test_if_vector()
{
    Vector v = {
        .x = 2.3,
        .y = 3.9,
        .z = -12.6,
        .w = 0.0
    };
    
    printf("test_if_vector(): \t%s\n", if_vector(v) ? "PASS" : "FAIL");
}

void test_vector_equal()
{

    Vector v1 = {
        .x = 2.3,
        .y = 3.9,
        .z = -12.6,
        .w = 0.0
    };

    Vector v2 = {
        .x = 2.3,
        .y = 3.9,
        .z = -12.6,
        .w = 0.0
    };

    printf("test_vector_equal(): \t%s\n", vector_equal(v1, v2) ? "PASS" : "FAIL");

    Vector v2 = {
        .x = 2.3,
        .y = 4.9,
        .z = -12.6,
        .w = 0.0
    };

    printf("test_vector_equal(): \t%s\n", ! vector_equal(v1, v2) ? "PASS" : "FAIL");


}

#endif /* _TEST_VECTOR_H_ */