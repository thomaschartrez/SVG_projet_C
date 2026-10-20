#include "../include/projet_svg.h"

void    add_line_to_file(line_s *line, FILE *file){
    fprintf(file, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"#%s\" stroke-width=\"7\" transform=\"rotate(%d) translate(%d, %d)\" />\n"
        , line->a->x, line->a->y,  line->b->x, line->b->y,line->color
        , line->transform->rotate, line->transform->x, line->transform->y);
}
void    add_circle_to_file(circle_s *circle, FILE *file){
        fprintf(file, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"#%s\" stroke=\"#%s\" stroke-width=\"7\" transform=\"rotate(%d) translate(%d, %d)\"/> \n",
        circle->a->x, circle->a->y, circle->r, circle->color_remplissage, circle->color_bord, circle->transform->rotate, circle->transform->x, circle->transform->y);
}

void    add_ellispe_to_file(elipse_s *elipse, FILE *file){
    fprintf(file,"<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"#%s\" stroke=\"#%s\" stroke-width=\"7\" transform=\"rotate(%d) translate(%d, %d)\" /> \n"
        , elipse->a->x , elipse->a->y, elipse->r1, elipse->r2, elipse->color_remplissage, elipse->color_bord
        ,elipse->transform->rotate, elipse->transform->x, elipse->transform->y);
}

void    add_rectangle_to_file(rectangle_s *rectangle, FILE *file){
    fprintf(file, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"#%s\" stroke=\"#%s\" stroke-width=\"7\" transform=\"rotate(%d) translate(%d,%d)\"/>\n"
    , rectangle->a->x, rectangle->a->y, rectangle->width, rectangle->height, rectangle->color_remplissage, rectangle->color_bord
    , rectangle->transform->rotate, rectangle->transform->x, rectangle->transform->y);
}

int add_to_file(list_s *list){
    node_s *temp;
    FILE *file = fopen("html/svgformer.svg", "w");

    if (list->node == NULL)
        return 0;
    fprintf(file, "<svg viewBox=\"-1000 -1000 2000 2000\" xmlns=\"http://www.w3.org/2000/svg\">\n");
    temp = list->node;
    while(temp != NULL){
        switch (temp->type)
        {
            case LINE:
                add_line_to_file(temp->figure->line, file);
                break;
            case CIRCLE:
                add_circle_to_file(temp->figure->circle, file);
                break;
            case ELLIPSE :
                add_ellispe_to_file(temp->figure->elipse, file);
                break;
            case RECTANGLE:
                add_rectangle_to_file(temp->figure->rectangle, file);
                break;
           case SQUARE:
                add_rectangle_to_file(temp->figure->rectangle, file);
                break;
            default :
                break;
        }
        temp = temp->next;
    }
    fprintf(file, "</svg>\n");
    fclose(file);
    return 0;
}
