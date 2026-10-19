#include "../projet_svg.h"

void    add_new_point(point_s *point){
    
    printf("coordinate x:\n");
    scanf("%d", &point->x);
    clear_stdin();
    printf("coorrdinate y:\n");
    scanf("%d", &point->y);
    clear_stdin();
}

/*int add_rectangle(FILE *file){
    
}*/

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
    scanf("%d", &rectangle->height);
    clear_stdin();
    rectangle->transform = malloc(sizeof(transform_s));
    rectangle->transform->rotate = 0;
    rectangle->transform->x = 0;
    rectangle->transform->y = 0;
    node = init_node_rectangle(RECTANGLE, rectangle);
    list = add_node(list, node);
}

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
    clear_stdin();
    node = init_node_square(SQUARE, square);
    list = add_node(list, node);
}

int    add_new_forme(list_s *list){
    unsigned char i;


    while(1){
        system("clear");
        printf(" ---------------------------------------------------\n");
        printf("||       0 : to quit                              ||\n");
        printf("||       1 : to create a line                     ||\n");
        printf("||       2 : to create a circle                   ||\n");
        printf("||       3 : to create a square                   ||\n");
        printf("||       4 : to create a rectangle                ||\n");
        printf("||       5 : to create an ellipse                 ||\n");
        printf(" ---------------------------------------------------\n");
        scanf("%hhd", &i);
        clear_stdin();
        switch (i)
        {
        case 0:
            return 0;
        case 1:
            add_line(list);
            break;
        case 2:
            add_circle(list);
            break;
        case 3:
            add_square(list);
            break;
        case 4:
            add_rectangle(list);
            break;
        case 5:
            add_ellipse(list);
            break;
        default:
            break;
        }
    }
    return 0;
}
