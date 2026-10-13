#include "../projet_svg.h"


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
