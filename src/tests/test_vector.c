#include "tests/test_vector.h"

#include <stdio.h>
#include "include.h"
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
    
    printf(TEST_PRINT_FORMAT, "test_if_point()", if_point(p) ? PASS : FAIL);
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
    
    printf(TEST_PRINT_FORMAT, "test_if_vector()", if_vector(v) ? PASS : FAIL);
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

    printf(TEST_PRINT_FORMAT, "test_vector_equal()", vector_equal(v1, v2) ? PASS : FAIL);

    Vector v3 = {
        .x = 2.3,
        .y = 4.9,
        .z = -12.6,
        .w = 0.0
    };

    printf(TEST_PRINT_FORMAT, "test_vector_equal()", ! vector_equal(v1, v3) ? PASS : FAIL);
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

    printf(TEST_PRINT_FORMAT, "test_vector_add()", vector_equal(v3, v_out) ? PASS : FAIL);
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

    printf(TEST_PRINT_FORMAT, "test_vector_subtract()", vector_equal(v3, v_out) ? PASS : FAIL);
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

    printf(TEST_PRINT_FORMAT, "test_vector_negate()", vector_equal(v2, v_out) ? PASS : FAIL);
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

    printf(TEST_PRINT_FORMAT, "test_vector_scalar_multiply()", vector_equal(v2, v_out) ? PASS : FAIL);
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

    printf(TEST_PRINT_FORMAT, "test_vector_scalar_multiply()", vector_equal(v2, v_out) ? PASS : FAIL);
}

void test_vector_norm()
{
    Vector v1 = {
        .x = 1.0,
        .y = 0.0,
        .z = 0.0,
        .w = 0.0
    };

    printf(TEST_PRINT_FORMAT, "test_vector_norm()", equal(1.0, vector_norm(v1)) ? PASS : FAIL);

    Vector v2 = {
        .x = -1.0,
        .y = -1.0,
        .z = -1.0,
        .w = -1.0
    };

    printf(TEST_PRINT_FORMAT, "test_vector_norm()", equal(2.0, vector_norm(v2)) ? PASS : FAIL);
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

    printf(TEST_PRINT_FORMAT, "test_vector_normalize()", vector_equal(v2, v_out) ? PASS : FAIL);
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

    printf(TEST_PRINT_FORMAT, "test_vector_dot()", equal(f1, 20.0) ? PASS : FAIL);

    Vector v3 = {
        .x = 1.0,
        .y = 0.0,
        .z = 0.0,
        .w = 0.0
    };

    f2 = vector_dot(v3, v3);

    printf(TEST_PRINT_FORMAT, "test_vector_dot()", equal(f2, 1.0) ? PASS : FAIL);
}

void test_vector_cross()
{
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

    Vector v3 = {
        .x = -1.0,
        .y = 2.0,
        .z = -1.0,
        .w = 0.0
    };

    Vector v4 = {
        .x = 1.0,
        .y = -2.0,
        .z = 1.0,
        .w = 0.0
    };

    Vector v_out = vector_cross(v1, v2);

    printf(TEST_PRINT_FORMAT, "test_vector_cross()", vector_equal(v3, v_out) ? PASS : FAIL);

    v_out = vector_cross(v2, v1);

    printf(TEST_PRINT_FORMAT, "test_vector_cross()", vector_equal(v4, v_out) ? PASS : FAIL);
}
