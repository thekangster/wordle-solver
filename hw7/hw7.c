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

  CustomerNode* node;
  node = bucket;

  while(node != NULL) {
    if (strcmp(node->email, email) == 0) {
      free(node->name);
      node->name = strdup(name);
      node->shoe_size = shoe_size;
      free(node->fav_food);
      node->fav_food = strdup(fav_food);
      return node;
    }
    node = node->next;
  }

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

void lookup_customer(char *email, CustomerNode **buckets, size_t num_buckets) {
  
  size_t which_bucket = hash(email) % num_buckets;

  CustomerNode* node;
  node = buckets[which_bucket];

  while(node != NULL) {
    if (strcmp(node->email, email) == 0) {
      printf("email: %s\n", node->email);
      printf("name: %s\n", node->name);
      printf("shoesize: %d\n", node->shoe_size);
      printf("food: %s\n\n", node->fav_food);
    }
    node = node->next;
  }
  return;
}

void list_customers(CustomerNode **buckets, size_t num_buckets) {
  
  CustomerNode* node;
  
  for (int i = 0; i < (int)num_buckets; i++) {
    node = buckets[i];
    while(node != NULL) {
      printf("email: %s\n", node->email);
      printf("name: %s\n", node->name);
      printf("shoesize: %d\n", node->shoe_size);
      printf("food: %s\n\n", node->fav_food);
      node = node->next;
    }
  }
  return;
}

void delete_customer(char *email, CustomerNode **buckets, size_t num_buckets) {
  
  size_t which_bucket = hash(email) % num_buckets;

  CustomerNode* cur;
  cur = buckets[which_bucket];
  CustomerNode* prev;
  prev = NULL;

  while(cur != NULL) {
    if (strcmp(cur->email, email) == 0) {
      if (prev == NULL) {
        buckets[which_bucket] = cur->next;
      } else {
        prev->next = cur->next;
      }
      free(cur->email);
      free(cur->name);
      free(cur->fav_food);
      free(cur);
      break;
    }
    prev = cur;
    cur = cur->next;
  }
  return;
}

void delete_hashtable(CustomerNode **buckets, size_t num_buckets) {
  
  CustomerNode *cur;
  CustomerNode *tmp;
  for (int i = 0; i < (int)num_buckets; i++) {
    cur = buckets[i];
    while(cur != NULL) {
      tmp = cur->next;
      free(cur->email);
      free(cur->name);
      free(cur->fav_food);
      free(cur);
      cur = tmp;
    }  
  }
}
