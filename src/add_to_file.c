#include "../projet_svg.h"

void    add_line_to_file(line_s *line, FILE *file){
    fprintf(file, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"#%s\" />\n"
        , line->a->x, line->a->y,  line->b->x, line->b->y,line->color);
}
void    add_circle_to_file(circle_s *circle, FILE *file){
    fprintf(file, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"#%s\" stroke=\"#%s\" />",
    circle->a->x, circle->a->y, circle->r, circle->color_remplissage, circle->color_bord);
}

int add_to_file(list_s *list){
    node_s *temp;
    FILE *file = fopen("html/svgformer.html", "w");

    fprintf(file, "<svg viewBox=\"0 0 1000 1000\" xmlns=\"http://www.w3.org/2000/svg\">\n");
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
        }
        temp = temp->next;
    }
    fprintf(file, "</svg>\n");
    fclose(file);
    return 0;
}
