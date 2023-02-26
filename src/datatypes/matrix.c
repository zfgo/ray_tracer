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


