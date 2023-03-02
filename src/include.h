#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include <stdbool.h>

#define UNUSED __attribute__((unused))

#define TEST_PRINT_FORMAT "%-40s %-5s\n"
#define PASS "ok"
#define FAIL "FAIL"

#define EPSILON  0.00001

/* compare two floating point values. They are ``equal'' if their
 * difference is < 0.00001 (aka EPSILON)
 */
bool equal(float a, float b);

/* convert degrees to radians
 */
float deg_to_rad(float deg);

#endif /* _INCLUDE_H_ */
