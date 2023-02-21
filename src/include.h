#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include <stdbool.h>
#include <math.h>

#define EPSILON  0.00001

bool equal(float a, float b)
{
    return (fabsf(a - b) < EPSILON);
}

#endif /* _INCLUDE_H_ */