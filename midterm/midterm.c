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

LLfloat *map_floats(float (*f)(float), LLfloat *numbers)  {
  // finish this function.
  // Should it be recursive? It's up to you, but it could be recursive!
  return NULL;
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

}
