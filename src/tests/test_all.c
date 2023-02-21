#include "test_vector.h"
#include "test_include.h"

int main(void)
{
    /* vector tests */
    test_if_point();
    test_if_vector();
    test_vector_equal();
    test_vector_add();
    test_vector_subtract();
    test_vector_negate();

    /* include tests */
    test_equal();

    return 0;
}