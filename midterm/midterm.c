#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// PROBLEM 1

long long *fibonacci_numbers(int n) {
  // You're going to have to allocate an array, fill it in, and return it.
  // The array should be of length n.
  // Recall the first few entries should be 1, 1, 2, 3, 5, 8, ...
  long long* output = NULL;
  output = (long long*)malloc(n * sizeof(long long));

  long long prev = 1;
  long long prevprev = 0;
  long long cur;
  
  if (n == 1) {
    output[0] = 1;
    return output;
  }

  output[0] = 1;
  for (int i = 1; i < n; i++) {
    cur = prevprev + prev;
    output[i] = cur;
    prevprev = prev;
    prev = cur;
  }
  return output;
}


// PROBLEM 2

typedef struct {
  int shoe_size;
  int customer_id;
  int num_purchases;
} ShoeCustomer;

void bubble_sort_customers(ShoeCustomer* customers, int n_customers) {
  // Your code here! Make them sorted!
  bool swap;
  ShoeCustomer tmp;
  for (int x = 0; x < n_customers; x++) {
    swap = false;
    for (int y = 0; y < (n_customers - x - 1); y++) {
      if (customers[y].shoe_size > customers[y+1].shoe_size) {
        tmp = customers[y];
        customers[y] = customers[y+1];
        customers[y+1] = tmp;
        swap = true;
      }
    }
    if (swap == false) {
      break;
    }
  }
}

// PROBLEM 3

// A linked list of floating point numbers.
typedef struct LLfloat {
  float val;
  struct LLfloat *next;
} LLfloat;

// add node function
LLfloat *add_node(float item, LLfloat* rest) {
  LLfloat *newnode = (LLfloat *)calloc(1, sizeof(LLfloat));
  newnode->val = item;
  newnode->next = rest;
  return newnode;
}

// print LL
void walk_list(LLfloat *list) {
  if (list == NULL) {
    return;
  }
  printf("%f\n", list->val);
  walk_list(list->next);
}

// square function
float square(float x) {
  return x * x;
}

LLfloat *map_floats(float (*f)(float), LLfloat *numbers)  {
  // finish this function.
  // Should it be recursive? It's up to you, but it could be recursive!
  
  LLfloat *temp = numbers->next;
  LLfloat *new = NULL;
  new = add_node(f(numbers->val), new);
  LLfloat *newtemp = new;
  
  while (temp != NULL) {
    LLfloat *node = (LLfloat *)calloc(1, sizeof(LLfloat));
    node->val = f(temp->val);
    newtemp->next = node;
    newtemp = node;
    temp = temp->next;
  }
  return new;

  /*
  LLfloat* new = (LLfloat *)calloc(1, sizeof(LLfloat));
  if (numbers == NULL) {
    printf("new list\n");
    return new;
  }

  new->next = numbers->next; 
  new->val = f(numbers->val);
  printf("new: %f old: %f\n", new->val, numbers->val);
  printf("recursive call\n");
  map_floats(f, new->next);
  */
}

// PROBLEM 4

unsigned long compute_availability(unsigned long *calendars, int num_users) {
  unsigned long availability = 0;
  return availability;
}

// put examples for testing your functions in the main! You're going to have to
// figure out how to test these.
int main(void) {
  // PROBLEM 1 TESTS

  /*
  long long *a;
  int x = 26;
  a = fibonacci_numbers(x);
  for (int i = 0; i < x; i++) {
    printf("%lld\n", a[i]);
  }
  return 0;
  */

  // PROBLEM 2 TESTS
  
  /*
  ShoeCustomer chad;
  chad.shoe_size = 420;
  chad.customer_id = 5;

  ShoeCustomer godfrey;
  godfrey.shoe_size = 12;
  godfrey.customer_id = 4;

  ShoeCustomer mike;
  mike.shoe_size = 7;
  mike.customer_id = 3;

  ShoeCustomer gav;
  gav.shoe_size = 6;
  gav.customer_id = 2;

  ShoeCustomer gord;
  gord.shoe_size = 4;
  gord.customer_id = 1;

  ShoeCustomer customers[5];
  customers[0] = gord;
  customers[1] = chad;
  customers[2] = godfrey;
  customers[3] = mike;
  customers[4] = gav;

  bubble_sort_customers(customers, 5);

  for (int i = 0; i < 5; i++) {
    printf("sorted order: %d\tshoe size: %d\n", customers[i].customer_id, customers[i].shoe_size);
  }
  */

  // problem 3 tests
  /* 
  LLfloat *front = NULL;
  front = add_node(2, front);
  front = add_node(3, front);
  front = add_node(4, front);
  
  walk_list(front); //print old LL
  walk_list(map_floats(square, front)); //print new LL
  */


}