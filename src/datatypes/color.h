#ifndef _COLOR_H_
#define _COLOR_H_

typedef struct color 
{
    float r, g, b;
} Color;

/* add two colors together, and return the result
 */
Color color_add(Color c1, Color c2);

/* subtract two colors, and return the result
 */
Color color_subtract(Color c1, Color c2);

/* multiply two colors together, and return the result
 */
Color color_multiply(Color c1, Color c2);

/* multiply a color by a sontant,  and return the result
 */
Color color_scalar_multiply(Color c, float f);




#endif /* _COLOR_H_ */
