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

void test_vector_add()
{
    Vector v1 = {
        .x = 2.3,
        .y = 3.4,
        .z = 12.6,
        .w = 0.0
    };

    Vector v2 = {
        .x = 2.3,
        .y = 3.4,
        .z = -12.6,
        .w = 1.0
    };

    Vector v3 = {
        .x = 4.6,
        .y = 6.8,
        .z = 0.0,
        .w = 1.0
    };

    Vector v_out = vector_add(v1, v2);

    printf("test_vector_add(): \t%s\n", vector_equal(v3, v_out) ? "PASS" : "FAIL");
}

void test_vector_subtract()
{
    Vector v1 = {
        .x = 2.3,
        .y = 3.4,
        .z = 1.1,
        .w = 1.0
    };

    Vector v2 = {
        .x = 2.3,
        .y = 3.4,
        .z = 1.0,
        .w = 1.0
    };

    Vector v3 = {
        .x = 0.0,
        .y = 0.0,
        .z = 0.1,
        .w = 0.0
    };

    Vector v_out = vector_subtract(v1, v2);

    printf("test_vector_subtract(): \t%s\n", vector_equal(v3, v_out) ? "PASS" : "FAIL");
}

void test_vector_negate()
{
    Vector v1 = {
        .x = 2.3,
        .y = 3.4,
        .z = 1.1,
        .w = 1.0
    };

    Vector v2 = {
        .x = -2.3,
        .y = -3.4,
        .z = -1.1,
        .w = -1.0
    };

    Vector v_out = vector_negate(v1);

    printf("test_vector_negate(): \t%s\n", vector_equal(v2, v_out) ? "PASS" : "FAIL");
}

void test_vector_scalar_multiply()
{
    Vector v1 = {
        .x = 2.3,
        .y = 3.4,
        .z = 1.1,
        .w = 1.0
    };

    Vector v2 = {
        .x = 4.6,
        .y = 6.8,
        .z = 2.2,
        .w = 2.0
    };

    Vector v_out = vector_scalar_multiply(v1, 2.0);

    printf("test_vector_scalar_multiply(): \t%s\n", vector_equal(v2, v_out) ? "PASS" : "FAIL");
}


void test_vector_scalar_divide()
{
    Vector v1 = {
        .x = 4.6,
        .y = 6.8,
        .z = 2.2,
        .w = 2.0
    };

    Vector v2 = {
        .x = 2.3,
        .y = 3.4,
        .z = 1.1,
        .w = 1.0
    };

    Vector v_out = vector_scalar_divide(v1, 2.0);

    printf("test_vector_scalar_multiply(): \t%s\n", vector_equal(v2, v_out) ? "PASS" : "FAIL");
}

void test_vector_norm()
{
    Vector v1 = {
        .x = 1.0,
        .y = 0.0,
        .z = 0.0,
        .w = 0.0
    };

    printf("test_vector_norm(): \t%s\n", equal(1.0, vector_norm(v1)) ? "PASS" : "FAIL");

    Vector v2 = {
        .x = -1.0,
        .y = -1.0,
        .z = -1.0,
        .w = -1.0
    };

    printf("test_vector_norm(): \t%s\n", equal(2.0, vector_norm(v2)) ? "PASS" : "FAIL");
}

void test_vector_normalize()
{
    Vector v1 = {
        .x = 4.0,
        .y = 0.0,
        .z = 0.0,
        .w = 0.0
    };

    Vector v2 = {
        .x = 1.0,
        .y = 0.0,
        .z = 0.0,
        .w = 0.0
    };

    Vector v_out = vector_normalize(v1);

    printf("test_vector_normalize(): \t%s\n", vector_equal(v2, v_out) ? "PASS" : "FAIL");
}

void test_vector_dot()
{
    float f1, f2;
    Vector v1 = {
        .x = 1.0,
        .y = 2.0,
        .z = 3.0,
        .w = 0.0
    };

    Vector v2 = {
        .x = 2.0,
        .y = 3.0,
        .z = 4.0,
        .w = 0.0
    };

    f1 = vector_dot(v1, v2);

    printf("test_vector_dot(): \t%s\n", equal(f1, 20.0) ? "PASS" : "FAIL");

    Vector v3 = {
        .x = 1.0,
        .y = 0.0,
        .z = 0.0,
        .w = 0.0
    };

    f2 = vector_dot(v3, v3);

    printf("test_vector_dot(): \t%s\n", equal(f2, 1.0) ? "PASS" : "FAIL");
}












#endif /* _TEST_VECTOR_H_ */