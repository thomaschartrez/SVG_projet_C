#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "transforme.h"
#include "point.h"

typedef struct rectangle_t
{
    transform_s *transform;
    point_s *a;
    char    *color_bord;
    char    *color_remplissage;
    int     width;
    int     height;
}rectangle_s;

void    free_rectangle(rectangle_s *rectangle);

#endif