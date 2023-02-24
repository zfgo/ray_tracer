#include "datatypes/color.h"

bool color_equal(Color c1, Color c2)
{
    return equal(c1.r, c2.r) && equal(c1.g, c2.g) && equal(c1.b, c2.b);
}

Color color_add(Color c1, Color c2)
{
    Color c_out = {
        .r = c1.r + c2.r,
        .g = c1.g + c2.g,
        .b = c1.b + c2.b
    };

    return c_out;
}

Color color_subtract(Color c1, Color c2)
{
    Color c_out = {
        .r = c1.r - c2.r,
        .g = c1.g - c2.g,
        .b = c1.b - c2.b
    };

    return c_out;
}

Color color_multiply(Color c1, Color c2)
{
    Color c_out = {
        .r = c1.r * c2.r,
        .g = c1.g * c2.g,
        .b = c1.b * c2.b
    };

    return c_out;
}

Color color_scalar_multiply(Color c, float f)
{
    Color c_out = {
        .r = c.r * f,
        .g = c.g * f,
        .b = c.b * f
    };

    return c_out;
}
