#include "tests/test_canvas.h"

void test_canvas_simple()
{
    Canvas c;
    c.width = 3;
    c.height = 3;
    alloc_canvas_data(&c);

    Color red = {
        .r = 1.0,
        .g = 0.0,
        .b = 0.0
    };

    Color green = {
        .r = 0.0,
        .g = 1.0,
        .b = 0.0
    };

    Color blue = {
        .r = 0.0,
        .g = 0.0,
        .b = 1.0
    };

    Color yellow = {
        .r = 1.0,
        .g = 1.0,
        .b = 0.0
    };

    Color magenta = {
        .r = 1.0,
        .g = 0.0,
        .b = 1.0
    };

    Color cyan = {
        .r = 0.0,
        .g = 1.0,
        .b = 1.0
    };

    Color white = {
        .r = 1.0,
        .g = 1.0,
        .b = 1.0
    };

    Color gray = {
        .r = 0.5,
        .g = 0.5,
        .b = 0.5
    };
    Color black = {
        .r = 0.0,
        .g = 0.0,
        .b = 0.0
    };
    write_pixel(&c, 0, 0, red);
    write_pixel(&c, 0, 1, blue);
    write_pixel(&c, 0, 2, green);
    write_pixel(&c, 1, 0, yellow);
    write_pixel(&c, 1, 1, magenta);
    write_pixel(&c, 1, 2, cyan);
    write_pixel(&c, 2, 0, white);
    write_pixel(&c, 2, 1, gray);
    write_pixel(&c, 2, 2, black);

    canvas_to_pnm(&c, "test_images/test_canvas_simple.pnm");

    free_canvas_data(&c);
}

void test_canvas_complex()
{
    return;
}
