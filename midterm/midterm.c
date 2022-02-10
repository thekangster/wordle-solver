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
  long long *a;
  int x = 26;
  a = fibonacci_numbers(x);
  for (int i = 0; i < x; i++) {
    printf("%lld\n", a[i]);
  }
  return 0;
}
