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
 */
typedef struct vector
{
    float x, y, z, w;
} Vector;


/* Return True if a vector is a point, false otherwise.
 */
bool if_point(Vector v);

/* Return True if a vector is a vector, false otherwise.
 */
bool if_vector(Vector v);

/* add two vectors, and return the result
 */
Vector vector_add(Vector v1, Vector v2);

/* subtract two vectors, and return the result
 */
Vector vector_subtract(Vector v1, Vector v2);

/* negate a vector, and return the result
 */
Vector vector_negate(Vector v);

/* multiply a vector by a float, and return the result
 */
Vector vector_scalar_multiply(Vector v, float f);

/* divide a vector by a float, and return the result
 */
Vector vector_scalar_divide(Vector v, float f);

float vector_norm(Vector v);

/* normalize a vector such that it has magnitude one, and return the
 * result
  */
Vector vector_normalize(Vector v);

/* calculate the dot product of a vector, and return the result
 */
float vector_dot(Vector v1, Vector v2);

/* calculate the cross product of a vector, and return the result
 */
Vector vector_cross(Vector v1, Vector v2);

#endif /* _VECTOR_H_ */