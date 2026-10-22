#include "../../include/projet_svg.h"

/**
 * @brief Allocates, initializes, and adds a new square shape to the list.
 * 
 * Clears the screen, allocates memory for a new square (rectangle) structure 
 * and its components (fill color, border color, top-left point, width/height, 
 * and transformation properties), prompts the user to enter the necessary values, 
 * creates a new node, and adds it to the specified list.
 * 
 * @param list Pointer to the `list_s` structure where the new square node will be added.
 */
void    add_square(list_s *list){

    node_s *node;
    rectangle_s *square;
    
    system("clear");
    square = malloc(sizeof(rectangle_s));
    printf("remplissge couleur remplissage\n");
    square->color_remplissage = color_init();
    printf("remplissge couleur bord\n");
    square->color_bord = color_init();
    square->a = malloc(sizeof(point_s));
    printf("enter the coordiation from the point at the top left\n");
    add_new_point(square->a);
    square->width = 0;
    printf("enter width\n");
    scanf("%d", &square->width);
    clear_stdin();
    square->height = square->width;
    square->transform = malloc(sizeof(transform_s));
    square->transform->rotate = 0;
    square->transform->x = 0;
    square->transform->y = 0;
    node = init_node_square(SQUARE, square);
    list = add_node(list, node);
}
