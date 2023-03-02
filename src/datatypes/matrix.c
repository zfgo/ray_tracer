#include "datatypes/matrix.h"
#include "include.h"

bool matrix4_equal(Mat4 m1, Mat4 m2)
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

bool matrix3_equal(Mat3 m1, Mat3 m2)
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

bool matrix2_equal(Mat2 m1, Mat2 m2)
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

Mat4 matrix4_compose(Mat4 m1, Mat4 m2)
{
    Mat4 res;
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

Vec matrix4_vector_multipy(Mat4 m, Vec v)
{
    Vec res;
    int i, j;

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            res.v[i] += v.v[j] * m.A[j][i];
        }
    }

    return res;
}

Mat4 matrix4_transpose(Mat4 m)
{
    Mat4 res;
    int i, j;

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            res.A[i][j] = m.A[j][i];
        }
    }

    return res;
}

float matrix4_determinant(Mat4 m)
{
    float det = 0.0;
    int i;

    for (i = 0; i < 4; ++i) {
        det += m.A[0][i] * matrix4_cofactor(m, 0, i);
    }

    return det;
}

float matrix3_determinant(Mat3 m)
{
    float det = 0.0;
    int i;

    for (i = 0; i < 3; ++i) {
        det += m.A[0][i] * matrix3_cofactor(m, 0, i);
    }

    return det;
}

float matrix2_determinant(Mat2 m)
{
    return m.A[0][0] * m.A[1][1] - m.A[0][1] * m.A[1][0];
}

Mat3 matrix4_submatrix(Mat4 m, int r, int c)
{
    Mat3 res;
    int i, j;
    int out_i = 0,
        out_j = 0;

    for (i = 0; i < 4; ++i) {
        if (i == r)
            continue;
        for (j = 0; j < 4; ++j) {
            if (j == c)
                continue;
            res.A[out_i][out_j] = m.A[i][j];
            ++out_j;
        }
        ++out_i;
    }

    return res;
}

Mat2 matrix3_submatrix(Mat3 m, int r, int c)
{
    Mat2 res;
    int i, j;
    int out_i = 0,
        out_j = 0;

    for (i = 0; i < 3; ++i) {
        if (i == r)
            continue;
        for (j = 0; j < 3; ++j) {
            if (j == c)
                continue;
            res.A[out_i][out_j] = m.A[i][j];
            ++out_j;
        }
        ++out_i;
    }

    return res;
}

float matrix4_minor(Mat4 m, int i, int j)
{
    Mat3 sub;
    float det;

    sub = matrix4_submatrix(m, i, j);
    det = matrix3_determinant(sub);
    
    return det;
}

float matrix3_minor(Mat3 m, int i, int j)
{
    Mat2 sub;
    float det;

    sub = matrix3_submatrix(m, i, j); 
    det = matrix2_determinant(sub);

    return det;
}

float matrix4_cofactor(Mat4 m, int i, int j)
{
    float cofactor;

    cofactor = matrix4_minor(m, i, j);

    return (i + j) % 2 ? -cofactor : cofactor;
}

float matrix3_cofactor(Mat3 m, int i, int j)
{
    float cofactor;

    cofactor = matrix3_minor(m, i, j);

    return (i + j) % 2 ? -cofactor : cofactor;
}

Mat4 matrix4_invert(Mat4 m)
{
    if (matrix4_determinant(m) == 0) {
        return m;
    }

    Mat4 res;
    int i, j;
    float c;
    float det = matrix4_determinant(m);

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            c = matrix4_cofactor(m, i, j);
            res.A[j][i] = c / det;
        }
    }

    return res;
}
