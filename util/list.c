/* Simple linked list implementation */

/* This code will be repleaced by the macros defined in <sys/queue.h>
 * until i figure how to use them and i verify the VM works. 
 */

#include <stdlib.h>

#include "list.h"

list_t
*create_list()
{
	list_t *list = malloc(sizeof(list_t));
	list->head = NULL; /* It's empty */
	return list;
}

node_t
*create_node(int value)
{
	node_t *node = malloc(sizeof(node_t));
	node->value = value;
	return node;
}

void
destroy_node(node_t *node)
{
	free(node);
	return;
}

void
insert_head(list_t *list, int32_t value)
{
	node_t *new_node = create_node(value);
	if(list->head == NULL) {
		list->head = new_node;
	} else {
		node_t *tmp = list->head;
		list->head = new_node;
		new_node->next = tmp;
	}
	return;
}

void
insert_tail(list_t *list, int32_t value)
{
	node_t *new_node = create_node(value);
	node_t *cur_node = list->head;
	if(cur_node == NULL) { /* List's empty */
		list->head = new_node;
		
	} else {
		while(cur_node->next != NULL) {
			cur_node = cur_node->next;
		}
		cur_node->next = new_node;
	}
	return;
}

void
pop_head(list_t *list)
{
	node_t *old_head = list->head;
	list->head = list->head->next;
	destroy_node(old_head);
}
	
int32_t
get_node(list_t *list, int index)
{
	node_t *cur_node = list->head;
	int i = index;
	int j = 0;
	while(cur_node != NULL && j != i) {
		cur_node = cur_node->next;

	}
	if(cur_node != NULL)
		return cur_node->value;
	else
		return -1;
}

void
change_value(list_t *list, int new_value, int index)
{
}
