// list/list.c
//
// Implementation for linked list.
//
// <Ronte' Parker>
#include <stdio.h>
#include "list.h"

// utility function for checking in list is empty
int isListEmpty(listT* l) {
  if (l == NULL) {
    printf("There is no list.\n");
    return 1;
  } else if (l->head == NULL) {
    printf("There is no data in the list.\n");
    return 1;
  }

  return 0;
}

listT* list_alloc() {
    listT* list = NULL;
    list = (listT*) malloc(sizeof(listT));
    list->head = NULL;

    nodeT* data = NULL;
    data = (nodeT*) malloc(sizeof(nodeT));
    data->value = 0;
    data->next = NULL;

    list->head = data;

    return list;
}

void list_free(listT *l) {
  free(l->head);
  free(l);
  return;
}

/* Prints the list in some format. */
void list_print(listT *l) {
  nodeT* curr = NULL;

  if (isListEmpty(l)) {
    return;

  } else {
    curr = l->head;
    int i = 1;
    printf("El%d: %d\n", i, curr->value);

    while(curr->next != NULL) {
      curr = curr->next;
      i++;

      printf("El%d: %d\n", i, curr->value);
    }
  }

  return;
}

/* Returns the length of the list. */
int list_length(listT *l) {
  nodeT* curr = NULL;
  int count = 0;

  if(!isListEmpty(l)) {
    curr = l->head;
    count++;
    
    while(curr->next != NULL) {
      curr = curr->next;
      count++;
    }
  }

  return count;
}

/* Methods for adding to the list. */
void list_add_to_back(listT *l, elem value) {
  if(!isListEmpty(l)){
    nodeT* curr = l->head;

    while(curr->next != NULL) {
      curr = curr->next;
    }

    nodeT* newNode = (nodeT*) malloc(sizeof(nodeT));
    newNode->value = value;
    newNode->next = NULL;

    curr->next = newNode;
  }

  return;
}

void list_add_to_front(listT *l, elem value) {
  if(!isListEmpty(l)){
    nodeT* curr = l->head;

    nodeT* newNode = (nodeT*) malloc(sizeof(nodeT));
    newNode->value = value;
    newNode->next = curr;

    l->head = newNode;
  }

  return;
}

void list_add_at_index(listT *l, elem value, int index) {  // adds to end of list if out of bounds
  if (index <= list_length(l) - 1 && index >= 0) {
    if(!isListEmpty(l)){
      nodeT* curr = l->head;
      nodeT* prev;

      while(index > 0) {
        index--;
        prev = curr;
        curr = curr->next;
      }

      nodeT* newNode = (nodeT*) malloc(sizeof(nodeT));
      newNode->value = value;
      newNode->next = curr;

      prev->next = newNode;
    }

  } else if (index >= list_length(l)) {
    list_add_to_back(l, value);
  }

  return;
}

/* Methods for removing from the list. Returns the removed element, or -1 for empty list */
elem list_remove_from_back(listT *l) {
  if(!isListEmpty(l)){
    nodeT* curr = l->head;
    nodeT* prev = NULL;

    while(curr->next != NULL) {
      prev = curr;
      curr = curr->next;
    }

    int val = curr->value;

    prev->next = NULL;
    free(curr);

    return val;
  }

  return -1;
}

elem list_remove_from_front(listT *l) {
  if(!isListEmpty(l)){
    nodeT* curr = l->head;
    nodeT* next = curr->next;

    int val = curr->value;

    l->head = next;
    free(curr);
    
    return val;
  }

  return -1;
}

elem list_remove_at_index(listT *l, int index) {
  if (index <= list_length(l) - 1 && index >= 0) {
    if(!isListEmpty(l)) {
      nodeT* curr = l->head;
      nodeT* prev;
      nodeT* next;

      while(index > 0) {
        index--;
        prev = curr;
        curr = curr->next;
        next = curr->next;
      }
      int val = curr->value;

      prev->next = next;
      free(curr);

      return val;
    }
  }

  return -1;
}

/* Checks to see if the given element exists in the list. */
bool list_is_in(listT *l, elem value) {
  if(!isListEmpty(l)) {
    nodeT* curr = l->head;

    if (curr->value == value) {
      return 1;
    }
    
    while(curr->next != NULL) {
      curr = curr->next;

      if (curr->value == value) {
        return 1;
      }
    }
  }

  return 0;
}

/* Returns the element at the given index, or -1 if empty or out of bounds */
elem list_get_elem_at(listT *l, int index) {
  if (index <= list_length(l) - 1 && index >= 0) {
    if(!isListEmpty(l)) {
      nodeT* curr = l->head;

      while(index > 0) {
        index--;
        curr = curr->next;
      }
      int val = curr->value;

      return val;
    }
  }

  return -1;
}

/* Returns the index at which the given element appears, or -1 if not found */
int list_get_index_of(listT *l, elem value) {
  if(!isListEmpty(l)) {
    int index = 0;
    nodeT* curr = l->head;

    if (curr->value == value) {
      return index;
    }
    
    while(curr->next != NULL) {
      curr = curr->next;
      index++;

      if (curr->value == value) {
        return index;
      }
    }
  }

  return -1;
}