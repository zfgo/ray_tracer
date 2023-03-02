#include "include.h"
#include <math.h>

bool equal(float a, float b)
{
    return (fabsf(a - b) < EPSILON);
}

float deg_to_rad(float deg)
{
    return deg * M_PI / 180.0;
}
