#include "../include/projet_svg.h"

/**
 * @brief Serializes and writes a point's coordinates to the specified file stream.
 * 
 * This function outputs the point's x and y coordinates, separated by a comma, 
 * into the provided file.
 * 
 * @param point Pointer to the `point_s` structure containing the point data to be saved.
 * @param file Pointer to an open `FILE` stream where the point coordinates will be written.
 */
void    save_point(point_s *point, FILE *file){
    fprintf(file,"%d,%d,", point->x, point->y);
}

/**
 * @brief Serializes and writes a color string to the specified file stream.
 * 
 * This function outputs the given color string followed by a comma into the provided file.
 * 
 * @param color Pointer to the null-terminated string representing the color data to be saved.
 * @param file Pointer to an open `FILE` stream where the color string will be written.
 */
void    save_color(char *color, FILE *file){
    fprintf(file, "%s,", color);
}

/**
 * @brief Serializes and writes transformation attributes to the specified file stream.
 * 
 * This function outputs the translation coordinates (`x` and `y`) followed by the 
 * rotation angle (`rotate`), each separated by a comma, into the provided file.
 * 
 * @param transform Pointer to the `transform_s` structure containing the transformation data to be saved.
 * @param file Pointer to an open `FILE` stream where the serialized transformation data will be written.
 */
void    save_transform(transform_s *transform, FILE *file){
    fprintf(file,"%d,%d,%d,", transform->x, transform->y, transform->rotate);
}

/**
 * @brief Serializes and writes a circle's properties to the specified file stream.
 * 
 * This function outputs a custom format identifier (`C|prcct|`) followed by the 
 * circle's anchor point, radius (`r`), border color, fill color, and transformation 
 * attributes into the provided file.
 * 
 * @param circle Pointer to the `circle_s` structure containing the circle data to be saved.
 * @param file Pointer to an open `FILE` stream where the serialized circle data will be written.
 */
void    save_circle(circle_s *circle, FILE *file){
    fprintf(file, "C|prcct|");
    save_point(circle->a, file);
    fprintf(file, "%d,", circle->r);
    save_color(circle->color_bord, file);
    save_color(circle->color_remplissage, file);
    save_transform(circle->transform, file);
}

/**
 * @brief Serializes and writes a line's properties to the specified file stream.
 * 
 * This function outputs a custom format identifier (`L|ppct|`) followed by the 
 * line's starting point (`a`), ending point (`b`), color, and transformation 
 * attributes into the provided file.
 * 
 * @param line Pointer to the `line_s` structure containing the line data to be saved.
 * @param file Pointer to an open `FILE` stream where the serialized line data will be written.
 */
void    save_line(line_s *line, FILE *file){
    fprintf(file, "L|ppct|");
    save_point(line->a, file);
    save_point(line->b, file);
    save_color(line->color, file);
    save_transform(line->transform, file);
}

/**
 * @brief Serializes and writes an ellipse's properties to the specified file stream.
 * 
 * This function outputs a custom format identifier (`E|prrcct|`) followed by the 
 * ellipse's anchor point, horizontal/vertical radii (`r1` and `r2`), border color, 
 * fill color, and transformation attributes into the provided file.
 * 
 * @param elipse Pointer to the `elipse_s` structure containing the ellipse data to be saved.
 * @param file Pointer to an open `FILE` stream where the serialized ellipse data will be written.
 */
void    save_ellipse(elipse_s *elipse, FILE *file){
    fprintf(file, "E|prrcct|");
    save_point(elipse->a, file);
    fprintf(file, "%d,", elipse->r1);
    fprintf(file, "%d,", elipse->r2);
    save_color(elipse->color_bord, file);
    save_color(elipse->color_remplissage, file);
    save_transform(elipse->transform, file);
}

/**
 * @brief Serializes and writes a square's properties to the specified file stream.
 * 
 * This function outputs a custom format identifier (`S|pwcct|`) followed by the 
 * square's anchor point, width (side length), border color, fill color, and 
 * transformation attributes into the provided file.
 * 
 * @param square Pointer to the `rectangle_s` structure representing the square data to be saved.
 * @param file Pointer to an open `FILE` stream where the serialized square data will be written.
 */
void    save_square(rectangle_s *square, FILE *file){
    fprintf(file, "S|pwcct|");
    save_point(square->a, file);
    fprintf(file, "%d,", square->width);
    save_color(square->color_bord, file);
    save_color(square->color_remplissage, file);
    save_transform(square->transform, file);
}

/**
 * @brief Serializes and writes a rectangle's properties to the specified file stream.
 * 
 * This function outputs a custom format identifier (`R|pwhcct|`) followed by the 
 * rectangle's anchor point, width, height, border color, fill color, and transformation 
 * attributes into the provided file.
 * 
 * @param rectangle Pointer to the `rectangle_s` structure containing the rectangle data to be saved.
 * @param file Pointer to an open `FILE` stream where the serialized rectangle data will be written.
 */
void    save_rectangle(rectangle_s *rectangle, FILE *file){
    fprintf(file, "R|pwhcct|");
    save_point(rectangle->a, file);
    fprintf(file, "%d,", rectangle->width);
    fprintf(file, "%d,", rectangle->height);
    save_color(rectangle->color_bord, file);
    save_color(rectangle->color_remplissage, file);
    save_transform(rectangle->transform, file);
}

/**
 * @brief Iterates through the linked list of figures and saves each one to the file.
 * 
 * This function traverses the list of nodes starting from the head, checks the 
 * shape type of each figure (CIRCLE, LINE, ELLIPSE, SQUARE, or RECTANGLE), 
 * and calls the appropriate saving function to write the figure data to the file, 
 * followed by a newline. It finishes with a 5-second system pause.
 * 
 * @param list Pointer to the `list_s` structure containing the figures to be saved.
 * @param file Pointer to an open `FILE` stream where the figure data will be written.
 */
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


/**
 * @brief Prompts the user for a file path and saves the SVG editor list to a file.
 * 
 * This function checks if the list is empty, clears the terminal screen, displays 
 * an SVG editor header, and asks the user to input a file path. It attempts to 
 * open the file, handles any errors (including a 5-second sleep on failure), and 
 * delegates the actual saving process to `init_save`.
 * 
 * @param list Pointer to the `list_s` structure containing the nodes to be saved.
 * @return int Returns `0` on success, or `-1` if the list node is NULL or the file could not be opened.
 */
int creat_save(list_s *list){
    FILE *file;
    char path[500];

    if (list->node == NULL)
        return -1;
    system("clear");
    printf(GREEN "        ┌─────────────────────────────────────────┐\n" RESET);
    printf(GREEN "        │              🎨 SVG EDITOR              │\n" RESET);
    printf(GREEN "        └─────────────────────────────────────────┘\n\n" RESET);
    printf("enter the path of the file\n");
    scanf("%50s", path);
    file = fopen(path,"wc");
    if (file == NULL){
        printf(ROUGE GRAS "invalid path or wrong right\n" RESET);
        system("sleep 5");
        return -1;
    }
    init_save(list, file);
    fclose(file);
    return 0;
}
