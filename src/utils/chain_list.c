#include "../../include/projet_svg.h"

list_s *init_list(void){
    list_s *list;

    list = malloc(sizeof(list_s));
    list->node = NULL;
    list->node = 0;
    return (list);
}

list_s *add_node(list_s *list, node_s *node){
    if (node == NULL)
        return (list);
    if (list->node){
        node_s *temp;
        temp = list->node;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
        list->length++;
        return (list);
    }
    list->node = node;
    list->length++;
    return (list);
}

list_s *supp_node(list_s *list, int index){
    int i = 0;
    node_s *temp_preview;
    node_s *temp_next;
    temp_preview = list->node;
    if (i > 0)
    {
           while(i + 1 != index){
            temp_preview = temp_preview->next;
            i++;
        }
    }
    if (temp_preview->next != NULL)
        temp_next = temp_preview->next->next;
    else
        temp_next = NULL;
    free_node(temp_preview->next);
    temp_preview->next = temp_next;
    return(list);
}

