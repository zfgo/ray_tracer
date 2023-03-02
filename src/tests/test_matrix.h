#ifndef _TEST_MATRIX_H_
#define _TEST_MATRIX_H_

#include "datatypes/matrix.h"
#include "datatypes/vector.h"

// need tests for determinants, inverse, transpose, matrix compose, and matrix-vector multipy

void test_matrix4_equal();
void test_matrix3_equal();
void test_matrix2_equal();
void test_matrix4_compose();
void test_matrix4_vector_multiply();
void test_matrix4_transpose();
void test_matrix4_determinant();
void test_matrix4_invert();

#endif /* _TEST_MATRIX_H_ */
