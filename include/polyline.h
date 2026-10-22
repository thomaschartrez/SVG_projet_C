#ifndef POLYLINE_H
#define POLYLINE_H

#include "point.h"
#include "transforme.h"

typedef struct poly_point_t
{
    point_s *point;
    struct poly_point_t *next;
}poly_point_s;


typedef struct polyline_t
{
    poly_point_s *node;
    transform_s *transform;
    char    *color;
    char    *color_fill;
    int nb_point;
}polyline_s;

polyline_s *init_polyline(void);

#endif