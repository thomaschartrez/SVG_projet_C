#include "../projet_svg.h"


int main(void){
    unsigned char i;
    list_s *list;

    list = init_list();
    while(1){
        printf("0 : for quit\n");
        printf("1 : for create\n");
        printf("2 : pour editer\n");
        printf("3 : for save\n");
        printf("4 : pour charge et visualiser\n");
        scanf("%hhd", &i);
        if (i == 0){
            free_list(list);
            return 0;
        }
        if (i == 1)
            add_new_forme(list);
        if (i == 3)
            add_to_file(list);     
    }
    free_list(list);
    return 0;
}
