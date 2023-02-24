#include "tests/test_all.h"

void test_all()
{
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
