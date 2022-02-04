
# homework 3: dynamic memory, linked lists and stacks

This is the design document for homework 3.

# how the program works

This assignment uses linked lists and stacks to create a stack-based calculator, essentially a Reverse-Polish Notation calculator. It will read a series of numbers and operations from a text file to perform computation using the stack data structure.

The calculator works by reading input from the text file. If it reads a number, then we push it to the calculation stack. If it reads a valid operator, we pop two values from the stack and use these two values as the operands for that specific operation. The resulting value is pushedto the stack. If there is an error, then the computation should return false.

# pseudocode

```
bool stack_push(pointer to stack s, CalculatorItem item)
    Node *newtop = (Node *)calloc(1, sizeof(Node))
    if newtop is null
        return false
    set newtop->data to item
    set newtop->next to s->top

    set s->top to newtop
    return true

bool stack_pop(pointer to stack s, CalculatorItem pointer to output)
    if (s is NULL or s->top is NULL)
        return false
    set int result to s->top->data
    pointer to output = result

    set Node pointer to delete_this to s->top
    s->top = s->top->next

    free delete_this
    return true

bool stack_empty(pointer to stack s)
    if (s is NULL or s->top is NULL)
        return true

void stack_delete(pointer to pointer to stack s)
   free pointer to s
   set pointer to s to NULL 

bool stack_compute_step(pointer to stack, CalculatorItem item)
    if item.type == ADD
        set float b to *s->top
        stack_pop(pointer to s, *s->top)
        set float a to *s->top
        stack_pop(pointer to s, *s->top)
        return a + b

    if item.type == SUBTRACT
        set float b to *s->top
        stack_pop(pointer to s, *s->top)
        set float a to *s->top
        stack_pop(pointer to s, *s->top)
        return a - b

    if item.type == MULTIPLY
        set float b to *s->top
        stack_pop(pointer to s, *s->top)
        set float a to *s->top
        stack_pop(pointer to s, *s->top)
        return a * b

    if item.type == DIVIDE
        set float b to *s->top
        stack_pop(pointer to s, *s->top)
        set float a to *s->top
        stack_pop(pointer to s, *s->top)
        return a / b

```
