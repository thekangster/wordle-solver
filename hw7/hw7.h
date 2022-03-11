#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct CustomerNode {
  char *email;  // the key
  char *name;   // value 
  int shoe_size; // value
  char *fav_food; // value
  struct CustomerNode *next;
} CustomerNode;

unsigned long hash(char*str);

CustomerNode *add_to_list(char *email, char *name, int shoe_size, char *fav_food, CustomerNode *bucket);

void add_to_hashtable(char *email, char *name, int shoe_size, char *fav_food, CustomerNode **buckets, size_t num_buckets);

void lookup_customer(char *email, CustomerNode **buckets, size_t num_buckets);

void delete_customer(char *email, CustomerNode **buckets, size_t num_buckets);

void list_customers(CustomerNode **buckets, size_t num_buckets);

void delete_hashtable(CustomerNode **buckets, size_t num_buckets);
