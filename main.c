#include <stdio.h>
#include "list.h"

int main() 
{
  printf("Write your Tests for your linked list implementation\n");
  
  listT *mylist;
  mylist = list_alloc();

  // Prints Starting List
  list_print(mylist);

  // Length of List
  printf("Length of mylist: %d\n", list_length(mylist));

  // Add to front, middle, and end
  list_add_to_back(mylist, 3);
  list_add_to_front(mylist, 1);
  list_add_at_index(mylist, 2, 1);
  // and out of bounds
  list_add_at_index(mylist, -1, 10);

  printf("\n");
  list_print(mylist);

  // removes from front, middle, and end
  printf("\n");
  printf("At index(2): %d\n", list_remove_at_index(mylist, 2));
  printf("From back: %d\n", list_remove_from_back(mylist));
  printf("From front: %d\n", list_remove_from_front(mylist));

  printf("\n");
  list_print(mylist);

  // Check if an element is in the list
  printf("\n");
  printf("Is 2 in the list: %d\n", list_is_in(mylist, 2));
  printf("Is 5 in the list: %d\n", list_is_in(mylist, 5));

  // Get element at index
  printf("\n");
  printf("At index(1) in the list: %d\n", list_get_elem_at(mylist, 1));

  // Get index from element
  printf("\n");
  printf("The element 2 is at: index(%d)\n", list_get_index_of(mylist, 2));
  printf("The element 3 is at: index(%d)\n", list_get_index_of(mylist, 3));
  printf("The element 5 is at: index(%d)\n", list_get_index_of(mylist, 5));

  list_free(mylist);

  printf("\n");
  return 0;
}
