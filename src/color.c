#include "../projet_svg.h"

int color_is_exa(char *color){
    int i = 0;

    while(i < 6){
        if ((color[i] < '0' || color[i] > '9') && (color[i] < 'a' || color[i] > 'f') && (color[i] < 'A' || color[i] > 'F'))
            return 0;
        i++;
    }
    return 1;
}

char *color_init(void){
    char *color;
    int i = 1;

    color = malloc(sizeof(char)* 7);
    while (i){
        i = 0;
        printf("entree la couleur format exadecimal ex : FF00FF\n");
        scanf("%6s", color);
        clear_stdin();
        if(strlen(color) != 6){
            printf("format de couleur entrée non valide\n");
            i = 1;
        }
        if (i == 0 && color_is_exa(color) == 0){
            printf("format de couleur entrée non valide\n");
            i = 1;
        }
    }
    return (color);
}
