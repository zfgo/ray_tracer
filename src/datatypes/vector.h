/* Implementation of the vector and point structs (both of which are 
 * more or less the same) as well as forward references for vector 
 * operations.
 */
#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <math.h>
#include <stdbool.h>

/* Structure to hold a vector or a point. If the vector is a point, 
 * then w = 0.0. If the vector is a vector, then w = 1.0.
 *
 * We define vectors as an array of 4 floats, where the indices 0, 1,
 * 2, 3, correspond to x, y, z, w, respectively, or to r, g, b, a, 
 * respectively if we are using the vector as a color.
 */
typedef struct vector
{
    /* anonymous union containing anonymous structs for vectors,
     * points, and colors
     */
    union {
        struct {
            float v[4];
        };
        struct {
            float p[4];
        };
        struct {
            float c[4];
        };
    };
} Vec;


/* Return True if a vector is a point, false otherwise.
 */
bool if_point(Vec v);

/* Return True if a vector is a vector, false otherwise.
 */
bool if_vector(Vec v);

/* check if two vectors are equal
 */
bool vector_equal(Vec v1, Vec v2);

/* add two vectors, and return the result
 */
Vec vector_add(Vec v1, Vec v2);

/* subtract two vectors, and return the result
 */
Vec vector_subtract(Vec v1, Vec v2);

/* negate a vector, and return the result
 */
Vec vector_negate(Vec v);

/* multiply a vector by a float, and return the result
 */
Vec vector_scalar_multiply(Vec v, float f);

/* divide a vector by a float, and return the result
 */
Vec vector_scalar_divide(Vec v, float f);

/* find the norm (aka length or magnitude) of a vector
 */
float vector_norm(Vec v);

/* normalize a vector such that it has magnitude one, and return the
 * result
  */
Vec vector_normalize(Vec v);

/* calculate the dot product of a vector, and return the result
 */
float vector_dot(Vec v1, Vec v2);

/* calculate the cross product of a vector, and return the result
 */
Vec vector_cross(Vec v1, Vec v2);

#endif /* _VECTOR_H_ */
