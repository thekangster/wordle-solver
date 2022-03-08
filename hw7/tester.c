#include "hw7.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_BUCKETS 100

int main(void) {

  CustomerNode *newcust
  FILE *infile = fopen("customers.tsv", "r");
  while (fscanf(infile, " %50[^\t]\t%50[^\t]\t%d\t%50[^\n]",  




  
  CustomerNode* buckets[NUM_BUCKETS] = {NULL};
  int sammy_size = 20;
  
  add_to_hashtable("sammy@ucsc.edu", "sammy", sammy_size, "slugs", buckets, NUM_BUCKETS);
  add_to_hashtable("jim@ucsc.edu", "jimothy", 12, "borgar", buckets, NUM_BUCKETS);

  char *sammy_food = fav_food_for_customer("sammy@ucsc.edu", buckets, NUM_BUCKETS);
  char *jim_food = fav_food_for_customer("jim@ucsc.edu", buckets, NUM_BUCKETS);
  printf("fav food for sammy@ucsc.edu: %s\n", sammy_food);
  printf("fav food for jim@ucsc.edu: %s\n", jim_food);

  return 0;
}

