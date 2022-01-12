/* list for the vm, which requires a 32 bit integer */
#include <stdint.h>

typedef struct node_t {
	int32_t value;
	struct node_t *next;

}node_t;

typedef struct list_t {
	node_t *head;

}list_t;

/* Allocates and returns an empty list */

list_t
*create_list();

/* Creates a node with a given value */

node_t
*create_node(int32_t value);

/* We don't have smart pointers and shit */

void
destroy_node(node_t *node);

/* Inserts the value into the list */

void
insert_head(list_t *list, int32_t value);

void
insert_tail(list_t *list, int32_t value);

void
pop_head(list_t *list);

int32_t
get_node(list_t *list, int index);

void
change_value(list_t *list, int new_value, int index);
