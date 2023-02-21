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