#include "vector.h"
#include "include.h"

bool if_point(Vector v)
{
    return equal(v.w, 1.0);
}

bool if_vector(Vector v)
{
    return equal(v.w, 0.0);
}

bool vector_equal(Vector v1, Vector v2)
{
    return (
        equal(v1.x, v2.x) &&
        equal(v1.y, v2.y) &&
        equal(v1.z, v2.z) &&
        equal(v1.w, v2.w)
    );
}

Vector vector_add(Vector v1, Vector v2)
{
    Vector v_out;

    v_out.x = v1.x + v2.x;
    v_out.y = v1.y + v2.y;
    v_out.z = v1.z + v2.z;
    v_out.w = v1.w + v2.w;

    return v_out;
}

Vector vector_subtract(Vector v1, Vector v2)
{
    Vector v_out;

    v_out.x = v1.x - v2.x;
    v_out.y = v1.y - v2.y;
    v_out.z = v1.z - v2.z;
    v_out.w = v1.w - v2.w;

    return v_out;
}

Vector vector_negate(Vector v)
{
    Vector zero = {
        .x = 0,
        .y = 0,
        .z = 0,
        .w = 0
    };

    return vector_subtract(zero, v);
}

Vector vector_scalar_multiply(Vector v, float f)
{
    Vector v_out = {
        .x = f * v.x,
        .y = f * v.y,
        .z = f * v.z,
        .w = f * v.w
    };

    return v_out;
}

Vector vector_scalar_divide(Vector v, float f)
{
    Vector v_out = {
        .x = v.x / f,
        .y = v.y / f,
        .z = v.z / f,
        .w = v.w / f
    };

    return v_out;
}

float vector_norm(Vector v)
{
    return sqrt(vector_dot(v, v));
}

Vector vector_normalize(Vector v)
{
    float norm = vector_norm(v);

    if (norm == 0.0) {
        // we don't want to have divide by 0 errors
        return v;
    }

    Vector v_out = vector_scalar_divide(v, norm);

    return v_out;
}

float vector_dot(Vector v1, Vector v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

Vector vector_cross(Vector v1, Vector v2)
{
    Vector v_out = {
        .x = v1.y * v2.z - v1.z * v2.y,
        .y = v1.z * v2.x - v1.x * v2.z,
        .z = v1.x * v2.y - v1.y * v2.x,
        .w = 0.0
    };

    return v_out;
}