#include "../../include/projet_svg.h"

void    add_rectangle(list_s *list){

    node_s *node;
    rectangle_s *rectangle;
    
    system("clear");
    rectangle = malloc(sizeof(rectangle_s));
    printf("remplissge couleur remplissage\n");
    rectangle->color_remplissage = color_init();
    printf("remplissge couleur bord\n");
    rectangle->color_bord = color_init();
    rectangle->a = malloc(sizeof(point_s));
    printf("enter the coordiation from the point at the top left\n");
    add_new_point(rectangle->a);
    rectangle->width = 0;
    printf("enter width\n");
    scanf("%d", &rectangle->width);
    rectangle->height = 0;
    clear_stdin();
    printf("enter height\n");
    scanf("%d", &rectangle->height);
    clear_stdin();
    rectangle->transform = malloc(sizeof(transform_s));
    rectangle->transform->rotate = 0;
    rectangle->transform->x = 0;
    rectangle->transform->y = 0;
    node = init_node_rectangle(RECTANGLE, rectangle);
    list = add_node(list, node);
}
