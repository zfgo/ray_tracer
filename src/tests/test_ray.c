#include "tests/test_ray.h"

#include <stdio.h>
#include "include.h"

void test_ray_position()
{
    Ray r = {
        .origin.p = {2.0, 3.0, 4.0, 1.0},
        .dir.v = {1.0, 0.0, 0.0, 0.0}
    };
    float t = 1.0;

    Vec exp = {
        .p = {3.0, 3.0, 4.0, 1.0}
    };

    Vec out = ray_position(r, t);

    printf(TEST_PRINT_FORMAT, "test_ray_position()", vector_equal(exp, out) ? PASS : FAIL);
}
