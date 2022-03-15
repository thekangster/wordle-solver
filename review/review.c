#include "review.h"
#include <stdio.h>
#include <stdlib.h>

// Functions for you to implement. Most of the work for this homework will be
// done in here, but you'll also need to make changes to review.h and yelling.c.

// Problem 1
void sum_and_difference(int a, int b, int *sum, int *difference) {
  //  Your code goes here!

  *sum = a + b;

  *difference = a - b;
}

// Problem 2

void push(LLint **node, int data) {
  LLint *new_node;
  new_node = malloc(sizeof(LLint));
  new_node->val = data;
  new_node->next = *node;
  *node = new_node;
}

void walk_list(LLint *node) {
  int count = 0;
  LLint *walk = node;
  while (walk != NULL) {
    count++;
    printf("node %d: %d -> ", count, walk->val); 
    walk = walk->next;
  }
  printf("null\n");
}

// This one ought to be recursive.
size_t ll_length(LLint *node) {
  // change this, clearly.

  if (node == NULL) {
    return (size_t)0;
  } else {
    return (size_t)1 + (size_t)ll_length(node->next);
  }
}

// Do this one iteratively.
size_t ll_length_iterative(LLint *node) {
  // These are just default return values; they're for you to change.
  
  size_t count = 0;
  LLint* cur;
  cur = node;
  while (cur != NULL) {
    count++;
    cur = cur->next;
  }

  return count;
}

// Problem 3.

//citation: GeeksforGeeks

LLdouble *create_stack(unsigned int capacity) {
  LLdouble *stack = malloc(sizeof(LLdouble));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = malloc(stack->capacity * sizeof(double));
  return stack;
}

int isFull(LLdouble *stack) {
  return stack->top == (int)(stack->capacity - 1);
}

int isEmpty(LLdouble *stack) {
  return stack->top == -1;
}

void push_double(LLdouble *stack, double item) {
  if (isFull(stack)) {
    return;
  }
  stack->array[++stack->top] = item;
}

int pop_double(LLdouble *stack) {
  if (isEmpty(stack)) {
    return -1;
  }
  return stack->array[stack->top--];
}

void reverse_doubles_with_stack(double *array, size_t array_len) {
  // This function will reverse the order of the array pointed to by *array.
  // Make sure to define your linked list data structure in review.h, and use
  // stack behavior (LIFO) to get the numbers in the reversed order.
  // There is a way to do this without a stack data structure, I know. But this
  // is for practice with data structures.

// Problem 4.
  LLdouble *stack = create_stack(array_len);
  for (int i = 0; i < (int)array_len; i++) {
    push_double(stack, array[i]);
  }

  for (int i = 0; i < (int)array_len; i++) {
    array[i] = pop_double(stack);
  }

  for (int i = 0; i < (int)array_len; i++) {
    printf("%f ", array[i]);
  }

}  

tnode *word_observe(char *word, tnode *node) {
  // This function returns a pointer to a tnode because you may have to allocate
  // a new one. You might take a NULL pointer to start with.
  // Also, this means that you can very cleanly do this with recursion.
  return NULL;
}

int word_count(char *word, tnode *node) {
  // Default return values; here for you to change.
  return 0;
}

void delete_tree(tnode *node) {
  // Free the whole tree and all associated memory. This can be recursive or
  // not, your choice!
}
