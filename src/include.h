#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include <stdbool.h>
#include <math.h>

#define UNUSED __attribute__((unused))

#define TEST_PRINT_FORMAT "%-40s %-5s\n"
#define PASS "ok"
#define FAIL "FAIL"

#define EPSILON  0.00001

bool equal(float a, float b);

#endif /* _INCLUDE_H_ */
