#include "datatypes/ray.h"

Vec ray_position(Ray r, float t)
{
    Vec pos = vector_add(r.origin, vector_scalar_multiply(r.dir, t));

    return pos;
}
