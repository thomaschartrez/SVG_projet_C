#include "../include/projet_svg.h"

/**
 * @brief Prompts the user for X and Y coordinate offsets and updates the transformation attributes.
 * 
 * @param transform Pointer to the `transform_s` structure to be translated.
 */
void    translate_shape(transform_s *transform){
    int x_coordinate = 0;
    int y_coordinate = 0;

    
    printf("enter the x-coordinate\n");
    scanf("%d", &x_coordinate);
    clear_stdin();
    transform->x = transform->x + x_coordinate;
    printf("enter the y-coordinate\n");
    scanf("%d", &y_coordinate);
    transform->y = transform->y + y_coordinate;
    clear_stdin();
}

/**
 * @brief Prompts the user for a rotation angle and adds it to the existing transformation rotation.
 * 
 * @param transform Pointer to the `transform_s` structure to be rotated.
 */
void    rotate_shape(transform_s *transform){
    int temp;
    
    temp = 0;
    printf("enter an interger for the rotation dont use 0 to quit use 360 :)\n");
    scanf("%d", &temp);
    clear_stdin();
    if(temp != 0)
        transform->rotate += temp;
}

/**
 * @brief Inverts a square's coordinates along the X or Y axis based on user selection.
 * 
 * @param square Pointer to the `rectangle_s` structure representing the square.
 * @return rectangle_s* Pointer to the modified square.
 */
rectangle_s  *square_inversion(rectangle_s *square){
    int input_user = 0;

    printf("\n");
    printf("||select 0 ❌ to quit    ||\n");
    printf("||select 1 for x         ||\n");
    printf("||select 2 for y         ||\n");
    printf("\n");
    scanf("%d",&input_user);
    clear_stdin();
    switch (input_user)
    {
    case 0:
        return square;
        break;
    case 1:
        square->a->x = -(square->a->x + square->width);
        return square;
        break;
    case 2:
        square->a->y = -(square->a->y + square->height);
        return square;
        break;
    default:
        break;
    }
    return square;
}

/**
 * @brief Displays an interactive menu to modify properties of a rectangle.
 * 
 * Allows modifying the start point, stroke color, fill color, rotation, translation, 
 * inversion, width, and height.
 * 
 * @param rectangle Pointer to the `Figure` union/structure containing the rectangle.
 * @return rectangle_s* Pointer to the modified rectangle structure.
 */
rectangle_s  *modify_rectangle(Figure *rectangle){
    int input_user;
    while (1)
    {
        system("clear");
        print_square(rectangle->rectangle);
        printf("   -------------------------------------------------\n");
        printf("||select 0 ❌ to quit                             ||\n");
        printf("||select 1 to modify start point                  ||\n");
        printf("||select 2 to modify strok color                  ||\n");
        printf("||select 3 to modify the fill color               ||\n");
        printf("||select 4 to rotate                              ||\n");
        printf("||select 5 to translate                           ||\n");
        printf("||select 6 for inversion x or y                   ||\n");
        printf("||select 7 to change width                        ||\n");
        printf("||select 8 to change heigth                       ||\n");
        printf(" ---------------------------------------------------\n");
        scanf("%d",&input_user);
        clear_stdin();
        switch (input_user)
        {
        case 0:
            return (rectangle->rectangle);
            break;
        case 1:
            add_new_point(rectangle->rectangle->a);
            break;
        case 2:
            free(rectangle->rectangle->color_bord);
            rectangle->rectangle->color_bord = color_init();
            break;
        case 3:
            free(rectangle->rectangle->color_remplissage);
            rectangle->rectangle->color_remplissage= color_init();
            break;
        case 4:
                rotate_shape(rectangle->rectangle->transform);
                break;
        case 5:
                translate_shape(rectangle->rectangle->transform);
                break;
        case 6:
                square_inversion(rectangle->rectangle);
                break;
        case 7:
                printf("enter new width:\n");
                scanf("%d", &input_user);
                clear_stdin();
                rectangle->rectangle->width = input_user;
                break;
        case 8:
                printf("enter new width:\n");
                scanf("%d", &input_user);
                clear_stdin();
                rectangle->rectangle->height = input_user;
                break;
        default:
            printf("invalid input\n");
            break;
        }
        input_user = 0;
    }
    return (rectangle->rectangle);
}

