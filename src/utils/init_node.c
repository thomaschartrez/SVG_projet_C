#include "../../include/projet_svg.h"

/**
 * @brief Allocates and initializes a new linked list node for a circle shape.
 * 
 * Allocates memory for a new `node_s` node and its inner figure container, 
 * assigns the provided shape type and circle pointer, sets the next pointer to NULL, 
 * and returns the initialized node.
 * 
 * @param type The shape type (e.g., CIRCLE).
 * @param circle Pointer to the `circle_s` structure to be encapsulated by the node.
 * @return node_s* Pointer to the newly created and initialized node structure, 
 *         or NULL if memory allocation fails.
 */
node_s  *init_node_circle(Forme type, circle_s *circle){
    node_s  *node;

    node = malloc(sizeof(node_s));
    node->figure = malloc(sizeof(Figure));
    node->type = type;
    node->figure->circle = circle;
    node->next = NULL;
    return node;
}

/**
 * @brief Allocates and initializes a new linked list node for a line shape.
 * 
 * Allocates memory for a new `node_s` node and its inner figure container, 
 * assigns the provided shape type and line pointer, sets the next pointer to NULL, 
 * and returns the initialized node.
 * 
 * @param type The shape type (e.g., LINE).
 * @param line Pointer to the `line_s` structure to be encapsulated by the node.
 * @return node_s* Pointer to the newly created and initialized node structure, 
 *         or NULL if memory allocation fails.
 */
node_s  *init_node_line(Forme type ,line_s *line){
    node_s  *node;

    node = malloc(sizeof(node_s));
    node->figure = malloc(sizeof(Figure));
    node->type = type;
    node->figure->line = line;
    node->next = NULL;
    return node;
}

/**
 * @brief Allocates and initializes a new linked list node for a square shape.
 * 
 * Allocates memory for a new `node_s` node and its inner figure container, 
 * assigns the provided shape type and rectangle pointer, sets the next pointer to NULL, 
 * and returns the initialized node.
 * 
 * @param type The shape type (e.g., SQUARE).
 * @param square Pointer to the `rectangle_s` structure representing the square to be encapsulated by the node.
 * @return node_s* Pointer to the newly created and initialized node structure, 
 *         or NULL if memory allocation fails.
 */
node_s  *init_node_square(Forme type ,rectangle_s *square){
    node_s  *node;

    node = malloc(sizeof(node_s));
    node->figure = malloc(sizeof(Figure));
    node->type = type;
    node->figure->rectangle = square;
    node->next = NULL;
    return node;
}

/**
 * @brief Allocates and initializes a new linked list node for a rectangle shape.
 * 
 * Allocates memory for a new `node_s` node and its inner figure container, 
 * assigns the provided shape type and rectangle pointer, sets the next pointer to NULL, 
 * and returns the initialized node.
 * 
 * @param type The shape type (e.g., RECTANGLE).
 * @param rectangle Pointer to the `rectangle_s` structure to be encapsulated by the node.
 * @return node_s* Pointer to the newly created and initialized node structure, 
 *         or NULL if memory allocation fails.
 */
node_s  *init_node_rectangle(Forme type , rectangle_s *rectangle){
    node_s  *node;

    node = malloc(sizeof(node_s));
    node->figure = malloc(sizeof(Figure));
    node->type = type;
    node->figure->rectangle = rectangle;
    node->next = NULL;
    return node;
}

/**
 * @brief Allocates and initializes a new node containing a polyline or polygon figure.
 * 
 * @param type The shape type (e.g., POLYLINE or POLYGONE).
 * @param polyline Pointer to the polyline structure to be stored in the node.
 * @return node_s* Returns a pointer to the newly allocated node structure.
 */
node_s  *init_node_polyline(Forme type , polyline_s *polyline){
    node_s  *node;

    node = malloc(sizeof(node_s));
    node->figure = malloc(sizeof(Figure));
    node->type = type;
    node->figure->polyline = polyline;
    node->next = NULL;
    return node;
}

/**
 * @brief Allocates and initializes a new linked list node for an ellipse shape.
 * 
 * Allocates memory for a new `node_s` node and its inner figure container, 
 * assigns the provided shape type and ellipse pointer, sets the next pointer to NULL, 
 * and returns the initialized node.
 * 
 * @param type The shape type (e.g., ELLIPSE).
 * @param elipse Pointer to the `elipse_s` structure to be encapsulated by the node.
 * @return node_s* Pointer to the newly created and initialized node structure, 
 *         or NULL if memory allocation fails.
 */
node_s  *init_node_ellipse(Forme type , elipse_s *elipse){
    node_s  *node;

    node = malloc(sizeof(node_s));
    node->figure = malloc(sizeof(Figure));
    node->type = type;
    node->figure->elipse = elipse;
    node->next = NULL;
    return node;
}

