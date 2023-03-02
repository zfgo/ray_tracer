#include "tests/test_matrix.h"

#include <stdio.h>
#include "include.h"

void test_matrix4_equal()
{
    Mat4 a = {
        .A = {
            {1, 2, 3, 4}, 
            {5, 6, 7, 8}, 
            {9, 10, 11, 12}, 
            {13, 14, 15, 16}
        }
    };
    Mat4 b = {
        .A = {
            {1, 2, 3, 4}, 
            {5, 6, 7, 8}, 
            {9, 10, 11, 12}, 
            {13, 14, 15, 16}
        }
    };
    Mat4 c = {
        .A = {
            {1, 2, 3, 4}, 
            {5, 6, 7, 8}, 
            {9, 10, 11, 12}, 
            {13, 14, 16, 16}
        }
    };

    printf(TEST_PRINT_FORMAT, "test_matrix4_equal()", matrix4_equal(a, b) ? PASS : FAIL);
    printf(TEST_PRINT_FORMAT, "test_matrix4_equal()", ! matrix4_equal(a, c) ? PASS : FAIL);
}

void test_matrix3_equal()
{
    Mat3 a = {
        .A = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        }
    };
    Mat3 b = {
        .A = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        }
    };
    Mat3 c = {
        .A = {
            {1, 2, 3},
            {4, 5, 6},
            {8, 8, 9}
        }
    };

    printf(TEST_PRINT_FORMAT, "test_matrix3_equal()", matrix3_equal(a, b) ? PASS : FAIL);
    printf(TEST_PRINT_FORMAT, "test_matrix3_equal()", ! matrix3_equal(a, c) ? PASS : FAIL);
}

void test_matrix2_equal()
{
    Mat2 a = {
        .A = {
            {1, 2},
            {3, 4}
        }
    };
    Mat2 b = {
        .A = {
            {1, 2},
            {3, 4}
        }
    };
    Mat2 c = {
        .A = {
            {1, 2},
            {4, 4}
        }
    };

    printf(TEST_PRINT_FORMAT, "test_matrix2_equal()", matrix2_equal(a, b) ? PASS : FAIL);
    printf(TEST_PRINT_FORMAT, "test_matrix2_equal()", ! matrix2_equal(a, c) ? PASS : FAIL);
}

void test_matrix4_compose()
{
    Mat4 a = {
        .A = {
            {1, 2, 3, 4}, 
            {5, 6, 7, 8}, 
            {9, 10, 11, 12}, 
            {13, 14, 15, 16}
        }
    };
    Mat4 b = {
        .A = {
            {16, 15, 14, 13}, 
            {12, 11, 10, 9}, 
            {8, 7, 6, 5}, 
            {4, 3, 2, 1}
        }
    };
    Mat4 c = {
        .A = {
            {80, 70, 60, 50}, 
            {240, 214, 188, 162}, 
            {400, 358, 316, 274}, 
            {560, 502, 444, 386}
        }
    };

    Mat4 res = matrix4_compose(a, b);

    printf(TEST_PRINT_FORMAT, "test_matrix4_compose()", matrix4_equal(c, res) ? PASS : FAIL);
}

void test_matrix4_vector_multiply()
{
    Mat4 a = {
        .A = {
            {1, 2, 3, 4}, 
            {2, 4, 4, 2}, 
            {8, 6, 4, 1}, 
            {0, 0, 0, 1}
        }
    };
    Vec v1 = {
        .v = {1, 2, 3, 1}
    };

    Vec v2 = {
        .v = {18, 24, 33, 1}
    };

    Vec res = matrix4_vector_multiply(a, v1);
    
    printf(TEST_PRINT_FORMAT, "test_matrix4_vector_multiply()", vector_equal(v2, res) ? PASS : FAIL);
}

void test_matrix4_transpose()
{
    Mat4 a = {
        .A = {
            {1, 2, 3, 4}, 
            {5, 6, 7, 8}, 
            {9, 10, 11, 12}, 
            {13, 14, 15, 16}
        }
    };
    Mat4 b = {
        .A = {
            {1, 5, 9, 13}, 
            {2, 6, 10, 14}, 
            {3, 7, 11, 15}, 
            {4, 8, 12, 16}
        }
    };

    Mat4 res = matrix4_transpose(a);

}

void test_matrix4_determinant()
{
    Mat4 a = {
        .A = {
            {1, 2, 3, 4},
            {0, 1, 2, 3},
            {0, 0, 1, 2},
            {0, 0, 0, 1}
        }
    };
    float det = 1.0;
    float res; // = matrix4_determinant(a);

    printf("%f\n", res);

    printf(TEST_PRINT_FORMAT, "test_matrix4_determinant()", equal(det, res) ? PASS : FAIL);
}

void test_matrix3_determinant()
{
    Mat3 a = {
        .A = {
            {1, 2, 3},
            {0, 1, 2},
            {0, 0, 2}
        }
    };
    float det = 2.0;
    float res = matrix3_determinant(a);

    printf("%f\n", res);

    printf(TEST_PRINT_FORMAT, "test_matrix3_determinant()", equal(det, res) ? PASS : FAIL);
}

void test_matrix2_determinant()
{
    Mat2 a = {
        .A = {
            {1, 2},
            {0, 1}
        }
    };
    Mat2 b = {
        .A = {
            {1, 2},
            {0, 2}
        }
    };
    float det_a = 1.0;
    float det_b = 2.0;
    float res_a = matrix2_determinant(a);
    float res_b = matrix2_determinant(b);

    printf(TEST_PRINT_FORMAT, "test_matrix2_determinant()", equal(det_a, res_a) ? PASS : FAIL);
    printf(TEST_PRINT_FORMAT, "test_matrix2_determinant()", equal(det_b, res_b) ? PASS : FAIL);
}

void test_matrix4_invert()
{
    Mat4 a = {
        .A = {
            {1, 2, 3, 4},
            {0, 1, 2, 3},
            {0, 0, 1, 2},
            {0, 0, 0, 1}
        }
    };
    Mat4 b = {
        .A = {
            {1, -2, 1, 0}, 
            {0, 1, -2, 1}, 
            {0, 0, 1, -2}, 
            {0, 0, 0, 1}
        }
    };
}
