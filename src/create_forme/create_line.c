#include "../../include/projet_svg.h"

/**
 * @brief Allocates, initializes, and adds a new line shape to the list.
 * 
 * Clears the screen, allocates memory for a new line structure and its components 
 * (color, points a and b, and transformation properties), prompts the user to enter 
 * the coordinates for both points, creates a new node, and adds it to the specified list.
 * 
 * @param list Pointer to the `list_s` structure where the new line node will be added.
 */
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