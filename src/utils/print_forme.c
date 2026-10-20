#include "../../include/projet_svg.h"

void    print_transform(transform_s *transform){
    if (transform->rotate != 0)
        printf(GREEN"-  rotation:"RESET"   %d\n", transform->rotate);
    if (transform->x != 0 || transform->y != 0)
        printf(GREEN"-  translation:"RESET" x: %d  y: %d\n", transform->x, transform->y);
}

void    print_point(point_s *point){
    printf(GREEN"-  point a :"RESET"   x : %d   y : %d\n", point->x, point->y);
}

void    print_color(char    *color){
    printf(GREEN"-  color   :"RESET"   %s\n", color);
}

void    print_circle(circle_s *circle){
    printf("\n");
    print_point(circle->a);
    print_color(circle->color_bord);
    print_color(circle->color_remplissage);
    printf(GREEN"-  radius  :"RESET  "   %d\n", circle->r);
    print_transform(circle->transform);
    printf("\n");
}

void    print_line(line_s *line){
    printf("\n");
    print_point(line->a);
    print_point(line->b);
    print_color(line->color);
    print_transform(line->transform);
    printf("\n");
}

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

void    print_square(rectangle_s *square){
    printf("\n");
    print_point(square->a);
    print_color(square->color_bord);
    print_color(square->color_remplissage);
    printf(GREEN"-  width   :"RESET  "   %d\n", square->width);
    print_transform(square->transform);
    printf("\n");
}

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
