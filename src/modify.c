#include "../projet_svg.h"


line_s  *modify_line(line_s *line){
    int input_user;
    while (1)
    {
        printf("select 0 to quit\n");
        printf("select 1 to modify the first point\n");
        printf("select 2 to modify the secound\n");
        printf("select 3 to modify the color\n");
        scanf("%d",&input_user);
        clear_stdin();
        switch (input_user)
        {
        case 0:
            return (line);
            break;
        case 1:
            add_new_point(line->a);
            break;
        case 2:
            add_new_point(line->b);
            break;
        case 3:
            free(line->color);
            line->color = color_init();
            break;
        default:
            printf("invalid input\n");
            break;
        }
        input_user = 0;
    }
}


circle_s  *modify_circle(circle_s *circle){
    int input_user;
    while (1)
    {
        printf("select 0 to quit\n");
        printf("select 1 to modify the center\n");
        printf("select 2 to modify contour color\n");
        printf("select 3 to modify the fill colorn");
        scanf("%d",&input_user);
        clear_stdin();
        switch (input_user)
        {
        case 0:
            return (circle);
            break;
        case 1:
            add_new_point(circle->a);
            break;
        case 2:
                free(circle->color_bord);
                circle->color_bord = color_init();
            break;
        case 3:
                free(circle->color_remplissage);
                circle->color_remplissage= color_init();
            break;
        default:
            printf("invalid input\n");
            break;
        }
        input_user = 0;
    }
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
            temp->figure->line = modify_line(temp->figure->line);
            break;
        case CIRCLE:
            temp->figure->circle = modify_circle(temp->figure->circle);
            break;    
    }
    return list;
}

int modify_forme(list_s *list){
    int count_line;
    int count_circle;
    int i;
    unsigned int user_input;
    node_s *temp = list->node;

    if (list->node == NULL){
        printf("nothing to modify\n");
        return (0);
    }
    while (1){
        count_line = 1;
        count_circle = 1;
        i = 1;
        printf("to select the element you want please selecte a number (order of creation) between 0 and %d\n", list->length);
        printf("0 to quit\n");
        while (temp){
            switch (temp->type)
            {
                case LINE:
                    printf("select %d, for line number %d\n", i , count_line);
                    i++;
                    count_line++;
                break;
                case CIRCLE:
                    printf("select %d, for circle numbre %d\n", i, count_circle);
                    i++;
                    count_circle++;
                break;
            }
            i++;
            temp = temp->next;
        }
        scanf("%d", &user_input);
        clear_stdin();
        if (user_input > list->length +1 && user_input > 0)
            printf("invalid input");
        else if(user_input == 0)
            return 0;
        else
            modify_shape_selected(list, user_input);
        temp = list->node;
    }
    return 0;
}