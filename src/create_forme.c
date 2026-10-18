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

int add_line(list_s *list){

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
    return 0;
}

int add_circle(list_s *list){

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

    return 0;
}

int    add_new_forme(list_s *list){
    unsigned char i;

    FILE *file = fopen("html/dsoformer.html", "w");
    fprintf(file, "<svg viewBox=\"0 0 1000 1000\" xmlns=\"http://www.w3.org/2000/svg\">\n");
    if (file == NULL)
        return (1);
    while(1){
        system("clear");
        printf(" ---------------------------------------------------\n");
        printf("||       0 : pour quitter                         ||\n");
        printf("||       1 : pour creer une ligne                 ||\n");
        printf("||       2 : pour creer une cercle                ||\n");
        printf(" ---------------------------------------------------\n");
        scanf("%hhd", &i);
        clear_stdin();
        if (i == 0)
            break;
        if (i == 1)
            add_line(list);
        if (i == 2)
            add_circle(list);
        i = 0;
    }
    fprintf(file, "</svg>\n");
    fclose(file);
    return 0;
}
