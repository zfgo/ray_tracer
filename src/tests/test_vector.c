#include "tests/test_vector.h"

#include <stdio.h>
#include "include.h"
#include "datatypes/vector.h"


/* test that the if_point function works correctly
 */
void test_if_point()
{
    Vec p = {
        .v = {2.3, 3.9, -12.6, 1.0}
    };
    
    printf(TEST_PRINT_FORMAT, "test_if_point()", if_point(p) ? PASS : FAIL);
}

/* test that the if_vector function works correctly
 */
void test_if_vector()
{
    Vec v = {
        .v = {2.3, 3.9, -12.6, 0.0}
    };
    
    printf(TEST_PRINT_FORMAT, "test_if_vector()", if_vector(v) ? PASS : FAIL);
}

void test_vector_equal()
{

    Vec v1 = {
        .v = {2.3, 3.9, -12.6, 0.0}
    };

    Vec v2 = {
        .v = {2.3, 3.9, -12.6, 0.0}
    };

    printf(TEST_PRINT_FORMAT, "test_vector_equal()", vector_equal(v1, v2) ? PASS : FAIL);

    Vec v3 = {
        .v = {2.3, 4.9, -12.6, 0.0}
    };

    printf(TEST_PRINT_FORMAT, "test_vector_equal()", ! vector_equal(v1, v3) ? PASS : FAIL);
}

void test_vector_add()
{
    Vec v1 = {
        .v = {2.3, 3.4, 12.6, 0.0}
    };

    Vec v2 = {
        .v = {2.3, 3.4, -12.6, 1.0}
    };

    Vec v3 = {
        .v = {4.6, 6.8, 0.0, 1.0}
    };

    Vec v_out = vector_add(v1, v2);

    printf(TEST_PRINT_FORMAT, "test_vector_add()", vector_equal(v3, v_out) ? PASS : FAIL);
}

void test_vector_subtract()
{
    Vec v1 = {
        .v = {2.3, 3.4, 1.1, 1.0}
    };

    Vec v2 = {
        .v = {2.3, 3.4, 1.0, 1.0}
    };

    Vec v3 = {
        .v = {0.0, 0.0, 0.1, 0.0}
    };

    Vec v_out = vector_subtract(v1, v2);

    printf(TEST_PRINT_FORMAT, "test_vector_subtract()", vector_equal(v3, v_out) ? PASS : FAIL);
}

void test_vector_negate()
{
    Vec v1 = {
        .v = {2.3, 3.4, 1.1, 1.0}
    };

    Vec v2 = {
        .v = {-2.3, -3.4, -1.1, -1.0}
    };

    Vec v_out = vector_negate(v1);

    printf(TEST_PRINT_FORMAT, "test_vector_negate()", vector_equal(v2, v_out) ? PASS : FAIL);
}

void test_vector_scalar_multiply()
{
    Vec v1 = {
        .v = {2.3, 3.4, 1.1, 1.0}
    };

    Vec v2 = {
        .v = {4.6, 6.8, 2.2, 2.0}
    };

    Vec v_out = vector_scalar_multiply(v1, 2.0);

    printf(TEST_PRINT_FORMAT, "test_vector_scalar_multiply()", vector_equal(v2, v_out) ? PASS : FAIL);
}


void test_vector_scalar_divide()
{
    Vec v1 = {
        .v = {4.6, 6.8, 2.2, 2.0}
    };

    Vec v2 = {
        .v = {2.3, 3.4, 1.1, 1.0}
    };

    Vec v_out = vector_scalar_divide(v1, 2.0);

    printf(TEST_PRINT_FORMAT, "test_vector_scalar_multiply()", vector_equal(v2, v_out) ? PASS : FAIL);
}

void test_vector_norm()
{
    Vec v1 = {
        .v = {1.0, 0.0, 0.0, 0.0}
    };

    printf(TEST_PRINT_FORMAT, "test_vector_norm()", equal(1.0, vector_norm(v1)) ? PASS : FAIL);

    Vec v2 = {
        .v = {-1.0, -1.0, -1.0, -1.0}
    };

    printf(TEST_PRINT_FORMAT, "test_vector_norm()", equal(2.0, vector_norm(v2)) ? PASS : FAIL);
}

void test_vector_normalize()
{
    Vec v1 = {
        .v = {4.0, 0.0, 0.0, 0.0}
    };

    Vec v2 = {
        .v = {1.0, 0.0, 0.0, 0.0}
    };

    Vec v_out = vector_normalize(v1);

    printf(TEST_PRINT_FORMAT, "test_vector_normalize()", vector_equal(v2, v_out) ? PASS : FAIL);
}

void test_vector_dot()
{
    float f1, f2;
    Vec v1 = {
        .v = {1.0, 2.0, 3.0, 0.0}
    };

    Vec v2 = {
        .v = {2.0, 3.0, 4.0, 0.0}
    };

    f1 = vector_dot(v1, v2);

    printf(TEST_PRINT_FORMAT, "test_vector_dot()", equal(f1, 20.0) ? PASS : FAIL);

    Vec v3 = {
        .v = {1.0, 0.0, 0.0, 0.0}
    };

    f2 = vector_dot(v3, v3);

    printf(TEST_PRINT_FORMAT, "test_vector_dot()", equal(f2, 1.0) ? PASS : FAIL);
}

void test_vector_cross()
{
    Vec v1 = {
        .v = {1.0, 2.0, 3.0, 0.0}
    };

    Vec v2 = {
        .v = {2.0, 3.0, 4.0, 0.0}
    };

    Vec v3 = {
        .v = {-1.0, 2.0, -1.0, 0.0}
    };

    Vec v4 = {
        .v = {1.0, -2.0, 1.0, 0.0}
    };

    Vec v_out = vector_cross(v1, v2);

    printf(TEST_PRINT_FORMAT, "test_vector_cross()", vector_equal(v3, v_out) ? PASS : FAIL);

    v_out = vector_cross(v2, v1);

    printf(TEST_PRINT_FORMAT, "test_vector_cross()", vector_equal(v4, v_out) ? PASS : FAIL);
}
