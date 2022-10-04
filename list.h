// list/list.h
// 
// Interface definition for linked list.
//
// <Ronte' Parker>

#include <stdbool.h>
#include <stdlib.h>


/* Defines the type of the elements in the linked list. You may change this if
 * you want! */
typedef int elem;

/* Defines the node structure. Each node contains its element, and points to the
 * next node in the list. The last element in the list should have NULL as its
 * next pointer. */
struct node {
	elem value;
	struct node *next;
};
typedef struct node nodeT;

/* Defines the list structure, which simply points to the first node in the
 * list. */
struct list {
	nodeT *head;
};
typedef struct list listT;

/* Functions for allocating and freeing lists. By using only these functions,
 * the user should be able to allocate and free all the memory required for
 * this linked list library. */
listT *list_alloc();
void list_free(listT *l);

/* Prints the list in some format. */
void list_print(listT *l);

/* Returns the length of the list. */
int list_length(listT *l);

/* Methods for adding to the list. */
void list_add_to_back(listT *l, elem value);
void list_add_to_front(listT *l, elem value);
void list_add_at_index(listT *l, elem value, int index);  // adds to end of list if out of bounds

/* Methods for removing from the list. Returns the removed element, or -1 for empty list */
elem list_remove_from_back(listT *l);
elem list_remove_from_front(listT *l);
elem list_remove_at_index(listT *l, int index);

/* Checks to see if the given element exists in the list. */
bool list_is_in(listT *l, elem value);

/* Returns the element at the given index, or -1 if empty or out of bounds */
elem list_get_elem_at(listT *l, int index);

/* Returns the index at which the given element appears, or -1 if not found */
int list_get_index_of(listT *l, elem value);

