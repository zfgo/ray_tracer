#ifndef _RAY_H_
#define _RAY_H_

#include "include.h"
#include "datatypes/vector.h"

typedef struct ray
{
    Vec origin;
    Vec dir;
} Ray;

Vec ray_position(Ray r, float t);

#endif /* _RAY_H_ */