/**
 * @brief Displays an interactive menu to modify properties of a square.
 * 
 * Allows modifying the start point, stroke color, fill color, rotation, translation, 
 * inversion, and width (which dynamically updates the height).
 * 
 * @param square Pointer to the `Figure` union/structure containing the square.
 * @return rectangle_s* Pointer to the modified square structure.
 */
rectangle_s  *modify_square(Figure *square){
    int input_user;
    while (1)
    {
        system("clear");
        print_square(square->rectangle);
        printf("   -------------------------------------------------\n");
        printf("||select 0 ❌ to quit                             ||\n");
        printf("||select 1 to modify start point                  ||\n");
        printf("||select 2 to modify strok color                  ||\n");
        printf("||select 3 to modify the fill color               ||\n");
        printf("||select 4 to rotate                              ||\n");
        printf("||select 5 to translate                           ||\n");
        printf("||select 6 for inversion x or y                   ||\n");
        printf("||select 7 to change width                        ||\n");
        printf(" ---------------------------------------------------\n");
        scanf("%d",&input_user);
        clear_stdin();
        switch (input_user)
        {
        case 0:
            return (square->rectangle);
            break;
        case 1:
            add_new_point(square->rectangle->a);
            break;
        case 2:
            free(square->rectangle->color_bord);
            square->rectangle->color_bord = color_init();
            break;
        case 3:
            free(square->rectangle->color_remplissage);
            square->rectangle->color_remplissage= color_init();
            break;
        case 4:
            rotate_shape(square->rectangle->transform);
            break;
        case 5:
                translate_shape(square->rectangle->transform);
                break;
        case 6:
                square_inversion(square->rectangle);
                break;
        case 7:
                printf("enter new width:\n");
                scanf("%d", &input_user);
                clear_stdin();
                square->rectangle->width = input_user;
                square->rectangle->height =  square->rectangle->width;
                break;
        default:
            printf("invalid input\n");
            break;
        }
        input_user = 0;
    }
    return (square->rectangle);
}

/**
 * @brief Inverts a line's start and end points along the X or Y axis based on user selection.
 * 
 * @param line Pointer to the `line_s` structure representing the line.
 * @return line_s* Pointer to the modified line.
 */
line_s  *line_inversion(line_s *line){
    int input_user = 0;

    printf("\n");
    printf("||select 0 ❌ to quit    ||\n");
    printf("||select 1 for x         ||\n");
    printf("||select 2 for y         ||\n");
    printf("\n");
    scanf("%d",&input_user);
    clear_stdin();
    switch (input_user)
    {
    case 0:
        return line;
        break;
    case 1:
        line->a->x = -line->a->x;
        line->b->x = -line->b->x;
        return line;
        break;
    case 2:
        line->a->y = -line->a->y;
        line->b->y = -line->b->y;
        return line;
        break;
    default:
        break;
    }
    return line;
}

/**
 * @brief Displays an interactive menu to modify properties of a line.
 * 
 * Allows modifying the first point, second point, color, rotation, inversion, and translation.
 * 
 * @param line Pointer to the `Figure` union/structure containing the line.
 * @return Figure* Pointer to the modified figure.
 */
Figure  *modify_line(Figure *line){
    int input_user = 0;
    while (1)
    {
        system("clear");
        print_line(line->line);
        printf(" \n--------------------------------------------------\n");
        printf("||select 0 ❌ to quit                             ||\n");
        printf("||select 1 to modify the first point              ||\n");
        printf("||select 2 to modify the secound                  ||\n");
        printf("||select 3 to modify the color                    ||\n");
        printf("||select 4 to rotate                              ||\n");
        printf("||select 5 for inversion x or y                   ||\n");
        printf("||select 6 to translate                           ||\n");
        printf(" ---------------------------------------------------\n");
        scanf("%d",&input_user);
        clear_stdin();
        switch (input_user)
        {
        case 0:
            return (line);
            break;
        case 1:
            add_new_point(line->line->a);
            break;
        case 2:
            add_new_point(line->line->b);
            break;
        case 3:
            free(line->line->color);
            line->line->color = color_init();
            break;
        case 4:
            rotate_shape(line->line->transform);
            break;
        case 5:
            line->line = line_inversion(line->line);
            break;
        case 6:
            translate_shape(line->line->transform);
            break;
        default:
            printf("invalid input\n");
            break;
        }
        input_user = 0;
    }
}

