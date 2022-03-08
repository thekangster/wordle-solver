#include "hw7.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_BUCKETS 20

unsigned long hash(char *str) {
  unsigned long hash = 5381;
  int c;

  while (*str != '\0') {
    c = *str;
    hash = ((hash << 5) + hash) + (unsigned char)c;
    str++;
  }
  return hash;
}

CustomerNode *add_to_list(char *email, CustomerInfo data, CustomerNode *bucket) {
  
  CustomerNode* new_customer;

  new_customer = malloc(sizeof(CustomerNode));
  new_customer->key = strdup(email);
  new_customer->val->email = strdup(data.email);
  new_customer->val->name = strdup(data.name);
  new_customer->val->shoe_size = data.shoe_size;
  new_customer->val->fav_food = strdup(data.fav_food);
  
  new_customer->next = bucket;

  return new_customer;
}

void add_to_hashtable(char *email, CustomerInfo data, CustomerNode **buckets, size_t num_buckets) {
  
  size_t which_bucket = hash(email) % num_buckets;

  buckets[which_bucket] = add_to_list(email, data, buckets[which_bucket]);
  
  printf("customer %s goes in bucket %lu .\n", email, which_bucket);
}

int main(void) {
  return 0;
}
