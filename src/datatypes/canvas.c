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
        if ((data[i] = (Color **)malloc(sizeof(Color *) * can->width)) == NULL) {
            return false;
        }
    }

    can->data = data;

    return true;
}


