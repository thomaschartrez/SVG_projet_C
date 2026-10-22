#include "../include/projet_svg.h"

/**
 * @brief Clears the standard input stream (stdin).
 * 
 * Consumes and discards all remaining characters in the input buffer until 
 * a newline character ('\n') or end-of-file (EOF) is reached. This is typically 
 * used after inputs like scanf to prevent leftover characters from interfering 
 * with subsequent reads.
 */
void clear_stdin(void)
{
    char c = 'a';

    while (c != '\n' && c!=EOF)
        c = getc(stdin);
}

/**
 * @brief Main entry point of the application.
 * 
 * Initializes a shape management linked list and runs an interactive console menu 
 * allowing the user to create, modify, upload, visualize, save, and exit the program.
 * 
 */
int main(void){
    unsigned char i = 1;
    list_s *list;

    list = init_list();
    while(1){
        system("clear");
        if (i == 0)
            printf(GREEN"nothing to modify\n"RESET);
        printf("    ---------------------------------------------------\n");
        printf("    ||               0 : to  quit                    ||\n");
        printf("    ||               1 : to  create                  ||\n");
        printf("    ||               2 : to  modify                  ||\n");
        printf("    ||               3 : to  upload  a save          ||\n");
        printf("    ||               4 : to visualize                ||\n");
        printf("    ||               5 : creat a new save            ||\n");
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
