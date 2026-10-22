#include "../../include/projet_svg.h"


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

void    free_ellipse(elipse_s *elipse){
    if (elipse->color_remplissage != NULL)
        free(elipse->color_remplissage);
    if (elipse->color_bord != NULL)
        free(elipse->color_bord);
    if (elipse->a != NULL) 
        free(elipse->a);
    if(elipse->transform != NULL)
        free(elipse->transform);
    if (elipse != NULL)
        free(elipse);
}

void    free_rectangle(rectangle_s *rectangle){
    if (rectangle->color_remplissage != NULL)
        free(rectangle->color_remplissage);
    if (rectangle->color_bord != NULL)
        free(rectangle->color_bord);
    if (rectangle->a != NULL) 
        free(rectangle->a);
    if(rectangle->transform != NULL)
        free(rectangle->transform);
    if (rectangle != NULL)
        free(rectangle);
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

void    free_polyline(polyline_s *polyline){
    poly_point_s *temp = polyline->node;
    poly_point_s *temp2;

    if (polyline->color != NULL)
        free(polyline->color);
    if (polyline->color_fill != NULL)
        free(polyline->color_fill);
    if (polyline->transform != NULL)
        free(polyline->transform);
    while (temp != NULL)
    {
        temp2= temp->next;
        free(temp->point);
        free(temp);
        temp = temp2;
    }
    free(polyline);
}

/**
 * @brief Frees a node and its associated figure data.
 * 
 * Inspects the node's type using a switch statement, deallocates the specific 
 * figure data (such as a line or circle) using the appropriate helper function, 
 * and then frees both the figure container and the node itself.
 * 
 * @param node Pointer to the `node_s` structure to be freed.
 */
void    free_node(node_s *node){
    switch (node->type)
    {
    case LINE:
        free_line(node->figure->line);
        break;
    case CIRCLE:
        free_circle(node->figure->circle);
        break;
    case SQUARE :
        free_rectangle(node->figure->rectangle);
        break;
    case RECTANGLE:
        free_rectangle(node->figure->rectangle);
        break;
    case POLYGONE:
        free_polyline(node->figure->polyline);
        break;
    case POLYLINE:
        free_polyline(node->figure->polyline);
        break;
    default :
        break;
    }
    free(node->figure);
    free(node);
}

/**
 * @brief Frees a linked list and all of its nodes.
 * 
 * Safely deallocates all memory associated with the given list structure, 
 * including iterating through and freeing each individual node using `free_node`, 
 * and finally freeing the list container itself.
 * 
 * @param list Pointer to the `list_s` structure to be freed. If the pointer 
 *        is NULL, the function does nothing.
 */
void    free_list(list_s *list){
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
        free(list);
}
