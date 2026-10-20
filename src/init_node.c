#include "../include/projet_svg.h"


node_s  *init_node_circle(Forme type, circle_s *circle){
    node_s  *node;

    node = malloc(sizeof(node_s));
    node->figure = malloc(sizeof(Figure));
    node->type = type;
    node->figure->circle = circle;
    node->next = NULL;
    return node;
}


node_s  *init_node_line(Forme type ,line_s *line){
    node_s  *node;

    node = malloc(sizeof(node_s));
    node->figure = malloc(sizeof(Figure));
    node->type = type;
    node->figure->line = line;
    node->next = NULL;
    return node;
}

node_s  *init_node_square(Forme type ,rectangle_s *square){
    node_s  *node;

    node = malloc(sizeof(node_s));
    node->figure = malloc(sizeof(Figure));
    node->type = type;
    node->figure->rectangle = square;
    node->next = NULL;
    return node;
}

node_s  *init_node_rectangle(Forme type , rectangle_s *rectangle){
    node_s  *node;

    node = malloc(sizeof(node_s));
    node->figure = malloc(sizeof(Figure));
    node->type = type;
    node->figure->rectangle = rectangle;
    node->next = NULL;
    return node;
}

node_s  *init_node_ellipse(Forme type , elipse_s *elipse){
    node_s  *node;

    node = malloc(sizeof(node_s));
    node->figure = malloc(sizeof(Figure));
    node->type = type;
    node->figure->elipse = elipse;
    node->next = NULL;
    return node;
}

