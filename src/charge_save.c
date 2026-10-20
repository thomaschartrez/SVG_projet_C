#include "../include/projet_svg.h"

int   *get_int(FILE *file, int *return_val){
    char BUFFER[2];
    int nb;
    int signe = 1;

    return_val[0] = 0;
    return_val[1] = 0;
    if( fgets(BUFFER, 2, file) == NULL){
        return_val[0] = -1;
        return return_val;
    }
    if (BUFFER[0] == '-')
    {
        signe = -1;
        if( fgets(BUFFER, 2, file) == NULL){
            return_val[0] = -1;
            return return_val;
        }
        if(BUFFER[0] == ','){
            return_val[0] = -1;
            return return_val;
        }
        if (BUFFER[0] < '0' || BUFFER[0] > '9'){
            return_val[0] = -1;
            return return_val;
        }
    }
    nb = BUFFER[0] - '0';
    while(1){
        if( fgets(BUFFER, 2, file) == NULL){
            return_val[0] = -1;
            return return_val;
        }
        if(BUFFER[0] == ','){
            return_val[1] = nb * signe;
            return return_val;
        }
        if (BUFFER[0] < '0' || BUFFER[0] > '9'){
            return_val[0] = -1;
            return return_val;
        }
        nb = nb *10 + (BUFFER[0] - '0');
    }
}

char    *get_color(FILE *file){
    char BUFFER[8];

    if( fgets(BUFFER, 8, file) == NULL)
        return NULL;
    if (strlen(BUFFER) != 7)
        return NULL;
    for(int i = 0; i < 6;i++){
        if ((BUFFER[i] < '0' || BUFFER[i] > '9') && (BUFFER[i] < 'a' || BUFFER[i] > 'f') && (BUFFER[i] < 'A' || BUFFER[i] > 'F'))
            return NULL;
    }
    if (BUFFER[6] != ',')
            return NULL;
    char *color = malloc(sizeof(char)* 7);
    for(int i = 0; i < 6;i++){
        color[i] = BUFFER[i];
    }
    color[6] = '\0';
    return color;
}

point_s   *get_point(FILE *file){
    point_s *point = malloc(sizeof(point_s));
    int *temp = malloc(sizeof(int) * 2);


    temp = get_int(file, temp);
    if(temp[0] < 0){
        free(temp);
        free(point);
        return NULL;
    }
    point->x = temp[1];
    temp = get_int(file, temp);
    if(temp[0] < 0){
        free(temp);
        free(point);
        return NULL;
    }
    point->y = temp[1];
    free(temp);
    return point;
}

transform_s   *get_translation_rotation(FILE *file){
    transform_s *transform = malloc(sizeof(transform_s));
    int *temp = malloc(sizeof(int) * 2);



    temp = get_int(file, temp);
    if(temp[0] < 0){
        free(transform);
        free(temp);
        return NULL;
    }
    transform->rotate = temp[1];
    temp = get_int(file, temp);
    if(temp[0] < 0){
        free(temp);
        free(transform);
        return NULL;
    }
    transform->x = temp[1];
    temp = get_int(file, temp);
    if(temp[0] < 0){
        free(temp);
        free(transform);
        return NULL;
    }
    transform->y = temp[1];
    free(temp);
    return transform;
}

void    go_end_line(FILE *file);

