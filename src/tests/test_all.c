#include "tests/test_all.h"

void test_all()
{
    /* Color tests */ 
    test_color_equal();
    test_color_add();
    test_color_subtract();
    test_color_multiply();
    test_color_scalar_multiply();

    /* vector tests */
    test_if_point();
    test_if_vector();
    test_vector_equal();
    test_vector_add();
    test_vector_subtract();
    test_vector_negate();
    test_vector_scalar_multiply();
    test_vector_scalar_divide();
    test_vector_norm();
    test_vector_normalize();
    test_vector_dot();
    test_vector_cross();

    /* include tests */
    test_equal();
}
