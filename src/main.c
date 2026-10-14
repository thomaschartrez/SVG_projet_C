#include "../projet_svg.h"


void clear_stdin(void)
{
    char c = 'a';

    while (c != '\n' && c!=EOF)
        c = getc(stdin);
}

int main(void){
    unsigned char i = 0;
    list_s *list;

    clear_stdin();
    list = init_list();
    while(1){
        printf("0 : for quit\n");
        printf("1 : for create\n");
        printf("2 : for modify\n");
        printf("3 : for save\n");
        printf("4 : pour charge et visualiser\n");
        scanf("%hhd", &i);
        clear_stdin();
        if (i == 0){
            free_list(list);
            return 0;
        }
        if (i == 1)
            add_new_forme(list);
        if (i == 2)
            modify_forme(list);
        if (i == 3)
            add_to_file(list);     
    }
    free_list(list);
    return 0;
}
