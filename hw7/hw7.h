#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct CustomerInfo {
  char *email;
  char *name;
  int shoe_size;
  char *fav_food;
} CustomerInfo;

typedef struct CustomerNode {
  char *key;
  CustomerInfo *val;
  struct CustomerNode *next;
} CustomerNode;

unsigned long hash(char*str);

CustomerNode *add_to_list(char *email, CustomerInfo data, CustomerNode *bucket);

void add_to_hashtable(char *email, CustomerInfo data, CustomerNode **buckets, size_t num_buckets);


