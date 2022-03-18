#include "final.h"

#include <stdio.h>

void find_two_biggest(LLint *linkedlist, int *biggest, int *nextbiggest) {
  // Your code here!
  int max = linkedlist->val;
  int nextmax = linkedlist->next->val;

  if (nextmax > max) {
    max = nextmax;
    nextmax = linkedlist->val;
  }

  linkedlist = linkedlist->next->next;

  while (linkedlist != NULL) {
    if (linkedlist->val > max) {
      nextmax = max;
      max = linkedlist->val;
    } else if (linkedlist->val > nextmax) {
      nextmax = linkedlist->val;
    }
    linkedlist = linkedlist->next;
  }

  *biggest = max;
  *nextbiggest = nextmax;
  return;
}