/**
 * @brief Inverts an ellipse's anchor point along the X or Y axis based on user selection.
 * 
 * @param elipse Pointer to the `elipse_s` structure representing the ellipse.
 * @return elipse_s* Pointer to the modified ellipse.
 */
elipse_s  *elipse_inversion(elipse_s *elipse){
    int input_user = 0;

    printf("\n");
    printf("||select ❌ 0 to quit    ||\n");
    printf("||select 1 for x         ||\n");
    printf("||select 2 for y         ||\n");
    printf("\n");
    scanf("%d",&input_user);
    clear_stdin();
    switch (input_user)
    {
    case 0:
        return elipse;
        break;
    case 1:
        elipse->a->x = -elipse->a->x;
        return elipse;
        break;
    case 2:
        elipse->a->y = -elipse->a->y;
        return elipse;
        break;
    default:
        break;
    }
    return elipse;
}

/**
 * @brief Displays an interactive menu to modify properties of an ellipse.
 * 
 * Allows modifying the center point, stroke color, fill color, rotation, translation, 
 * inversion, and radii.
 * 
 * @param elipse Pointer to the `Figure` union/structure containing the ellipse.
 * @return elipse_s* Pointer to the modified ellipse structure.
 */
elipse_s  *modify_elipse(Figure *elipse){
    int input_user;
    while (1)
    {
        system("clear");
        print_ellipse(elipse->elipse);
        printf("   -------------------------------------------------\n");
        printf("||select 0 ❌ to quit                             ||\n");
        printf("||select 1 to modify the center                   ||\n");
        printf("||select 2 to modify strok color                  ||\n");
        printf("||select 3 to modify the fill color               ||\n");
        printf("||select 4 to rotate                              ||\n");
        printf("||select 5 to translate                           ||\n");
        printf("||select 6 for inversion x or y                   ||\n");
        printf("||select 7 to modify radius 1                     ||\n");
        printf("||select 8 to modify radius 2                     ||\n");
        printf(" ---------------------------------------------------\n");
        scanf("%d",&input_user);
        clear_stdin();
        switch (input_user)
        {
        case 0:
            return (elipse->elipse);
            break;
        case 1:
            add_new_point(elipse->elipse->a);
            break;
        case 2:
                free(elipse->elipse->color_bord);
                elipse->elipse->color_bord = color_init();
            break;
        case 3:
                free(elipse->elipse->color_remplissage);
                elipse->elipse->color_remplissage= color_init();
                break;
        case 4:
                rotate_shape(elipse->elipse->transform);
                break;
        case 5:
                translate_shape(elipse->elipse->transform);
                break;
        case 6:
                elipse_inversion(elipse->elipse);
                break;
        case 7:
                printf("enter the new radius\n");
                scanf("%d", &input_user);
                clear_stdin();
                elipse->circle->r = input_user;
                break;
        case 8:
                printf("enter the new radius\n");
                scanf("%d", &input_user);
                clear_stdin();
                elipse->circle->r = input_user;
                break;
        default:
            printf("invalid input\n");
            break;
        }
        input_user = 0;
    }
    return (elipse->elipse);
}

/**
 * @brief Inverts a circle's center point along the X or Y axis based on user selection.
 * 
 * @param circle Pointer to the `circle_s` structure representing the circle.
 * @return circle_s* Pointer to the modified circle.
 */
circle_s  *circle_inversion(circle_s *circle){
    int input_user = 0;

    printf("\n");
    printf("||select 0 to quit       ||\n");
    printf("||select 1 for x         ||\n");
    printf("||select 2 for y         ||\n");
    printf("\n");
    scanf("%d",&input_user);
    clear_stdin();
    switch (input_user)
    {
    case 0:
        return circle;
        break;
    case 1:
        circle->a->x = -circle->a->x;
        return circle;
        break;
    case 2:
        circle->a->y = -circle->a->y;
        return circle;
        break;
    default:
        break;
    }
    return circle;
}


/**
 * @brief Displays an interactive menu to modify properties of a circle.
 * 
 * Allows modifying the center point, stroke color, fill color, rotation, translation, 
 * inversion, and radius.
 * 
 * @param circle Pointer to the `Figure` union/structure containing the circle.
 * @return circle_s* Pointer to the modified circle structure.
 */
