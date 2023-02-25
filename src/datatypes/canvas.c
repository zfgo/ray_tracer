#include "datatypes/canvas.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

bool alloc_canvas_data(Canvas *can)
{
    int i;

    Color **data = NULL;

    if ((data = (Color **)malloc(sizeof(Color *) * can->height)) == NULL) {
        return false;
    }

    for (i = 0; i < can->height; ++i) {
        if ((data[i] = (Color *)malloc(sizeof(Color) * can->width)) == NULL) {
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

void set_canvas_color(Canvas *can, Color c)
{
    int i, j;

    for (i = 0; i < can->height; ++i) {
        for (j = 0; j < can->width; ++i) {
            can->data[i][j] = c;
        }
    }
}

void canvas_to_pnm(Canvas *can, char *f_name)
{
    int i, j;
    unsigned char col[3];
    FILE *fp;

    if ((fp = fopen(f_name, "wb")) == NULL) {
        fprintf(stderr, "Error: couldn't open file %s\n", f_name);
        exit(1);
    }

    // write the magic #, height, width, and max color value (hard
    // coded to be 255)
    fprintf(fp, "P6\n%d %d\n255\n", can->width, can->height);

    for (i = 0; i < can->height; ++i) {
        for (j = 0; j < can->width; ++j) {
            // convert color floats to unsigned chars
            col[0] = (unsigned char) ceil(can->data[i][j].r * 255);
            col[1] = (unsigned char) ceil(can->data[i][j].g * 255);
            col[2] = (unsigned char) ceil(can->data[i][j].b * 255);

            fwrite(col, 3, 1, fp);
        }
    }

    fclose(fp);
}
