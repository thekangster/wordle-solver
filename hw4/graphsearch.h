#pragma once

// maximum number of vertices we're willing to have in a graph, for simplicity.
#define MAX_GRAPH_SIZE 128

typedef struct SPath SPath;

typedef struct {
  int steps;
  int vertices_visited[MAX_GRAPH_SIZE];
} Path;

struct SPath {
  SPath *next;
  Path val;
};

typedef struct {
  SPath *top;
} Stack;

typedef struct {
  int vertices;  // the set V
  int **matrix;  // the set E
} Graph;

typedef struct LLint {
  int val;
  struct LLint *next;
} LLint;

typedef struct LLPath {
  Path val;
  struct LLPath *next;
} LLPath;

Stack *stack_create(void);

bool stack_push(Stack *s, Path item);

bool stack_pop(Stack *s, Path *val);

LLint *add_to_set(LLint *set, int val);
bool set_contains(LLint *set, int val);

LLPath *enqueue_path(LLPath *q, Path path); 
bool dequeue_path(LLPath **q, Path *ret);

Graph *graph_create(int vertices);
void graph_add_edge(Graph *g, int i, int j) ;
bool graph_has_edge(Graph *g, int i, int j);

Path graph_find_path_bfs(Graph *g, int i, int j);
Path graph_find_path_dfs(Graph *g, int i, int j);

void print_path(Path path);