circle_s  *modify_circle(Figure *circle){
    int input_user;
    while (1)
    {
        system("clear");
        print_circle(circle->circle);
        printf("   -------------------------------------------------\n");
        printf("||select 0 ❌ to quit                             ||\n");
        printf("||select 1 to modify the center                   ||\n");
        printf("||select 2 to modify strok color                  ||\n");
        printf("||select 3 to modify the fill color               ||\n");
        printf("||select 4 to rotate                              ||\n");
        printf("||select 5 to translate                           ||\n");
        printf("||select 6 for inversion x or y                   ||\n");
        printf("||select 7 to modify radius                       ||\n");
        printf(" ---------------------------------------------------\n");
        scanf("%d",&input_user);
        clear_stdin();
        switch (input_user)
        {
        case 0:
            return (circle->circle);
            break;
        case 1:
            add_new_point(circle->circle->a);
            break;
        case 2:
                free(circle->circle->color_bord);
                circle->circle->color_bord = color_init();
            break;
        case 3:
                free(circle->circle->color_remplissage);
                circle->circle->color_remplissage= color_init();
                break;
        case 4:
                rotate_shape(circle->circle->transform);
                break;
        case 5:
                translate_shape(circle->circle->transform);
                break;
        case 6:
                circle_inversion(circle->circle);
                break;
        case 7:
                printf("enter the new radius\n");
                scanf("%d", &input_user);
                clear_stdin();
                circle->circle->r = input_user;
                break;
        default:
            printf("invalid input\n");
            break;
        }
        input_user = 0;
    }
    return (circle->circle);
}

/**
 * @brief Inverts all points of a polyline along the X or Y axis based on user selection.
 * 
 * @param polyline Pointer to the `polyline_s` structure to be inverted.
 */
void    inversion_polyline(polyline_s *polyline){
    poly_point_s    *temp = polyline->node;

       int input_user = 0;

    printf("\n");
    printf("||select 1 for x         ||\n");
    printf("||select 2 for y         ||\n");
    printf("\n");
    scanf("%d",&input_user);
    clear_stdin();
    switch (input_user){
        case 1:
            while (temp != NULL)
            {
                temp->point->x = -temp->point->x;
                temp = temp->next;
            }
            break;
        case 2:
            while (temp != NULL)
            {
                temp->point->y = -temp->point->y;
                temp = temp->next;
            }
            break;
        default:
            break;
    }
}

/**
 * @brief Displays an interactive menu to modify properties of a polyline or polygon.
 * 
 * Allows modifying the stroke color, fill color, translation, inversion, and rotation.
 * 
 * @param polyline Pointer to the `Figure` union/structure containing the polyline.
 * @return polyline_s* Pointer to the modified polyline structure.
 */
polyline_s  *modify_polyline(Figure *polyline){
    int input_user;
    while (1){
        system("clear");
        print_polyline(polyline->polyline);
        printf("   -------------------------------------------------\n");
        printf("||select 0 ❌ to quit                             ||\n");
        printf("||select 1 to modify strok color                  ||\n");
        if (polyline->polyline->color_fill)
            printf("||select 2 to modify the fill color               ||\n");
        printf("||select 3 to translate                           ||\n");
        printf("||select 4 for inversion x or y                   ||\n");
        printf("||select 5 to rotate                              ||\n");
        printf(" ---------------------------------------------------\n");
        scanf("%d",&input_user);
        clear_stdin();
        switch (input_user){
            case 0:
                return (polyline->polyline);
                break;
            case 1:
                free(polyline->polyline->color);                
                polyline->polyline->color = color_init();
                break;
            case 2:
                if (polyline->polyline->color_fill){
                    free(polyline->polyline->color_fill);
                    polyline->polyline->color_fill = color_init();
                }
                break;
            case 3:
                translate_shape(polyline->polyline->transform);
                break;
            case 4:
                inversion_polyline(polyline->polyline);
                break;
            case 5:
                rotate_shape(polyline->polyline->transform);
                break;
            default:
                break;
        }
    }
}

/**
 * @brief Selects a shape from the list based on index and routes it to the correct shape-specific modification function.
 * 
 * @param list Pointer to the `list_s` structure containing all shapes.
 * @param user_input 1-indexed identifier of the shape to modify.
 * @return list_s* Pointer to the updated list.
 */
