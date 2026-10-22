#include "../../include/polyline.h"
#include "../../include/projet_svg.h"

void  add_polyline(list_s *list, Forme type){
    polyline_s  *polyline = init_polyline();
    int         nb_point;
    node_s      *node;
    poly_point_s    *temp;

    while(1){
        nb_point = 0;
        printf("enter the number of point you want :\n");
        scanf("%d", &nb_point);
        clear_stdin();
        if (nb_point > 1)
            break;
        else
            printf(ROUGE GRAS "WRONG INPUT USE A NUMBER > 1" RESET);
    }
    
    while (nb_point > 0){
        point_s *point = malloc(sizeof(point_s));
        poly_point_s *node_poly = malloc(sizeof(poly_point_s));
        node_poly->point = point;
        node_poly->next = NULL;
        add_new_point(point);
        if (polyline->node == NULL){
            polyline->node = node_poly;
            temp = node_poly;
        }
        else{
            temp->next = node_poly;
            temp = temp->next;
        }
        nb_point--;
    }
    polyline->color = color_init();
    if (type == POLYGONE)
        polyline->color_fill = color_init();
    else
        polyline->color_fill = NULL;
    polyline->transform = malloc(sizeof(transform_s));
    polyline->transform->rotate = 0;
    polyline->transform->x = 0;
    polyline->transform->y = 0;
    node = init_node_polyline(type,polyline);
    list = add_node(list, node);
}