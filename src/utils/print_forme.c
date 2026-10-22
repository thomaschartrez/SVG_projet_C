#include "../../include/projet_svg.h"

/**
 * @brief Prints the transformation details (rotation and translation) if they are non-zero.
 * 
 * @param transform Pointer to the transformation structure to print.
 */
void    print_transform(transform_s *transform){
    if (transform->rotate != 0)
        printf(GREEN"-  rotation:"RESET"   %d\n", transform->rotate);
    if (transform->x != 0 || transform->y != 0)
        printf(GREEN"-  translation:"RESET" x: %d  y: %d\n", transform->x, transform->y);
}

/**
 * @brief Prints the coordinates (x and y) of a point structure.
 * 
 * @param point Pointer to the point structure to be printed.
 */
void    print_point(point_s *point){
    printf(GREEN"-  point   :"RESET"   x : %d   y : %d\n", point->x, point->y);
}

/**
 * @brief Prints the color string with terminal formatting.
 * 
 * @param color Pointer to the string representing the color to be printed.
 */
void    print_color(char    *color){
    printf(GREEN"-  color   :"RESET"   %s\n", color);
}

/**
 * @brief Prints the details of a circle structure, including its center point, border color, fill color, radius, and transformations.
 * 
 * @param circle Pointer to the circle structure to be printed.
 */
void    print_circle(circle_s *circle){
    printf("\n");
    print_point(circle->a);
    print_color(circle->color_bord);
    print_color(circle->color_remplissage);
    printf(GREEN"-  radius  :"RESET  "   %d\n", circle->r);
    print_transform(circle->transform);
    printf("\n");
}

/**
 * @brief Prints the details of a line structure, including its start point, end point, color, and transformations.
 * 
 * @param line Pointer to the line structure to be printed.
 */
void    print_line(line_s *line){
    printf("\n");
    print_point(line->a);
    print_point(line->b);
    print_color(line->color);
    print_transform(line->transform);
    printf("\n");
}

/**
 * @brief Prints the details of an ellipse structure, including its center point, border color, fill color, radii, and transformations.
 * 
 * @param elipse Pointer to the ellipse structure to be printed.
 */
void    print_ellipse(elipse_s *elipse){
    printf("\n");
    print_point(elipse->a);
    print_color(elipse->color_bord);
    print_color(elipse->color_remplissage);
    printf(GREEN"-  radius 1:"RESET  "   %d\n", elipse->r1);
    printf(GREEN"-  radius 2:"RESET  "   %d\n", elipse->r2);
    print_transform(elipse->transform);
    printf("\n");
}

/**
 * @brief Prints the details of a square structure, including its point, border color, fill color, width, and transformations.
 * 
 * @param square Pointer to the rectangle structure representing the square to be printed.
 */
void    print_square(rectangle_s *square){
    printf("\n");
    print_point(square->a);
    print_color(square->color_bord);
    print_color(square->color_remplissage);
    printf(GREEN"-  width   :"RESET  "   %d\n", square->width);
    print_transform(square->transform);
    printf("\n");
}

/**
 * @brief Prints the details of a rectangle structure, including its point, border color, fill color, width, height, and transformations.
 * 
 * @param rectangle Pointer to the rectangle structure to be printed.
 */
void    print_rectangle(rectangle_s *rectangle){
    printf("\n");
    print_point(rectangle->a);
    print_color(rectangle->color_bord);
    print_color(rectangle->color_remplissage);
    printf(GREEN"-  width   :"RESET  "   %d\n", rectangle->width);
    printf(GREEN"-  heigth  :"RESET  "   %d\n", rectangle->width);
    print_transform(rectangle->transform);
    printf("\n");
}

/**
 * @brief Prints the details of a polyline structure, including its point count, individual points, colors, and transformations.
 * 
 * @param polyline Pointer to the polyline structure to be printed.
 */
void    print_polyline(polyline_s *polyline){
    poly_point_s *temp = polyline->node;

    printf("\n");
    printf(GREEN"- number point :"RESET  "   %d\n", polyline->nb_point);
    while(temp != NULL){
        print_point(temp->point);
        temp = temp->next;
    }
    print_color(polyline->color);
    if (polyline->color_fill)
        print_color(polyline->color_fill);
    print_transform(polyline->transform);
    printf("\n");
}