list_s *modify_shape_selected(list_s *list, int user_input){
    node_s *temp = list->node;
    int i = 0;

    while(i < user_input - 1){
        temp = temp->next;
        i++;
    }
    switch (temp->type){
        case LINE:
            temp->figure = modify_line(temp->figure);
            break;
        case CIRCLE:
            temp->figure->circle = modify_circle(temp->figure);
            break;
        case SQUARE:
            temp->figure->rectangle = modify_square(temp->figure);
            break;
        case RECTANGLE:
            temp->figure->rectangle = modify_rectangle(temp->figure);
            break;
        case ELLIPSE:
            temp->figure->elipse = modify_elipse(temp->figure);
            break;
        case POLYLINE:
            temp->figure->polyline = modify_polyline(temp->figure);
            break;
        case POLYGONE:
            temp->figure->polyline = modify_polyline(temp->figure);
            break;
        default :
            break;
    }
    return list;
}

/**
 * @brief Prompts the user for a shape number and removes it from the list.
 * 
 * @param list Pointer to the `list_s` structure from which the shape will be deleted.
 */
void    delete_shape(list_s* list){
    int input_user = 0;
    printf("enter the number of shape you want to delete\n");
    scanf("%d", &input_user);
    clear_stdin();
    if (input_user > 0 && input_user <= (int)list->length)
        supp_node(list, input_user - 1);
}

/**
 * @brief Displays the main shape management menu, printing all figures and handling user selection for modification or deletion.
 * 
 * @param list Pointer to the `list_s` structure containing all shapes.
 * @return int Returns `0` on exit, or `1` if the shape list is empty.
 */
int modify_forme(list_s *list){
    int count_line;
    int count_circle;
    int count_ellipse;
    int count_rectangle;
    int count_square;
    int count_polyline;
    int count_polygone;
    int i;
    int user_input;
    node_s *temp = list->node;

    if (list->node == NULL)
        return (1);
    while (1){
        system("clear");
        count_line = 1;
        count_circle = 1;
        count_square = 1;
        count_rectangle = 1;
        count_ellipse = 1;
        count_polygone = 1;
        count_polyline = 1;
        i = 1;
        printf(GREEN "        ┌─────────────────────────────────────────┐\n" RESET);
        printf(GREEN "        │              🎨 SVG EDITOR              │\n" RESET);
        printf(GREEN "        └─────────────────────────────────────────┘\n\n" RESET);
        printf(" ---------------------------------------------------\n");
        printf("to select the element you want please selecte a number between 0 and %d\n\n", list->length);
        printf("0  ❌ to quit\n");
        printf("\n-1 to delete a shape\n\n");
        while (temp){
            switch (temp->type)
            {
                case LINE:
                    printf("select %d, to line 📏 number %d\n", i , count_line);
                    print_line(temp->figure->line);
                    i++;
                    count_line++;
                break;
                case CIRCLE:
                    printf("select %d, to circle 🔵 number %d\n", i, count_circle);
                    print_circle(temp->figure->circle);
                    i++;
                    count_circle++;
                break;
                case ELLIPSE:
                    printf("select %d, to ellipse 🟠 number %d\n", i, count_ellipse);
                    print_ellipse(temp->figure->elipse);
                    i++;
                    count_ellipse++;
                break;
                case RECTANGLE:
                    printf("select %d, to rectangle 🟦 number %d\n", i, count_rectangle);
                    print_rectangle(temp->figure->rectangle);
                    i++;
                    count_rectangle++;
                break;
                case SQUARE:
                    printf("select %d, to square ⬛ number %d\n", i, count_square);
                    print_square(temp->figure->rectangle);
                    i++;
                    count_square++;
                break;
                case POLYLINE:
                    printf("select %d, to polyline 〰️ number %d\n", i, count_polyline);
                    print_polyline(temp->figure->polyline);
                    count_polyline++;
                    break;
                case POLYGONE:
                    printf("select %d, to polygone ⬡ number %d\n", i, count_polygone);
                    print_polyline(temp->figure->polyline);
                    count_polygone++;
                    break;
                default :
                    break;
            }
            temp = temp->next;
        }
        printf(" ---------------------------------------------------\n");
        scanf("%d", &user_input);
        clear_stdin();
        if (user_input > (int)list->length +1 && user_input > 0)
            printf(GRAS ROUGE "invalid input\n" RESET);
        else if(user_input == 0)
            return 0;
        else if(user_input == -1)
            delete_shape(list);
        else
            modify_shape_selected(list, user_input);
        temp = list->node;
    }
    return 0;
}
