#include "../include/projet_svg.h"


rectangle_s *rotate_square(rectangle_s *square){
    int temp;
    
    while(1){
        temp = 0;
        printf("enter an interger for the rotation dont use 0 to quit use 360 :)\n");
        scanf("%d", &temp);
        clear_stdin();
        if(temp != 0){
            square->transform->rotate += temp;
            return(square);
        }
    }
}

rectangle_s *translate_square(rectangle_s *square){
    int x_coordinate = 0;
    int y_coordinate = 0;

    
    printf("enter the x-coordinate\n");
    scanf("%d", &x_coordinate);
    clear_stdin();
    square->transform->x = square->transform->x + x_coordinate;
    printf("enter the y-coordinate\n");
    scanf("%d", &y_coordinate);
    square->transform->y = square->transform->y + y_coordinate;
    clear_stdin();
    return (square);
}

rectangle_s  *square_inversion(rectangle_s *square){
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

rectangle_s  *modify_rectangle(Figure *rectangle){
    int input_user;
    while (1)
    {
        system("clear");
        print_square(rectangle->rectangle);
        printf("   -------------------------------------------------\n");
        printf("||select 0 to quit                                ||\n");
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
                rectangle->rectangle = rotate_square(rectangle->rectangle);
                break;
        case 5:
                rectangle->rectangle = translate_square(rectangle->rectangle);
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

rectangle_s  *modify_square(Figure *square){
    int input_user;
    while (1)
    {
        system("clear");
        print_square(square->rectangle);
        printf("   -------------------------------------------------\n");
        printf("||select 0 to quit                                ||\n");
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
            square->rectangle = rotate_square(square->rectangle);
            break;
        case 5:
                square->rectangle = translate_square(square->rectangle);
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

line_s *rotate_line(line_s *line){
    int temp;
    
    while(1){
        temp = 0;
        printf("enter an interger for the rotation dont use 0 to quit use 360 :)\n");
        scanf("%d", &temp);
        clear_stdin();
        if(temp != 0){
            line->transform->rotate += temp;
            return(line);
        }
    }
}

line_s  *line_inversion(line_s *line){
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

Figure  *modify_line(Figure *line){
    int input_user = 0;
    while (1)
    {
        system("clear");
        print_line(line->line);
        printf(" \n--------------------------------------------------\n");
        printf("||select 0 to quit                                ||\n");
        printf("||select 1 to modify the first point              ||\n");
        printf("||select 2 to modify the secound                  ||\n");
        printf("||select 3 to modify the color                    ||\n");
        printf("||select 4 to rotate                              ||\n");
        printf("||select 5 for inversion x or y                   ||\n");
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
            line->line = rotate_line(line->line);
            break;
        case 5:
            line->line = line_inversion(line->line);
            break;
        default:
            printf("invalid input\n");
            break;
        }
        input_user = 0;
    }
}

elipse_s *rotate_elipse(elipse_s *elipse){
    int temp;
    
    while(1){
        temp = 0;
        printf("enter an interger for the rotation dont use 0 to quit use 360 :)\n");
        scanf("%d", &temp);
        clear_stdin();
        if(temp != 0){
            elipse->transform->rotate += temp;
            return(elipse);
        }
    }
}

elipse_s *translate_elipse(elipse_s *elipse){
    int x_coordinate = 0;
    int y_coordinate = 0;

    
    printf("enter the x-coordinate\n");
    scanf("%d", &x_coordinate);
    clear_stdin();
    elipse->transform->x += x_coordinate;
    printf("enter the y-coordinate\n");
    scanf("%d", &y_coordinate);
    elipse->transform->y += y_coordinate;
    clear_stdin();
    return (elipse);
}

elipse_s  *elipse_inversion(elipse_s *elipse){
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

elipse_s  *modify_elipse(Figure *elipse){
    int input_user;
    while (1)
    {
        system("clear");
        print_ellipse(elipse->elipse);
        printf("   -------------------------------------------------\n");
        printf("||select 0 to quit                                ||\n");
        printf("||select 1 to modify the center                   ||\n");
        printf("||select 2 to modify strok color                  ||\n");
        printf("||select 3 to modify the fill colorn              ||\n");
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
                elipse->elipse = rotate_elipse(elipse->elipse);
                break;
        case 5:
                elipse->elipse = translate_elipse(elipse->elipse);
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

circle_s *rotate_circle(circle_s *circle){
    int temp;
    
    while(1){
        temp = 0;
        printf("enter an interger for the rotation dont use 0 to quit use 360 :)\n");
        scanf("%d", &temp);
        clear_stdin();
        if(temp != 0){
            circle->transform->rotate += temp;
            return(circle);
        }
    }
}

circle_s *translate_circle(circle_s *circle){
    int x_coordinate = 0;
    int y_coordinate = 0;

    
    printf("enter the x-coordinate\n");
    scanf("%d", &x_coordinate);
    clear_stdin();
    circle->transform->x += x_coordinate;
    printf("enter the y-coordinate\n");
    scanf("%d", &y_coordinate);
    circle->transform->y += y_coordinate;
    clear_stdin();
    return (circle);
}

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

circle_s  *modify_circle(Figure *circle){
    int input_user;
    while (1)
    {
        system("clear");
        print_circle(circle->circle);
        printf("   -------------------------------------------------\n");
        printf("||select 0 to quit                                ||\n");
        printf("||select 1 to modify the center                   ||\n");
        printf("||select 2 to modify strok color                  ||\n");
        printf("||select 3 to modify the fill colorn              ||\n");
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
                circle->circle = rotate_circle(circle->circle);
                break;
        case 5:
                circle->circle = translate_circle(circle->circle);
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
        default :
            break;
    }
    return list;
}

int modify_forme(list_s *list){
    int count_line;
    int count_circle;
    int count_ellipse;
    int count_rectangle;
    int count_square;
    int i;
    unsigned int user_input;
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
        i = 1;
        printf(" ---------------------------------------------------\n");
        printf("to select the element you want please selecte a number (order of creation) between 0 and %d\n\n", list->length);
        printf("0 to quit\n");
        while (temp){
            switch (temp->type)
            {
                case LINE:
                    printf("select %d, for line number %d\n", i , count_line);
                    print_line(temp->figure->line);
                    i++;
                    count_line++;
                break;
                case CIRCLE:
                    printf("select %d, for circle number %d\n", i, count_circle);
                    print_circle(temp->figure->circle);
                    i++;
                    count_circle++;
                break;
                case ELLIPSE:
                    printf("select %d, for ellipse number %d\n", i, count_circle);
                    print_ellipse(temp->figure->elipse);
                    i++;
                    count_ellipse++;
                break;
                case RECTANGLE:
                    printf("select %d, for rectangle number %d\n", i, count_circle);
                    print_rectangle(temp->figure->rectangle);
                    i++;
                    count_rectangle++;
                break;
                case SQUARE:
                    printf("select %d, for square number %d\n", i, count_circle);
                    print_square(temp->figure->rectangle);
                    i++;
                    count_square++;
                break;
                default :
                    break;

            }
            temp = temp->next;
        }
        printf(" ---------------------------------------------------\n");
        scanf("%d", &user_input);
        clear_stdin();
        if (user_input > list->length +1 && user_input > 0)
            printf(GRAS ROUGE "invalid input\n" RESET);
        else if(user_input == 0)
            return 0;
        else
            modify_shape_selected(list, user_input);
        temp = list->node;
    }
    return 0;
}
