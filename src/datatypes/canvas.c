#include "datatypes/canvas.h"
#include <stdlib.h>

bool alloc_canvas_data(Canvas *can)
{
    int i;

    Color **data = NULL;

    if ((data = (Color **)malloc(sizeof(Color *) * can->height)) == NULL) {
        return false;
    }

    for (i = 0; i < can->height; ++i) {
        if ((data[i] = (Color **)malloc(sizeof(Color) * can->width)) == NULL) {
            return false;
        }
    }

    can->data = data;

    return true;
}

void free_canvas_data(Canvas *can) 
{
    int i;

    for (i = 0; i < can->height; ++i) {
        free(can->data[i]);
    }
    
    free(can->data);
}

void write_pixel(Canvas *can, int i, int j, Color c)
{
    if (i < 0 || i >= can->height || j < 0 || j >= can->width) {
        return;
    }

    can->data[i][j] = c;
}
