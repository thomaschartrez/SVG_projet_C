#include "../include/projet_svg.h"

void    save_point(point_s *point, FILE *file){
    fprintf(file,"%d,%d,", point->x, point->y);
}

void    save_color(char *color, FILE *file){
    fprintf(file, "%s,", color);
}

void    save_transform(transform_s *transform, FILE *file){
    fprintf(file,"%d,%d,%d,", transform->x, transform->y, transform->rotate);
}

void    save_circle(circle_s *circle, FILE *file){
    fprintf(file, "C|prcct|");
    save_point(circle->a, file);
    fprintf(file, "%d,", circle->r);
    save_color(circle->color_bord, file);
    save_color(circle->color_remplissage, file);
    save_transform(circle->transform, file);
}

void    save_line(line_s *line, FILE *file){
    fprintf(file, "L|ppct|");
    save_point(line->a, file);
    save_point(line->b, file);
    save_color(line->color, file);
    save_transform(line->transform, file);
}

void    save_ellipse(elipse_s *elipse, FILE *file){
    fprintf(file, "E|prrcct|");
    save_point(elipse->a, file);
    fprintf(file, "%d,", elipse->r1);
    fprintf(file, "%d,", elipse->r2);
    save_color(elipse->color_bord, file);
    save_color(elipse->color_remplissage, file);
    save_transform(elipse->transform, file);
}

void    save_square(rectangle_s *square, FILE *file){
    fprintf(file, "S|pwcct|");
    save_point(square->a, file);
    fprintf(file, "%d,", square->width);
    save_color(square->color_bord, file);
    save_color(square->color_remplissage, file);
    save_transform(square->transform, file);
}

void    save_rectangle(rectangle_s *rectangle, FILE *file){
    fprintf(file, "R|pwhcct|");
    save_point(rectangle->a, file);
    fprintf(file, "%d,", rectangle->width);
    fprintf(file, "%d,", rectangle->height);
    save_color(rectangle->color_bord, file);
    save_color(rectangle->color_remplissage, file);
    save_transform(rectangle->transform, file);
}

void    init_save(list_s *list, FILE *file){
    node_s *temp = list->node;

    while(temp != NULL){
        switch (temp->type)
        {
        case CIRCLE:
            save_circle(temp->figure->circle, file);
            fprintf(file, "\n");
            break;
        case LINE:
            save_line(temp->figure->line, file);
            fprintf(file, "\n");
            break;
        case ELLIPSE:
            save_ellipse(temp->figure->elipse, file);
            fprintf(file, "\n");
            break;
        case SQUARE:
            save_square(temp->figure->rectangle, file);
            fprintf(file, "\n");
            break;
        case RECTANGLE:
            save_rectangle(temp->figure->rectangle, file);
            fprintf(file, "\n");
            break;
        default:
            break;
        }
        temp = temp->next;
    }
    system("sleep 5");
}


int creat_save(list_s *list){
    FILE *file;
    char way[51];

    if (list->node == NULL)
        return -1;
    printf("enter the way of the file\n");
    scanf("%50s", way);
    file = fopen(way,"w");
    if (file == NULL){
        printf(ROUGE GRAS "invalid way or wrong right\n" RESET);
        system("sleep 5");
        return -1;
    }
    init_save(list, file);
    fclose(file);
    return 0;
}
