#include "review.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Your code for testing your functions in review.c goes here.

  // problem 1 tests
  /*
  int sum;
  int dif;
  sum_and_difference(4, 3, &sum, &dif);
  printf("sum %d, dif %d\n", sum, dif);
  */

  // problem 2 tests
  /*
  LLint *new_node = NULL;
  push(&new_node, 3);
  push(&new_node, 2);
  push(&new_node, 1);

  walk_list(new_node);

  size_t rec_length = ll_length(new_node);
  size_t iter_length = ll_length_iterative(new_node);
  printf("recursive length: %zu, iterative length: %zu\n", rec_length, iter_length);
  */

  //problem 3 tests

  /*
  double arr[] = {1, 2, 3, 4, 5};
  size_t len = sizeof(arr) / sizeof(arr[0]);
  reverse_doubles_with_stack(arr, len);
  */


  return 0;
}
