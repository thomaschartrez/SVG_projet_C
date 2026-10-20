#ifndef PROJET_SVG_H
#define PROJET_SVG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET   "\x1b[0m"
#define ROUGE   "\x1b[31m"
#define GREEN    "\x1b[32m"
#define JAUNE   "\x1b[33m"
#define GRAS    "\x1b[1m"

typedef struct point_t{
    int x;
    int y;
} point_s;

typedef struct transform_t{
    int rotate;
    int x;
    int y;
} transform_s;

typedef struct rectangle_t
{
    transform_s *transform;
    point_s *a;
    char    *color_bord;
    char    *color_remplissage;
    int     width;
    int     height;
}rectangle_s;


typedef struct elipse_t
{
    transform_s *transform;
    point_s     *a;
    int         r1;
    int         r2;
    char        *color_bord;
    char        *color_remplissage;
}elipse_s;


typedef struct line_t{
    transform_s *transform;
    char        *color;
    point_s     *a;
    point_s     *b;
} line_s;

typedef struct circle_t{
    transform_s *transform;
    point_s     *a;
    int         r;
    char        *color_bord;
    char        *color_remplissage;
}circle_s;

typedef enum {LINE, CIRCLE, RECTANGLE, SQUARE, ELLIPSE} Forme; 

typedef union {
    line_s      *line;
    circle_s    *circle;
    elipse_s    *elipse;
    rectangle_s *rectangle;
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

int    add_new_forme(list_s *list);
char    *color_init(void);
void    free_list(list_s *list);
void    free_node(node_s *node);
list_s  *init_list(void);
list_s *add_node(list_s *list, node_s *node);
list_s *supp_node(list_s *list, int index);
void    free_node(node_s *node);
void    free_list(list_s *list);
node_s *init_node_circle(Forme type, circle_s *circle);
int add_to_file(list_s *list);
node_s *init_node_line(Forme type ,line_s *line);
int modify_forme(list_s *list);
void    add_new_point(point_s *point);
void clear_stdin(void);
void    free_circle(circle_s *circle);
list_s  *get_save(list_s *list);
void    print_circle(circle_s *circle);
void    print_line(line_s *line);
void    free_line(line_s *line);
int creat_save(list_s *list);
node_s  *init_node_ellipse(Forme type , elipse_s *elipse);
node_s  *init_node_rectangle(Forme type , rectangle_s *rectangle);
node_s  *init_node_square(Forme type ,rectangle_s *square);
void    free_ellipse(elipse_s *elipse);
void    free_rectangle(rectangle_s *rectangle);


#endif