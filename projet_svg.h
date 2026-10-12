#ifndef PROJET_SVG_H
#define PROJET_SVG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct point_t{
    int x;
    int y;
} point_s;

typedef struct line_t{
    char *color;
    point_s *a;
    point_s *b;
} line_s;

int    add_new_forme(void);
char    *color_init(void);

#endif