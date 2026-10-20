#ifndef CIRCLE_H
#define CIRCLE_H

#include "transforme.h"
#include "point.h"

typedef struct circle_t{
    transform_s *transform;
    point_s     *a;
    int         r;
    char        *color_bord;
    char        *color_remplissage;
}circle_s;

#endif