#ifndef LINE_H
#define LINE_H

#include "transforme.h"
#include "point.h"

typedef struct line_t{
    transform_s *transform;
    char        *color;
    point_s     *a;
    point_s     *b;
} line_s;



#endif