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

/* print a 4x4 matrix to stdout
 */
void matrix4_print(Mat4 m);

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
Vec matrix4_vector_multiply(Mat4 m1, Vec v);

/* calculate the transpose of a given matrix, and return the result
 */
Mat4 matrix4_transpose(Mat4 m);

/* calculate the inverse of a given matrix, and return the result
 */
Mat4 matrix4_invert(Mat4 m);

/* calculate the determinant of a 4x4 matrix, and return the result
 */
float matrix4_determinant(Mat4 m);

/* calculate the determinant of a 3x3 matrix, and return the result
 */
float matrix3_determinant(Mat3 m);

/* calculate the determinant of a 2x2 matrix, and return the result
 */
float matrix2_determinant(Mat2 m);

/* find the 3x3 submatrix of a 4x4 matrix when row i and column j are
 * removed
 */
Mat3 matrix4_submatrix(Mat4 m, int r, int c);

/* find the 2x2 submatrix of a 3x3 matrix when row i and column j are
 * removed
 */
Mat2 matrix3_submatrix(Mat3 m, int r, int c);

/* calculate the determinant of the 3x3 submatrix that is found by 
 * removing row i and column j
 */
float matrix4_minor(Mat4 m, int i, int j);

/* calculate the determinant of the 2x2 submatrix that is found by 
 * removing row i and column j
 */
float matrix3_minor(Mat3 m, int i, int j);

/* calculate the determinant of the 3x3 submatrix that is found by 
 * removing row i and column j and change the sign of the result if
 * (i + j) is odd.
 */
float matrix4_cofactor(Mat4 m, int i, int j);

/* calculate the determinant of the 2x2 submatrix that is found by 
 * removing row i and column j and change the sign of the result if
 * (i + j) is odd.
 */
float matrix3_cofactor(Mat3 m, int i, int j);


#endif /* _MATRIX_H_ */
