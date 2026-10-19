#include "../projet_svg.h"

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
