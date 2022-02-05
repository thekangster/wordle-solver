#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack_calculator.h"

// Allocate a new Stack struct and return a pointer to it.
Stack *stack_create(void) {
  // this one is complete, no need to change it!
    Stack *out;
    out = (Stack *)calloc(1, sizeof(Stack));
    return out;
}

// Add a new node at the front of the stack. Return false if we are unable to do
// so (eg, if memory allocation fails).
bool stack_push(Stack *s, CalculatorItem item) {
  // your code here
    Node *newtop = (Node *)calloc(1, sizeof(Node));
    if (newtop == NULL) {
        return false;
    }
    newtop->item = item;
    newtop->next = s->top;

    s->top = newtop;
    return true;
}

// Pop the stack and put the result into the output pointer.
// return false if the stack is NULL or if it is empty.
bool stack_pop(Stack *s, CalculatorItem *output) {
  // your code here
    if (s == NULL || s->top == NULL) {
        return false;
    }
    CalculatorItem result = s->top->item;
    *output = result;

    Node *delete_this = s->top;
    s->top = s->top->next;

    free(delete_this);
    return true;
}

// Returns true if the specified stack is empty.
bool stack_empty(Stack *s) {
  // your code here
    if (s == NULL || s->top == NULL) {
        return true;
    }
    return false;
}

// Free all of the memory used by this stack, including its linked list.
// When you are done, set the pointer to NULL.
void stack_delete(Stack **s) {
  // your code here
    CalculatorItem n;
    while ((*s)->top != NULL) {
        stack_pop(*s, &n);
    free(*s);
    *s = NULL;
    }
}

// Returns true if we were able to successfully perform the computation step,
// and false if there was an error of some kind.
bool stack_compute_step(Stack *s, CalculatorItem item) {
  // your code here
    CalculatorItem result;
    CalculatorItem sol;

    if (item.type == NUMBER) {
        stack_push(s, item);
        return true;
    }

    if (item.type == ADD) {
        float b = s->top->item.value;
        stack_pop(s, &result);
        float a = s->top->item.value;
        stack_pop(s, &result);
        sol.value = a + b;
        stack_push(s, sol);
        return true;
    }

    if (item.type == SUBTRACT) {
        float b = s->top->item.value;
        stack_pop(s, &result);
        float a = s->top->item.value;
        stack_pop(s, &result);
        sol.value = a - b;
        stack_push(s, sol);
        return true;
    }

    if (item.type == MULTIPLY) {
        float b = s->top->item.value;
        stack_pop(s, &result);
        float a = s->top->item.value;
        stack_pop(s, &result);
        sol.value = a * b;
        stack_push(s, sol);
        return true;
    }

    if (item.type == DIVIDE) {
        float b = s->top->item.value;
        stack_pop(s, &result);
        float a = s->top->item.value;
        stack_pop(s, &result);
        sol.value = a / b;
        stack_push(s, sol);
        return true;
    }
    return false;
}