list_s    *read_option_rectangle(FILE *file,char *option, list_s *new_list){
    int p = 0;
    int w = 0;
    int h = 0;
    int c = 0;
    int t = 0;
    int *temp;

    for (int i = 0; i < 6; i++){
        if(option[i] == 'p')
            p++;
        if(option[i] == 'w')
            w++;
        if(option[i] == 'h')
            h++;
        if(option[i] == 'c')
            c++;
        if(option[i] == 't')
            t++;
    }
    if(p != 1 || c!= 2 || w != 1 || t != 1 || h != 1){
        go_end_line(file);
        return (new_list);
    }
    rectangle_s *square = malloc(sizeof(rectangle_s));
    square->a = NULL;
    square->color_bord = NULL;
    square->color_remplissage = NULL;
    square->transform = NULL;
    c = 0;
    temp = malloc(sizeof(int)* 2);
    for (int i = 0; i < 6; i++){
        switch (option[i])
        {
        case 'p':
            square->a = get_point(file);
            if (!square->a){
                free_rectangle(square);
                free(temp);
                return(new_list);
            }
            break;
        case 't':
            square->transform = get_translation_rotation(file);
            if (square->transform == NULL){
                free_rectangle(square);
                free(temp);
                return(new_list);
            }
            break;
        case 'c':
            if(c == 0){
                square->color_bord = get_color(file);
                if (!square->color_bord){
                    free_rectangle(square);
                    free(temp);
                    return(new_list);
                    }
                    c++;
                }
                else{
                    square->color_remplissage = get_color(file);
                    if (!square->color_remplissage){
                        free_rectangle(square);
                        free(temp);
                        return(new_list);
                    }
                }
                break;
        case 'w':
            temp = get_int(file, temp);
            if (temp[0] < 0){
                free_rectangle(square);
                free(temp);
                return(new_list);
            }
            square->width = temp[1];
            break;
        case 'h':
            temp = get_int(file, temp);
            if (temp[0] < 0){
                free_rectangle(square);
                free(temp);
                return(new_list);
            }
            square->height = temp[1];
            break;
        default:
            break;
        }
    }
    free(temp);
    node_s  *node = init_node_rectangle(RECTANGLE, square);
    add_node(new_list, node);
    return new_list;
}

list_s    *read_option_square(FILE *file,char *option, list_s *new_list){
    int p = 0;
    int w = 0;
    int c = 0;
    int t = 0;
    int *temp;

    for (int i = 0; i < 5; i++){
        if(option[i] == 'p')
            p++;
        if(option[i] == 'w')
            w++;
        if(option[i] == 'c')
            c++;
        if(option[i] == 't')
            t++;
    }
    if(p != 1 || c!= 2 || w != 1 || t != 1){
        go_end_line(file);
        return (new_list);
    }
    rectangle_s *square = malloc(sizeof(rectangle_s));
    square->a = NULL;
    square->color_bord = NULL;
    square->color_remplissage = NULL;
    square->transform = NULL;
    c = 0;
    temp = malloc(sizeof(int)* 2);
    for (int i = 0; i < 5; i++){
        switch (option[i])
        {
        case 'p':
            square->a = get_point(file);
            if (!square->a){
                free_rectangle(square);
                free(temp);
                return(new_list);
            }
            break;
        case 't':
            square->transform = get_translation_rotation(file);
            if (square->transform == NULL){
                free_rectangle(square);
                free(temp);
                return(new_list);
            }
            break;
        case 'c':
            if(c == 0){
                square->color_bord = get_color(file);
                if (!square->color_bord){
                    free_rectangle(square);
                    free(temp);
                    return(new_list);
                    }
                    c++;
                }
                else{
                    square->color_remplissage = get_color(file);
                    if (!square->color_remplissage){
                        free_rectangle(square);
                        free(temp);
                        return(new_list);
                    }
                }
                break;
        case 'w':
            temp = get_int(file, temp);
            if (temp[0] < 0){
                free_rectangle(square);
                free(temp);
                return(new_list);
            }
                square->height = temp[1];
                square->width = temp[1];
            break;
        default:
            break;
        }
    }
    free(temp);
    node_s  *node = init_node_square(SQUARE, square);
    add_node(new_list, node);
    return new_list;
}

