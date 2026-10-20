#include "../../include/projet_svg.h"

void    add_new_point(point_s *point){
    
    printf("coordinate x:\n");
    scanf("%d", &point->x);
    clear_stdin();
    printf("coorrdinate y:\n");
    scanf("%d", &point->y);
    clear_stdin();
}
