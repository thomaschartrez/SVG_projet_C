#include "../projet_svg.h"

int    add_new_forme(void){ 
    line_s *line;
    
    line = malloc(sizeof(line_s));
    line->color = color_init();
    line->a = malloc(sizeof(point_s));
    line->b = malloc(sizeof(point_s));
    printf("a x:\n");
    scanf("%d", &line->a->x);
    printf("a y:\n");
    scanf("%d", &line->a->y);
    printf("b x:\n");
    scanf("%d", &line->b->x);
    printf("b y:\n");
    scanf("%d", &line->b->y);
    FILE *a = fopen("dsoformer.html", "w");
    if (a == NULL)
        return (1);
    fprintf(a, "<svg viewBox=\"0 0 100 100\" xmlns=\"http://www.w3.org/2000/svg\">\n<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"#%s\" />\n</svg>\n"
        , line->a->x, line->a->y,  line->b->x, line->b->y,line->color);
    fclose(a);
    free(line->color);
    free(line->a);
    free(line->b);
    free(line);
    return 0;
}
