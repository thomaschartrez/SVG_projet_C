#include "../projet_svg.h"


void    free_line(line_s *line){

    if (line->a != NULL)
        free(line->a);
    if (line->b != NULL)
        free(line->b);
    if (line->color != NULL)
        free(line->color);
    if (line->transform != NULL)
        free(line->transform);
    if (line != NULL)
        free(line);
}

void    free_circle(circle_s *circle){
    if (circle->color_remplissage != NULL)
        free(circle->color_remplissage);
    if (circle->color_bord != NULL)
        free(circle->color_bord);
    if (circle->a != NULL) 
        free(circle->a);
    if(circle->transform != NULL)
        free(circle->transform);
    if (circle != NULL)
        free(circle);
}

void    free_node(node_s *node){
    switch (node->type)
    {
    case LINE:
        free_line(node->figure->line);
        break;
    case CIRCLE:
        free_circle(node->figure->circle);
        break;
    }
    free(node->figure);
    free(node);
}

void    free_list(list_s *list){
    printf("espoit");
    if (list != NULL && list->node != NULL){
        node_s *temp;
        node_s *temp2;
        temp = list->node;
        while (temp != NULL)
        {
            temp2= temp->next;
            free_node(temp);
            temp = temp2;
        }
    }
    if (list != NULL)
    {
        free(list);
    }
    
}