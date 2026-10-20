#ifndef PROJET_SVG_H
#define PROJET_SVG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "point.h"
#include "transforme.h"
#include "rectangle.h"
#include "ellipse.h"
#include "circle.h"
#include "line.h"
#include "list.h"

#define RESET    "\x1b[0m"
#define ROUGE    "\x1b[31m"
#define GREEN    "\x1b[32m"
#define JAUNE    "\x1b[33m"
#define GRAS     "\x1b[1m"

void    add_line(list_s *list);
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
void clear_stdin(void);
void    free_circle(circle_s *circle);
list_s  *get_save(list_s *list);
void    print_circle(circle_s *circle);
void    print_line(line_s *line);
void    free_line(line_s *line);
int creat_save(list_s *list);
node_s  *init_node_square(Forme type ,rectangle_s *square);
void    print_square(rectangle_s *square);
node_s  *init_node_rectangle(Forme type , rectangle_s *rectangle);
node_s  *init_node_ellipse(Forme type , elipse_s *elipse);
void    add_line(list_s *list);
void    add_rectangle(list_s *list);
void    add_square(list_s *list);
void    add_circle(list_s *list);
void    add_ellipse(list_s *list);

#endif