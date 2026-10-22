#include "../../include/projet_svg.h"

/**
 * @brief Allocates and initializes a new list structure.
 * 
 * Allocates memory for a new `list_s` container, initializes its internal 
 * pointers/fields, and returns a pointer to the newly created list.
 * 
 * @return list_s* Pointer to the newly allocated and initialized list structure, 
 *         or NULL if memory allocation fails.
 */
list_s *init_list(void){
    list_s *list;

    list = malloc(sizeof(list_s));
    list->node = NULL;
    list->node = 0;
    return (list);
}

/**
 * @brief Appends a new node to the end of a linked list.
 * 
 * Checks if the provided node is valid. If the list is currently empty, the node 
 * becomes the first element. Otherwise, the function traverses to the end of the 
 * list and appends the node. It also increments the length counter of the list.
 * 
 * @param list Pointer to the `list_s` structure where the node will be added.
 * @param node Pointer to the `node_s` structure to be added.
 * @return list_s* Pointer to the updated list structure.
 */
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

polyline_s *init_polyline(void){
    polyline_s *list;

    list = malloc(sizeof(polyline_s));
    list->node = NULL;
    list->color = NULL;
    return (list);
}