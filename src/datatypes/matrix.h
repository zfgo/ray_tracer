#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdbool.h>
#include "datatypes/vector.h"

typedef struct matrix4
{
    float A[4][4];
} Mat4;

typedef struct matrix3
{
    float A[3][3];
} Mat3;

typedef struct matrix2
{
    float A[2][2];
} Mat2;

/* given two 4x4 matrices, determine if they are equal or not
 */
bool matrix4_equal(Mat4 m1, Mat4 m2);

/* given two 3x3 matrices, determine if they are equal or not
 */
bool matrix3_equal(Mat3 m1, Mat3 m2);

/* given two 2x2 matrices, determine if they are equal or not
 */
bool matrix2_equal(Mat2 m1, Mat2 m2);

/* given two 4x4 matrices, multiply them together and return the result
 */
Mat4 matrix4_compose(Mat4 m1, Mat4 m2);

/* given a 4x4 matric and a vector, multiply them together and return
 * the result
 */
Vec matrix4_vector_multipy(Mat4 m1, Vec v);

Mat4 matrix4_transpose(Mat4 m);

Mat4 matrix4_invert(Mat4 m);

float matrix4_determinant(Mat4 m);

float matrix3_determinant(Mat3 m);

float matrix2_determinant(Mat2 m);

Mat3 matrix4_submatrix(Mat4 m, int i, int j);

Mat2 matrix3_submatrix(Mat3 m, int i, int j);

float matrix4_minor(Mat4 m, int i, int j);

float matrix3_minor(Mat3 m, int i, int j);

float matrix4_cofactor(Mat4 m, int i, int j);

float matrix3_cofactor(Mat3 m, int i, int j);


#endif /* _MATRIX_H_ */
