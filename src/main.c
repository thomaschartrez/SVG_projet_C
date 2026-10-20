#include "../include/projet_svg.h"


void clear_stdin(void)
{
    char c = 'a';

    while (c != '\n' && c!=EOF)
        c = getc(stdin);
}

int main(void){
    unsigned char i = 1;
    list_s *list;

    list = init_list();
    while(1){
        system("clear");
        if (i == 0)
            printf(GREEN"nothing to modify\n"RESET);
        printf("    ---------------------------------------------------\n");
        printf("    ||               0 : for quit                    ||\n");
        printf("    ||               1 : for create                  ||\n");
        printf("    ||               2 : for modify                  ||\n");
        printf("    ||               3 : for upload                  ||\n");
        printf("    ||               4 : pour charge et visualiser   ||\n");
        printf("    ||               5 : save                        ||\n");
        printf("    ---------------------------------------------------\n");
        scanf("%hhd", &i);
        clear_stdin();
        if (i == 0){
            free_list(list);
            return 0;
        }
        if (i == 1)
            add_new_forme(list);
        if (i == 2){
            if (modify_forme(list))
                i = 0;
        }
        if (i == 3)
            list = get_save(list);
        if (i == 4)
            add_to_file(list);     
        if (i == 5)
            creat_save(list);
    }
    free_list(list);
    return 0;
}
