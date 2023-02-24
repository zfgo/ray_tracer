#ifndef _CANVAS_H_
#define _CANVAS_H_

#include "include.h"
#include "datatypes/color.h"
#include <stdbool.h>

typedef struct canvas 
{
    int width;
    int height;
    Color **data;
} Canvas;

/* alloc the color data for the canvas
 */
bool alloc_canvas_data(Canvas *can);

/* free the allocated canvas data 
 */
void free_canvas_data(Canvas *can);

/* write a pixel to the canvas 
 */
void write_pixel(Canvas *can, int i, int j, Color c);

/* set the entire canvas to one solid color 
 */
void set_canvas_color(Canvas *can, Color c);


#endif
