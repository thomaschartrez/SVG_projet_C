#include "projet_svg.h"

int    add_new_forme(void){
    FILE *a = fopen("dsoformer.html", "w");
    if (a == NULL)
        return (1);
    fprintf(a, "<svg viewBox=\"0 0 100 100\" xmlns=\"http://www.w3.org/2000/svg\">\n<line x1=\"0\" y1=\"80\" x2=\"100\" y2=\"20\" stroke=\"black\" />\n</svg>\n");
    fclose(a);
    return 0;
}
