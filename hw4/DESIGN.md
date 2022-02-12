
# homework 4: graphs, queues, stacks, and search

This is the design document for homework 4.

# how the program works

Continuing on the graphs demo we worked on in class, this assignment will show the user a path between two nodes in a graph (if it exists) between two nodes in a graph using bread-first search and depth-first search algorithms.

# pseudocode

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
  put the starting vertex into the queue
  while there are more places to visit in the queue
    dequeue the next place to visit
    if it is our intended destination
      return the path
    else make sure it is in the set of visited nodes
      enqueue each of its neighbors that have not been visited

dfs function (takes Graph pointer g, int i, int j)
  same as bfs but replace the queue with a stack
