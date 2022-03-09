#include "hw7.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_BUCKETS 100

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

CustomerNode *add_to_list(char *email, char *name, int shoe_size, char *fav_food, CustomerNode *bucket) {
  
  CustomerNode* new_customer;
  
  new_customer = malloc(sizeof(CustomerNode));
  new_customer->email = strdup(email);
  new_customer->name = strdup(name);
  new_customer->shoe_size = shoe_size;
  new_customer->fav_food = strdup(fav_food);
 
  new_customer->next = bucket;

  return new_customer;
}

void add_to_hashtable(char *email, char *name, int shoe_size, char *fav_food, CustomerNode **buckets, size_t num_buckets) {
  
  size_t which_bucket = hash(email) % num_buckets;

  buckets[which_bucket] = add_to_list(email, name, shoe_size, fav_food, buckets[which_bucket]);
  
  //printf("customer %s goes in bucket %lu .\n", email, which_bucket);
}

char *fav_food_for_customer(char *email, CustomerNode **buckets, size_t num_buckets) {
  
  size_t which_bucket = hash(email) % num_buckets;

  char *result = NULL;
  CustomerNode* node;
  node = buckets[which_bucket];

  while(node != NULL) {
    if (strcmp(node->email, email) == 0) {
      result = node->fav_food;
    }
    node = node->next;
  }
  return result;
}

