#include "vector.h"

bool if_point(Vector v)
{
    return v.w == 1.0;
}

bool if_vector(Vector v)
{
    return v.w == 0.0;
}
