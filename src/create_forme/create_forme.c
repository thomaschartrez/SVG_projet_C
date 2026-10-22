#include "../../include/projet_svg.h"

/**
 * @brief Displays an interactive menu allowing the user to select and add a new shape to the list.
 * 
 * @param list Pointer to the list structure where the new shape will be added.
 * @return int Returns 0 when the user chooses to quit.
 */
int    add_new_forme(list_s *list){
    unsigned char i;

    while(1){
        system("clear");
        printf(" ---------------------------------------------------\n");
        printf("||       0 : ❌ to quit                           ||\n");
        printf("||       1 : 📏 to create a line                  ||\n");
        printf("||       2 : 🔵 to create a circle                ||\n");
        printf("||       3 : ⬛ to create a square                ||\n");
        printf("||       4 : 🟦 to create a rectangle             ||\n");
        printf("||       5 : 🟠 to create an ellipse              ||\n");
        printf("||       6 : 〰️ to create a polyline              ||\n");
        printf("||       7 : ⬡ to create a polygon                ||\n");
        printf(" ---------------------------------------------------\n");
        scanf("%hhd", &i);
        clear_stdin();
        switch (i)
        {
        case 0:
            return 0;
        case 1:
            add_line(list);
            break;
        case 2:
            add_circle(list);
            break;
        case 3:
            add_square(list);
            break;
        case 4:
            add_rectangle(list);
            break;
        case 5:
            add_ellipse(list);
            break;
        case 6:
            add_polyline(list, POLYLINE);
            break;
        case 7:
            add_polyline(list, POLYGONE);
            break;
        default:
            break;
        }
    }
    return 0;
}
