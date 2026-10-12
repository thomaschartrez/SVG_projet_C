#include "../projet_svg.h"


int main(void){
    unsigned char i;
    
    while(1){
        printf("0 : pour quitter\n");
        printf("1 : pour creer\n");
        printf("2 : pour editer\n");
        printf("3 : pour sauver\n");
        printf("4 : pour charge et visualiser\n");
        scanf("%hhd", &i);
        if (i == 0)
            return 0;
        if (i == 1)
            add_new_forme();
        printf("%d\n", i);
    }
}
