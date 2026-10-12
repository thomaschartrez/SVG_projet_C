#include "../projet_svg.h"


void    free_line(line_s *line){
    free(line->a);
    free(line->b);
    free(line->color);
    free(line);
}

void    free_circle(circle_s *circle){
    free(circle->color_remplissage);
    free(circle->color_bord);
    free(circle->a);
    free(circle);
}

void    free_node(node_s *node){
    switch (node->type)
    {
    case LINE:
        free_line(&node->figure->line);
        break;
    case CIRCLE:
        free_circle(&node->figure->circle);
        break;
    }
    free(node->txt_html);
    free(node);
}

void    free_list(list_s *list){
    if (list->node != NULL){
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
    free(list);
}