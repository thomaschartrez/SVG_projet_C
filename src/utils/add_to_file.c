#include "../../include/projet_svg.h"

/**
 * @brief Writes an SVG line representation of the line structure to the specified file.
 * 
 * @param line Pointer to the line structure to export.
 * @param file Pointer to the FILE stream where the SVG output will be written.
 */
void    add_line_to_file(line_s *line, FILE *file){
    fprintf(file, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"#%s\" stroke-width=\"7\" transform=\"rotate(%d) translate(%d, %d)\" />\n"
        , line->a->x, line->a->y,  line->b->x, line->b->y,line->color
        , line->transform->rotate, line->transform->x, line->transform->y);
}

/**
 * @brief Writes an SVG circle representation of the circle structure to the specified file.
 * 
 * @param circle Pointer to the circle structure to export.
 * @param file Pointer to the FILE stream where the SVG output will be written.
 */
void    add_circle_to_file(circle_s *circle, FILE *file){
        fprintf(file, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"#%s\" stroke=\"#%s\" stroke-width=\"7\" transform=\"rotate(%d) translate(%d, %d)\"/> \n",
        circle->a->x, circle->a->y, circle->r, circle->color_remplissage, circle->color_bord, circle->transform->rotate, circle->transform->x, circle->transform->y);
}

/**
 * @brief Writes an SVG ellipse representation of the ellipse structure to the specified file.
 * 
 * @param elipse Pointer to the ellipse structure to export.
 * @param file Pointer to the FILE stream where the SVG output will be written.
 */
void    add_ellispe_to_file(elipse_s *elipse, FILE *file){
    fprintf(file,"<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"#%s\" stroke=\"#%s\" stroke-width=\"7\" transform=\"rotate(%d) translate(%d, %d)\" /> \n"
        , elipse->a->x , elipse->a->y, elipse->r1, elipse->r2, elipse->color_remplissage, elipse->color_bord
        ,elipse->transform->rotate, elipse->transform->x, elipse->transform->y);
}

/**
 * @brief Writes an SVG rectangle representation of the rectangle structure to the specified file.
 * 
 * @param rectangle Pointer to the rectangle structure to export.
 * @param file Pointer to the FILE stream where the SVG output will be written.
 */
void    add_rectangle_to_file(rectangle_s *rectangle, FILE *file){
    fprintf(file, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"#%s\" stroke=\"#%s\" stroke-width=\"7\" transform=\"rotate(%d) translate(%d,%d)\"/>\n"
    , rectangle->a->x, rectangle->a->y, rectangle->width, rectangle->height, rectangle->color_remplissage, rectangle->color_bord
    , rectangle->transform->rotate, rectangle->transform->x, rectangle->transform->y);
}

/**
 * @brief Writes the coordinates of a point to the specified file.
 * 
 * @param point Pointer to the point structure containing the coordinates.
 * @param file Pointer to the FILE stream where the output will be written.
 */
void    add_point(point_s *point, FILE *file){
    fprintf(file, "%d,%d ", point->x, point->y);
}

/**
 * @brief Writes an SVG polygon representation of the polyline structure to the specified file.
 * 
 * @param polyline Pointer to the polyline structure to export.
 * @param file Pointer to the FILE stream where the SVG output will be written.
 */
void    add_polygone_to_file(polyline_s *polyline, FILE *file){
    poly_point_s *temp = polyline->node;
    fprintf(file,"<polygon points=\"");
    while (temp != NULL){
        add_point(temp->point, file);
        temp = temp->next;
    }
    fprintf(file, "\" stroke=\"#%s\" stroke-width=\"7\" fill=\"#%s\" transform=\"rotate(%d) translate(%d,%d)\"/>"
        , polyline->color, polyline->color_fill, polyline->transform->rotate, polyline->transform->x, polyline->transform->y);
}

/**
 * @brief Writes an SVG polyline representation of the polyline structure to the specified file.
 * 
 * @param polyline Pointer to the polyline structure to export.
 * @param file Pointer to the FILE stream where the SVG output will be written.
 */
void    add_polyline_to_file(polyline_s *polyline, FILE *file){
    poly_point_s *temp = polyline->node;
    fprintf(file,"<polyline points=\"");
    while (temp != NULL){
        add_point(temp->point, file);
        temp = temp->next;
    }
    fprintf(file, "\" fill=\"none\" stroke=\"#%s\" stroke-width=\"7\" transform=\"rotate(%d) translate(%d,%d)\"/>"
        , polyline->color, polyline->transform->rotate, polyline->transform->x, polyline->transform->y);
}

/**
 * @brief Exports all shapes stored in the list to an SVG file ("html/svgformer.svg").
 * 
 * @param list Pointer to the list structure containing the shapes to export.
 * @return int Returns 0 upon completion or if the list is empty.
 */
int add_to_file(list_s *list){
    node_s *temp;
    FILE *file = fopen("svgformer.svg", "w");

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
            case POLYLINE :
                add_polyline_to_file(temp->figure->polyline, file);
                break;
            case POLYGONE :
                add_polygone_to_file(temp->figure->polyline, file);
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
