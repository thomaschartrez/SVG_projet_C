#include "../projet_svg.h"



point_s *inversion_point(point_s *point){
    point->x = -point->x;
    point->y = -point->y;
    return (point);
}


void    inversion_shape(Figure *shape, Forme type){
    switch (type)
    {
    case CIRCLE:
        shape->circle->a = inversion_point(shape->circle->a);
        break;
    case LINE:
        shape->line->a = inversion_point(shape->line->a);
        shape->line->b = inversion_point(shape->line->b);
        break;
    default:
        break;
    }
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

Figure  *modify_line(Figure *line){
    int input_user;
    while (1)
    {
        system("clear");
        print_line(line->line);
        printf(" \n--------------------------------------------------\n");
        printf("||select 0 to quit                               ||\n");
        printf("||select 1 to modify the first point             ||\n");
        printf("||select 2 to modify the secound                 ||\n");
        printf("||select 3 to modify the color                   ||\n");
        printf("||select 4 to rotate                             ||\n");
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
            
        default:
            printf("invalid input\n");
            break;
        }
        input_user = 0;
    }
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

circle_s  *modify_circle(Figure *circle){
    int input_user;
    while (1)
    {
        system("clear");
        print_circle(circle->circle);
        printf("\n ---------------------------------------------------\n");
        printf("||select 0 to quit                                ||\n");
        printf("||select 1 to modify the center                   ||\n");
        printf("||select 2 to modify contour color                ||\n");
        printf("||select 3 to modify the fill colorn              ||\n");
        printf("||select 4 to rotate\n                            ||\n");
        printf("||select 5 to translate                           ||\n");
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
                inversion_shape(circle ,CIRCLE);
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
        default :
            break;

    }
    return list;
}

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