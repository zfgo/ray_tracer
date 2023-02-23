#include "include.h"

bool equal(float a, float b)
{
    return (fabsf(a - b) < EPSILON);
}
