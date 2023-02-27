#include "datatypes/matrix.h"
#include "include.h"

bool matrix4_equal(Matrix4 m1, Matrix4 m2)
{
    int i, j;

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            if (m1.A[i][j] != m2.A[i][j]) {
                return false;
            }
        }
    }
    
    return true;
}

bool matrix3_equal(Matrix3 m1, Matrix3 m2)
{
    int i, j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            if (m1.A[i][j] != m2.A[i][j]) {
                return false;
            }
        }
    }
    
    return true;
}

bool matrix2_equal(Matrix2 m1, Matrix2 m2)
{
    int i, j;

    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            if (m1.A[i][j] != m2.A[i][j]) {
                return false;
            }
        }
    }
    
    return true;
}

Matrix4 matrix4_compose(Matrix4 m1, Matrix4 m2)
{
    Matrix4 res;
    int i, j, k;

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            for (k = 0; k < 4; ++k) {
                res.A[i][j] += m1.A[i][k] * m2.A[k][j];
            }
        }
    }

    return res;
}

Vector matrix4_vector_multipy(Matrix4 m, Vector v)
{
    Vector res;
    int i;

    res.x = v.x * m.A[0][0]
          + v.y * m.A[1][0]
          + v.z * m.A[2][0]
          + v.w * m.A[3][0];

    res.y = v.x * m.A[0][1]
          + v.y * m.A[1][1]
          + v.z * m.A[2][1]
          + v.w * m.A[3][1];

    res.z = v.x * m.A[0][2]
          + v.y * m.A[1][2]
          + v.z * m.A[2][2]
          + v.w * m.A[3][2];

    res.w = v.x * m.A[0][3]
          + v.y * m.A[1][3]
          + v.z * m.A[2][3]
          + v.w * m.A[3][3];

    return res;
}

Matrix4 matrix4_transpose(Matrix4 m)
{
    Matrix4 res;
    int i, j;

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            res.A[i][j] = m.A[j][i];
        }
    }

    return res;
}

float matrix4_determinant(Matrix4 m)
{
    return 0.0;
}

float matrix3_determinant(Matrix3 m)
{
    return 0.0;
}

float matrix2_determinant(Matrix2 m)
{
    return m.A[0][0] * m.A[1][1] - m.A[0][1] * m.A[1][0];
}

Matrix3 matrix4_submatrix(Matrix4 m, int r, int c)
{
    Matrix3 res;
    int i, j;
    int out_i = 0,
        out_j = 0;

    for (i = 0; i < 4; ++i) {
        if (i == r) {

            continue;
        }
        for (j = 0; j < 4; ++j) {
            if (j == c) {
                continue;
            }
            res.A[out_i][out_j] = m.A[i][j];
            ++out_j;
        }
        ++out_i;
    }

}
