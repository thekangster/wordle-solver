
# homework 4: graphs, queues, stacks, and search

This is the design document for homework 4.

# how the program works

Continuing on the graphs demo we worked on in class, this assignment will show the user a path between two nodes in a graph (if it exists) between two nodes in a graph using breadth-first search and depth-first search algorithms. 

Our breadth-first search algorithm will keep a queue of vertices that we would like to explore and queue the neighbors of the current vertex. This will make is so that we are rippling out on all the nodes until we find the path. 

Our depth-first search algorithm will be the same as our breadth-first search algorithm, but we will replace the queue with a stack. This wil make the behavior so that rather than gradually radiating outward from our starting point, the search will plumb the depths of all of the paths reachable for the first child of the current vertex before backing up to consider all of the paths reachable from the current vertex's second child and so on.

For the stack implementation, I created a SPath struct that holds a Path val and a pointer to a next SPath struct. My Stack struct holds an SPath struct called top. I also have a stack_create function that simplifies the stack initialization. The stack_push function puts a path onto the top of the stack and the stack_pop function removes the top path of the stack.

# pseudocode

```
enqueue path function (takes an LLPath pointer q and Path path):
  calloc newnode
  set newnode's val to val

  if q is null
    return newnode

  create LLPath cur and set to q
  while cur's next node is not NULL
    set cur to cur's next node

  set cur's next node to newnode
  return q

dequeue function (takes LLpath double pointer q and Path pointer ret
  if pointer q is NULL
    return false

  set pointer ret to pointer q's val
  
  create LLpath freethis and set to pointer q
  set pointer q to pointer q's next node
  free freethis
  return true

bfs function (takes Graph pointer g, int i, int j)
  keep a set of vertices that we have visited
  keep a queue of vertices that we want to visit
  initialize a path and set steps to 0
  extend the path by i
  queue the vertex i
  while there are more places to visit in the queue
    dequeue the next place to visit
    if it is our intended destination
      return the path
    else make sure it is in the set of visited nodes
    enqueue each of its neighbors that have not been visited
  return empty path  

dfs function (takes Graph pointer g, int i, int j)
  keep a set of vertices that we have visited
  keep a stack of vertices that we want to visit
  initialize path and set steps to 0
  extend the path by i
  push i onto the stack
  while there are more places to visit in the stack
    pop the next place to visit
    if it is our intended destination
      return the path
    else make sure it is in the set of visited nodes
    push each of its neighbors that havent been visited onto the stack
  return empty path
```
