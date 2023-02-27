#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdbool.h>
#include "datatypes/vector.h"

typedef struct matrix4
{
    float A[4][4];
} Matrix4;

typedef struct matrix3
{
    float A[3][3];
} Matrix3;

typedef struct matrix2
{
    float A[2][2];
} Matrix2;

/* given two 4x4 matrices, determine if they are equal or not
 */
bool matrix4_equal(Matrix4 m1, Matrix4 m2);

/* given two 3x3 matrices, determine if they are equal or not
 */
bool matrix3_equal(Matrix3 m1, Matrix3 m2);

/* given two 2x2 matrices, determine if they are equal or not
 */
bool matrix2_equal(Matrix2 m1, Matrix2 m2);

/* given two 4x4 matrices, multiply them together and return the result
 */
Matrix4 matrix4_compose(Matrix4 m1, Matrix4 m2);

/* given a 4x4 matric and a vector, multiply them together and return
 * the result
 */
Vector matrix4_vector_multipy(Matrix4 m1, Vector v);

Matrix4 matrix4_transpose(Matrix4 m);

Matrix4 matrix4_invert(Matrix4 m);

float matrix4_determinant(Matrix4 m);

float matrix3_determinant(Matrix3 m);

float matrix2_determinant(Matrix2 m);

Matrix3 matrix4_submatrix(Matrix4 m, int i, int j);

Matrix2 matrix3_submatrix(Matrix3 m, int i, int j);

float matrix4_minor(Matrix4 m, int i, int j);

float matrix3_minor(Matrix3 m, int i, int j);

float matrix4_cofactor(Matrix4 m, int i, int j);

float matrix3_cofactor(Matrix3 m, int i, int j);


#endif /* _MATRIX_H_ */
