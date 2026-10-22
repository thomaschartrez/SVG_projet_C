#include "../../include/projet_svg.h"

/**
 * @brief Prompts the user to input and store 2D coordinates.
 * 
 * Asks the user to enter the x and y coordinate values via standard input, 
 * stores them into the provided point structure, and clears the input buffer.
 * 
 * @param point Pointer to the `point_s` structure where the input coordinates will be saved.
 */
void    add_new_point(point_s *point){
    
    printf("coordinate x:\n");
    scanf("%d", &point->x);
    clear_stdin();
    printf("coorrdinate y:\n");
    scanf("%d", &point->y);
    clear_stdin();
}
