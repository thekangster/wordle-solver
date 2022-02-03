
# homework 3: dynamic memory, linked lists and stacks

This is the design document for homework 3.

# how the program works

This assignment uses linked lists and stacks to create a stack-based calculator, essentially a Reverse-Polish Notation calculator. It will read a series of numbers and operations from a text file to perform computation using the stack data structure.

The calculator works by reading input from the text file. If it reads a number, then we push it to the calculation stack. If it reads a valid operator, we pop two values from the stack and use these two values as the operands for that specific operation. The resulting value is pushedto the stack. If there is an error, then the computation should return false.

# pseudocode


