#ifndef _RAY_H_
#define _RAY_H_

#include "include.h"
#include "datatypes/vector.h"
#include "datatypes/sphere.h"

typedef struct ray
{
    Vec origin;
    Vec dir;
} Ray;

/* calculate the position of a ray at some given time, t
 */
Vec ray_position(Ray r, float t);

float *

#endif /* _RAY_H_ */
