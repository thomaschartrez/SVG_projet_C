#include "../../include/projet_svg.h"

/**
 * @brief Validates if a string consists entirely of hexadecimal characters.
 * 
 * Checks the first 6 characters of the provided string to ensure they are 
 * valid hexadecimal digits (0-9, a-f, A-F).
 * 
 * @param color Pointer to the string to be validated.
 * @return int Returns 1 if all checked characters are valid hexadecimal digits, 
 *         otherwise returns 0.
 */
int color_is_exa(char *color){
    int i = 0;

    while(i < 6){
        if ((color[i] < '0' || color[i] > '9') && (color[i] < 'a' || color[i] > 'f') && (color[i] < 'A' || color[i] > 'F'))
            return 0;
        i++;
    }
    return 1;
}

/**
 * @brief Prompts the user to input and validate a hexadecimal color code.
 * 
 * Allocates memory for a color string, prompts the user to enter a 6-character 
 * hexadecimal color code (e.g., "FF00FF"), and validates the format and content 
 * using length checks and hexadecimal verification. Repeatedly prompts until valid input is received.
 * 
 * @return char* Pointer to the dynamically allocated, validated color string.
 */
char *color_init(void){
    char *color;
    int i = 1;

    color = malloc(sizeof(char)* 7);
    while (i){
        i = 0;
        printf("color exadecimal format ex : FF00FF\n");
        scanf("%6s", color);
        clear_stdin();
        if(strlen(color) != 6){
            printf(GRAS ROUGE"wrong format try again\n" RESET);
            i = 1;
        }
        if (i == 0 && color_is_exa(color) == 0){
            printf(GRAS ROUGE"wrong format try again\n" RESET);
            i = 1;
        }
    }
    return (color);
}
