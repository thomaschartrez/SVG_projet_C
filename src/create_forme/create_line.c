#include "../../include/projet_svg.h"

void    add_line(list_s *list){

    line_s *line;
    node_s *node;
    
    system("clear");
    line = malloc(sizeof(line_s));
    line->color = color_init();
    line->a = malloc(sizeof(point_s));
    line->b = malloc(sizeof(point_s));
    line->transform = malloc(sizeof(transform_s));

    line->transform->rotate = 0;
    line->transform->x = 0;
    line->transform->y = 0;
    printf("entree coordonné du point a\n");
    add_new_point(line->a);
    printf("entrée les coordonées du points b\n");
    add_new_point(line->b);
    node = init_node_line(LINE, line);
    list = add_node(list, node);
}