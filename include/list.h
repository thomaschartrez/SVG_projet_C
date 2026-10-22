#ifndef LIST_H
#define LIST_H

#include "rectangle.h"
#include "circle.h"
#include "ellipse.h"
#include "line.h"
#include "polyline.h"

typedef enum {LINE, CIRCLE, RECTANGLE, SQUARE, ELLIPSE, POLYLINE, POLYGONE} Forme; 

typedef union {
    line_s      *line;
    circle_s    *circle;
    elipse_s    *elipse;
    rectangle_s *rectangle;
    polyline_s  *polyline;
} Figure;


typedef struct node_t{
    Forme           type;
    Figure          *figure;
    struct node_t   *next;
}node_s;

typedef struct list_t{
    node_s          *node;
    unsigned int    length;
}list_s;

#endif