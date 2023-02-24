#include "tests/test_color.h"
#include "include.h"

void test_color_equal()
{
    Color c1 = {
        .r = 0.5,
        .g = 0.2,
        .b = 0.1
    };

    Color c2 = {
        .r = 0.5,
        .g = 0.2,
        .b = 0.1
    };

    Color c3 = {
        .r = 1.0,
        .g = 0.4,
        .b = 0.2
    };

    printf(TEST_PRINT_FORMAT, "test_color_equal()", color_equal(c1, c2) ? PASS : FAIL);
    printf(TEST_PRINT_FORMAT, "test_color_equal()", !color_equal(c1, c3) ? PASS : FAIL);
}

void test_color_add()
{
    Color c1 = {
        .r = 0.5,
        .g = 0.2,
        .b = 0.1
    };

    Color c2 = {
        .r = 0.5,
        .g = 0.2,
        .b = 0.1
    };

    Color c3 = {
        .r = 1.0,
        .g = 0.4,
        .b = 0.2
    };

    Color c_out = color_add(c1, c2);

    printf(TEST_PRINT_FORMAT, "test_color_add()", color_equal(c_out, c3) ? PASS : FAIL);
}

void test_color_subtract()
{
    Color c1 = {
        .r = 0.5,
        .g = 0.2,
        .b = 0.1
    };

    Color c2 = {
        .r = 0.5,
        .g = 0.2,
        .b = 0.1
    };

    Color c3 = {
        .r = 0.0,
        .g = 0.0,
        .b = 0.0
    };

    Color c_out = color_subtract(c1, c2);

    printf(TEST_PRINT_FORMAT, "test_color_subtract()", color_equal(c_out, c3) ? PASS : FAIL);
}

void test_color_multiply()
{
    Color c1 = {
        .r = 0.5,
        .g = 0.2,
        .b = 0.1
    };

    Color c2 = {
        .r = 0.5,
        .g = 0.2,
        .b = 0.1
    };

    Color c3 = {
        .r = 0.25,
        .g = 0.04,
        .b = 0.01
    };

    Color c_out = color_multiply(c1, c2);

    printf(TEST_PRINT_FORMAT, "test_color_multiply()", color_equal(c_out, c3) ? PASS : FAIL);
}

void test_color_scalar_multiply()
{
    Color c1 = {
        .r = 0.5,
        .g = 0.2,
        .b = 0.1
    };

    float f = 0.1;

    Color c3 = {
        .r = 0.05,
        .g = 0.02,
        .b = 0.01
    };

    Color c_out = color_scalar_multiply(c1, f);

    printf(TEST_PRINT_FORMAT, "test_color_multiply()", color_equal(c_out, c3) ? PASS : FAIL);

}
