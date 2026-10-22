#include "../../include/projet_svg.h"

/**
 * @brief Allocates, initializes, and adds a new circle shape to the list.
 * 
 * Clears the screen, allocates memory for a new circle structure and its components 
 * (fill color, border color, center point, transformation properties, and radius), 
 * prompts the user to enter the necessary values, creates a new node, and adds it 
 * to the specified list.
 * 
 * @param list Pointer to the `list_s` structure where the new circle node will be added.
 */
void    add_circle(list_s *list){
    node_s *node;
    circle_s *circle;

    system("clear");
    circle = malloc(sizeof(circle_s));
    printf("remplissge couleur remplissage\n");
    circle->color_remplissage = color_init();
    printf("remplissge couleur bord\n");
    circle->color_bord = color_init();
    circle->a = malloc(sizeof(point_s));
    printf("entrée les coordonnées du centre\n");
    add_new_point(circle->a);
    circle->transform = malloc(sizeof(transform_s));
    circle->transform->rotate = 0;
    circle->transform->x = 0;
    circle->transform->y = 0;
    printf("taille du rayon\n");
    scanf("%d", &circle->r);
    clear_stdin();
    node = init_node_circle(CIRCLE, circle);
    list = add_node(list, node);
}