list_s    *read_option_circle(FILE *file,char *option, list_s *new_list){
    int p = 0;
    int r = 0;
    int c = 0;
    int t = 0;
    int *temp;

    for (int i = 0; i < 5; i++){
        if(option[i] == 'p')
            p++;
        if(option[i] == 'r')
            r++;
        if(option[i] == 'c')
            c++;
        if(option[i] == 't')
            t++;
    }
    if(p != 1 || c!= 2 || r != 1 || t != 1){
        go_end_line(file);
        return (new_list);
    }
    circle_s *circle = malloc(sizeof(circle_s));
    circle->a = NULL;
    circle->color_bord = NULL;
    circle->color_remplissage = NULL;
    circle->transform = NULL;
    c = 0;
    temp = malloc(sizeof(int)* 2);
    for (int i = 0; i < 5; i++){
        switch (option[i])
        {
        case 'p':
            circle->a = get_point(file);
            if (!circle->a){
                free_circle(circle);
                free(temp);
                return(new_list);
            }
            break;
        case 't':
            circle->transform = get_translation_rotation(file);
            if (circle->transform == NULL){
                free_circle(circle);
                free(temp);
                return(new_list);
            }
            break;
        case 'c':
            if(c == 0){
                circle->color_bord = get_color(file);
                if (!circle->color_bord){
                    free_circle(circle);
                    free(temp);
                    return(new_list);
                    }
                    c++;
                }
                else{
                    circle->color_remplissage = get_color(file);
                if (!circle->color_remplissage){
                    free_circle(circle);
                    free(temp);
                    return(new_list);
                    }
                }
                break;
        case 'r':
            temp = get_int(file, temp);
            if (temp[0] < 0){
                free_circle(circle);
                free(temp);
                return(new_list);
            }
            else
                circle->r = temp[1];
            break;
        default:
            break;
        }
    }
    free(temp);
    node_s  *node = init_node_circle(CIRCLE, circle);
    add_node(new_list, node);
    return new_list;
}

list_s    *read_option_ellipse(FILE *file,char *option, list_s *new_list){
    int p = 0;
    int c = 0;
    int r = 0;
    int t = 0;
    int *temp;

    for (int i = 0; i < 6; i++){
        if(option[i] == 'p')
            p++;
        if(option[i] == 'c')
            c++;
        if(option[i] == 'r')
            r++;
        if(option[i] == 't')
            t++;
    }
    if(p != 1 || c!= 2 || t != 1 || r != 2){
        go_end_line(file);
        return (new_list);
    }
    elipse_s *ellipse = malloc(sizeof(elipse_s));
    ellipse->a = NULL;
    ellipse->color_bord = NULL;
    ellipse->color_remplissage = NULL;
    ellipse->transform = NULL;
    c = 0;
    r = 0;
    temp = malloc(sizeof(int)* 2);
    for (int i = 0; i < 6; i++){
        switch (option[i])
        {
        case 'p':
            ellipse->a = get_point(file);
            if (!ellipse->a){
                free(temp);
                free_ellipse(ellipse);
                return(new_list);
                }
            break;
        case 't':
            ellipse->transform = get_translation_rotation(file);
            if (ellipse->transform == NULL){
                free(temp);
                free_ellipse(ellipse);
                return(new_list);
            }
            break;
        case 'c':
                if (c == 0){
                    ellipse->color_bord = get_color(file);
                    if (!ellipse->color_bord){
                        free(temp);
                        free_ellipse(ellipse);
                        return(new_list);
                    }
                    c++;
                }
                else{
                     ellipse->color_remplissage = get_color(file);
                    if (!ellipse->color_remplissage){
                        free(temp);
                        free_ellipse(ellipse);
                        return(new_list);
                    }
                }
                break;
        case 'r' :
                if (r == 0){
                    temp = get_int(file, temp);
                    if (temp[0] < 0){
                        free(temp);
                        free_ellipse(ellipse);
                        return(new_list);
                    }
                    ellipse->r1 = temp[1];
                    r++;
                }
                else{
                    temp = get_int(file, temp);
                    if (temp[0] < 0){
                        free(temp);
                        free_ellipse(ellipse);
                        return(new_list);
                    }
                    ellipse->r2 = temp[1];
                }
        default:
            break;
        }
    }
    free(temp);
    node_s  *node = init_node_ellipse(ELLIPSE, ellipse);
    add_node(new_list, node);
    return new_list;
}

