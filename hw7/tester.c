#include "hw7.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_BUCKETS 100

int main(void) {

  CustomerNode* buckets[NUM_BUCKETS] = {NULL};
 
  CustomerNode *newcust;

  newcust = malloc(sizeof(CustomerNode));
  newcust->email = (char *)malloc(50*sizeof(char *));
  newcust->name = (char *)malloc(50*sizeof(char *));
  newcust->fav_food = (char *)malloc(50*sizeof(char *));

  char line[150];

  FILE *infile = fopen("customers.tsv", "r");
  if (infile == NULL) {
    printf("no such file\n");
  }

  while (fgets(line, 150, infile) != NULL) {
    if (sscanf(line, "%50[^\t]\t%50[^\t]\t%d\t%50[^\n]", newcust->email, newcust->name, &newcust->shoe_size, newcust->fav_food) == 4) {
      add_to_hashtable(newcust->email, newcust->name, newcust->shoe_size, newcust->fav_food, buckets, NUM_BUCKETS);
      printf("email: %s\tname: %s\tshoe size: %d\tfav food: %s\n", newcust->email, newcust->name, newcust->shoe_size, newcust->fav_food);
    } else {
      printf("ERROR: missing email, name, shoe_size, or fav_food\n"); 
    }
  }

  while (1) {
    printf("command: ");
    char command[15];
    scanf("%s", command);

    if (strcmp(command, "quit") == 0) {
      break;
    } else if (strcmp(command, "save") == 0) {
      FILE *writefile = fopen("customers.tsv", "a");
      if (writefile == NULL) {
        printf("error opening file\n");
      }
      
      fprintf(writefile, "%s\t%s\t%d\t%s\n", newcust->email, newcust->name, newcust->shoe_size, newcust->fav_food);
      printf("%s\t%s\t%d\t%s\n", newcust->email, newcust->name, newcust->shoe_size, newcust->fav_food);
    }
  }
  
/*
  char *sammy = fav_food_for_customer("sammy@ucsc.edu", buckets, NUM_BUCKETS); 
  printf("%s\n", sammy);

  int sammy_size = 20;

  add_to_hashtable("sammy@ucsc.edu", "sammy", sammy_size, "slugs", buckets, NUM_BUCKETS);
  add_to_hashtable("jim@ucsc.edu", "jimothy", 12, "borgar", buckets, NUM_BUCKETS);

  char *sammy_food = fav_food_for_customer("sammy@ucsc.edu", buckets, NUM_BUCKETS);
  char *jim_food = fav_food_for_customer("jim@ucsc.edu", buckets, NUM_BUCKETS);
  printf("fav food for sammy@ucsc.edu: %s\n", sammy_food);
  printf("fav food for jim@ucsc.edu: %s\n", jim_food);
*/
  return 0;
}

