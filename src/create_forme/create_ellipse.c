#include "../../include/projet_svg.h"

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