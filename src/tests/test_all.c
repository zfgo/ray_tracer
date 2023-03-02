#include "tests/test_all.h"

void test_all()
{
    /* Canvas tests */ 
    test_canvas_simple();
    test_canvas_complex();

    /* Color tests */ 
    test_color_equal();
    test_color_add();
    test_color_subtract();
    test_color_multiply();
    test_color_scalar_multiply();

    /* include tests */
    test_equal();

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

    /* matrix tests */
    test_matrix4_equal();
    test_matrix3_equal();
    test_matrix2_equal();
    test_matrix4_compose();
    test_matrix4_vector_multiply();
    test_matrix4_transpose();
    test_matrix4_determinant();
    test_matrix3_determinant();
    test_matrix2_determinant();
    test_matrix4_invert();
}
