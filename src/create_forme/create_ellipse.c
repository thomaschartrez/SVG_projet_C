#include "../../include/projet_svg.h"

/**
 * @brief Allocates, initializes, and adds a new ellipse shape to the list.
 * 
 * Clears the screen, allocates memory for a new ellipse structure and its components 
 * (fill color, border color, center point, transformation properties, and two radii), 
 * prompts the user to enter the necessary values, creates a new node, and adds it 
 * to the specified list.
 * 
 * @param list Pointer to the `list_s` structure where the new ellipse node will be added.
 */
void    add_ellipse(list_s *list){

    node_s *node;
    elipse_s *ellipse;
    
    system("clear");
    ellipse = malloc(sizeof(circle_s));
    printf("remplissge couleur remplissage\n");
    ellipse->color_remplissage = color_init();
    printf("remplissge couleur bord\n");
    ellipse->color_bord = color_init();
    ellipse->a = malloc(sizeof(point_s));
    printf("enter center position :\n");
    add_new_point(ellipse->a);
    ellipse->transform = malloc(sizeof(transform_s));
    ellipse->transform->rotate = 0;
    ellipse->transform->x = 0;
    ellipse->transform->y = 0;
    printf("radius 1 :\n");
    scanf("%d", &ellipse->r1);
    clear_stdin();
    printf("radius 2 :\n");
    scanf("%d", &ellipse->r2);
    clear_stdin();
    node = init_node_ellipse(ELLIPSE, ellipse);
    list = add_node(list, node);
}