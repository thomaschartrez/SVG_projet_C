#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "transforme.h"
#include "point.h"

typedef struct elipse_t
{
    transform_s *transform;
    point_s     *a;
    int         r1;
    int         r2;
    char        *color_bord;
    char        *color_remplissage;
}elipse_s;

void    free_ellipse(elipse_s *elipse);
void    print_ellipse(elipse_s *elipse);

#endif