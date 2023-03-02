#include "include.h"
#include "datatypes/vector.h"

#include <stdio.h>

bool if_point(Vec v)
{
    return equal(v.p[3], 1.0);
}

bool if_vector(Vec v)
{
    return equal(v.v[3], 0.0);
}

void vector_print(Vec v)
{
    printf("{%f, %f, %f, %f}\n", v.v[0], v.v[1], v.v[2], v.v[3]);
}

bool vector_equal(Vec v1, Vec v2)
{
    return (
        equal(v1.v[0], v2.v[0]) &&
        equal(v1.v[1], v2.v[1]) &&
        equal(v1.v[2], v2.v[2]) &&
        equal(v1.v[3], v2.v[3])
    );
}

Vec vector_add(Vec v1, Vec v2)
{
    Vec v_out;

    v_out.v[0] = v1.v[0] + v2.v[0];
    v_out.v[1] = v1.v[1] + v2.v[1];
    v_out.v[2] = v1.v[2] + v2.v[2];
    v_out.v[3] = v1.v[3] + v2.v[3];

    return v_out;
}

Vec vector_subtract(Vec v1, Vec v2)
{
    Vec v_out;

    v_out.v[0] = v1.v[0] - v2.v[0];
    v_out.v[1] = v1.v[1] - v2.v[1];
    v_out.v[2] = v1.v[2] - v2.v[2];
    v_out.v[3] = v1.v[3] - v2.v[3];

    return v_out;
}

Vec vector_negate(Vec v)
{
    Vec zero = {
        .v[0] = 0.0,
        .v[1] = 0.0,
        .v[2] = 0.0,
        .v[3] = 0.0
    };

    return vector_subtract(zero, v);
}

Vec vector_scalar_multiply(Vec v, float f)
{
    Vec v_out = {
        .v[0] = f * v.v[0],
        .v[1] = f * v.v[1],
        .v[2] = f * v.v[2],
        .v[3] = f * v.v[3]
    };

    return v_out;
}

Vec vector_scalar_divide(Vec v, float f)
{
    Vec v_out = {
        .v[0] = v.v[0] / f,
        .v[1] = v.v[1] / f,
        .v[2] = v.v[2] / f,
        .v[3] = v.v[3] / f
    };

    return v_out;
}

float vector_norm(Vec v)
{
    return sqrt(vector_dot(v, v));
}

Vec vector_normalize(Vec v)
{
    float norm = vector_norm(v);

    if (norm == 0.0) {
        // we don't want to have divide by 0 errors
        return v;
    }

    Vec v_out = vector_scalar_divide(v, norm);

    return v_out;
}

float vector_dot(Vec v1, Vec v2)
{
    return v1.v[0] * v2.v[0] 
         + v1.v[1] * v2.v[1] 
         + v1.v[2] * v2.v[2] 
         + v1.v[3] * v2.v[3];
}

Vec vector_cross(Vec v1, Vec v2)
{
    Vec v_out = {
        .v[0] = v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],
        .v[1] = v1.v[2] * v2.v[0] - v1.v[0] * v2.v[2],
        .v[2] = v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0],
        .v[3] = 0.0
    };

    return v_out;
}