list_s    *read_option_line(FILE *file,char *option, list_s *new_list){
    int p = 0;
    int c = 0;
    int t = 0;
    int *temp;

    for (int i = 0; i < 4; i++){
        if(option[i] == 'p')
            p++;
        if(option[i] == 'c')
            c++;
        if(option[i] == 't')
            t++;
    }
    if(p != 2 || c!= 1 || t != 1){
        go_end_line(file);
        return (new_list);
    }
    line_s *line = malloc(sizeof(line_s));
    line->a = NULL;
    line->b = NULL;
    line->color = NULL;
    line->transform = NULL;
    p = 0;
    temp = malloc(sizeof(int)* 2);
    for (int i = 0; i < 4; i++){
        switch (option[i])
        {
        case 'p':
            if (p == 0){
                line->a = get_point(file);
                if (!line->a){
                    free(temp);
                    free_line(line);
                    return(new_list);
                }
                p++;
            }
            else{
                line->b = get_point(file);
                if (!line->b){
                    free(temp);
                    free_line(line);
                    return(new_list);
            }
        }
            break;
        case 't':
            line->transform = get_translation_rotation(file);
            if (line->transform == NULL){
                free(temp);
                free_line(line);
                return(new_list);
            }
            break;
        case 'c':
                line->color = get_color(file);
                if (!line->color){
                    free(temp);
                    free_line(line);
                    return(new_list);
                    }
                    c++;
                break;
        default:
            break;
        }
    }
    free(temp);
    node_s  *node = init_node_line(LINE, line);
    add_node(new_list, node);
    return new_list;
}


char    *get_option(FILE *file, int size){
    char    *option;

    option = malloc(sizeof(char) * (size + 2));
    if (fgets(option, size + 2,file) == NULL){
        free(option);
        return (NULL);
    }
    if (option[size] != '|'){
        free(option);
        return (NULL);
    }
    option[size + 1] = '\0';
    return option;
}


void go_end_line(FILE *file) {
    char BUFFER[2];
    BUFFER[0] = ' '; 

    while (BUFFER[0] != '\n') {
        if (fgets(BUFFER, 2, file) == NULL) {
            break; 
        }
    }
}

list_s  *read_save(list_s *old_list,FILE *file){
    list_s *new_list;
    char    *option;
    char    BUFFER[3];

    new_list = init_list();
    while(1){
        if (fgets(BUFFER,3,file) == NULL)
        {
            free_list(old_list);
            return (new_list);
        }
        if(BUFFER[1] != '|')
            BUFFER[0] = 'a';
        switch (BUFFER[0])
        {
        case 'C':
            option = get_option(file, 5);
            if (option == NULL)
               go_end_line(file);
            else{
                new_list = read_option_circle(file, option, new_list);
                go_end_line(file);
                free(option);
            }
            break;
        case 'L':
            option = get_option(file, 4);
            if (option == NULL)
                go_end_line(file);
            else{
                new_list = read_option_line(file, option, new_list);
                go_end_line(file);
                free(option);
            }
            break;
        case 'E':
            option = get_option(file, 6);
            if (option == NULL)
                go_end_line(file);
            else{
                new_list = read_option_ellipse(file, option, new_list);
                go_end_line(file);
                free(option);
            }
            break;
        case 'R':
            option = get_option(file, 6);
            if (option == NULL)
                go_end_line(file);
            else{
                new_list = read_option_rectangle(file, option, new_list);
                go_end_line(file);
                free(option);
            }
            break;
        case 'S':
            option = get_option(file, 5);
            if (option == NULL)
                go_end_line(file);
            else{
                new_list = read_option_square(file, option, new_list);
                go_end_line(file);
                free(option);
            }
            break;
        default:
            go_end_line(file);
            break;
        }
    }
    free_list(old_list);
    return new_list;
}

list_s  *get_save(list_s *list){
    FILE *file;
    char way[51];

    printf("enter the way of the save you want to upload\n");
    scanf("%50s", way);
    clear_stdin();
    file = fopen(way,"r");
    if (file == NULL){
        printf(ROUGE GRAS "wrong input or not read right\n" RESET);
        system("sleep 5");
        return(list);
    }
    list = read_save(list, file);
    fclose(file);
    return (list);
}
