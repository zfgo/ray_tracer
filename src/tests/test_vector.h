#ifndef _TEST_VECTOR_H_
#define _TEST_VECTOR_H_

#include <stdio.h>
#include "include.h"
#include "datatypes/vector.h"

/* test that the if_point function works correctly
 */
void test_if_point();

/* test that the if_vector function works correctly
 */
void test_if_vector();

void test_vector_equal();

void test_vector_add();

void test_vector_subtract();

void test_vector_negate();

void test_vector_scalar_multiply();

void test_vector_scalar_divide();

void test_vector_norm();

void test_vector_normalize();

void test_vector_dot();

void test_vector_cross();

#endif /* _TEST_VECTOR_H_ */
