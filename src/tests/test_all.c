#include "test_vector.h"
#include "test_include.h"

int main(void)
{
    /* vector tests */
    test_if_point();
    test_if_vector();

    /* include tests */
    test_equal();

    return 0;
}