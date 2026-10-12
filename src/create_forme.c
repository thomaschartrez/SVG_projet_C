#include "../projet_svg.h"

void    add_new_point(point_s *point){
    int i = 1;
    
    while (i){
        i = 0;
        printf("a x:\n");
        scanf("%d", &point->x);
        printf("a y:\n");
        scanf("%d", &point->y);
        if (point->x <= 0 || point->y <= 0 ){
            printf("merci d utiliser des entier positifs\n");
            point->x = 0;
            point->y = 0;
            i = 1;
        }
    }
}

/*int add_rectangle(FILE *file){
    
}*/

int add_line(FILE *file){

    line_s *line;
    
    line = malloc(sizeof(line_s));
    line->color = color_init();
    line->a = malloc(sizeof(point_s));
    line->b = malloc(sizeof(point_s));
    printf("entree coordonné du point a\n");
    add_new_point(line->a);
    printf("entrée les coordonées du points b\n");
    add_new_point(line->b);
    fprintf(file, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"#%s\" />\n"
        , line->a->x, line->a->y,  line->b->x, line->b->y,line->color);
    free(line->color);
    free(line->a);
    free(line->b);
    free(line);
    return 0;
}

int add_circle(FILE *file){

    circle_s *circle;
    
    circle = malloc(sizeof(circle_s));
    printf("remplissge couleur remplissage\n");
    circle->color_remplissage = color_init();
    printf("remplissge couleur bord\n");
    circle->color_bord = color_init();
    circle->a = malloc(sizeof(point_s));
    printf("entrée les coordonnées du centre\n");
    add_new_point(circle->a);
    printf("taille du rayon\n");
    scanf("%d", &circle->r);
    fprintf(file, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"#%s\" stroke=\"#%s\" />",
    circle->a->x, circle->a->y, circle->r, circle->color_remplissage, circle->color_bord);
    free(circle->color_remplissage);
    free(circle->color_bord);
    free(circle->a);
    free(circle);
    return 0;
}

int    add_new_forme(void){
    unsigned char i;

    FILE *file = fopen("html/dsoformer.html", "w");
    fprintf(file, "<svg viewBox=\"0 0 1000 1000\" xmlns=\"http://www.w3.org/2000/svg\">\n");
    if (file == NULL)
        return (1);
    while(1){
        printf("0 : pour quitter\n");
        printf("1 : pour creer une ligne\n");
        printf("2 : pour creer une cercle\n");
        scanf("%hhd", &i);
        if (i == 0)
            break;
        if (i == 1)
            add_line(file);
        if (i == 2)
            add_circle(file);
    }
    fprintf(file, "</svg>\n");
    fclose(file);
    return 0;
}
