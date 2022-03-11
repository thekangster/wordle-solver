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
    if (sscanf(line, " %50[^\t]\t%50[^\t]\t%d\t%50[^\n]", newcust->email, newcust->name, &newcust->shoe_size, newcust->fav_food) == 4) {
      add_to_hashtable(newcust->email, newcust->name, newcust->shoe_size, newcust->fav_food, buckets, NUM_BUCKETS);
      printf("email: %s\tname: %s\tshoe size: %d\tfav food: %s\n", newcust->email, newcust->name, newcust->shoe_size, newcust->fav_food);
    } else {
      printf("ERROR: missing email, name, shoe_size, or fav_food\n"); 
    }
  }
  
  CustomerNode *add_cust = NULL;
  
  while (1) {
    printf("command: ");
    char command[10];
    scanf("%s", command);
    
    if (strcmp(command, "quit") == 0) {
      break;
    } else if (strcmp(command, "add") == 0) {
      add_cust = malloc(sizeof(CustomerNode));
      add_cust->email = (char *)malloc(50*sizeof(char *));
      add_cust->name = (char *)malloc(50*sizeof(char *));
      add_cust->fav_food = (char *)malloc(50*sizeof(char *));
      printf("email address? ");
      scanf(" %[^\n\t]s", add_cust->email);
      printf("name? ");
      scanf(" %[^\n\t]s", add_cust->name);
      printf("shoe size? ");
      scanf("%d", &add_cust->shoe_size);
      printf("favorite food? ");
      scanf(" %[^\n\t]s", add_cust->fav_food);
      add_to_hashtable(add_cust->email, add_cust->name, add_cust->shoe_size, add_cust->fav_food, buckets, NUM_BUCKETS);
    } else if (strcmp(command, "save") == 0) {
      FILE *writefile = fopen("customers.tsv", "w");
      if (writefile == NULL) {
        printf("error opening file\n");
      }
      if (add_cust == NULL) {
        printf("add cust is null\n");
        continue;
      }
      CustomerNode *node;
      for (int i = 0; i < (int)NUM_BUCKETS; i++) {
        node = buckets[i];
        while(node != NULL) {
          fprintf(writefile, "%s\t%s\t%d\t%s\n", node->email, node->name, node->shoe_size, node->fav_food);
          node = node->next;
        }
      }

      fclose(writefile);
      printf("%s\t%s\t%d\t%s\n", add_cust->email, add_cust->name, add_cust->shoe_size, add_cust->fav_food);
    } else if (strcmp(command, "lookup") == 0) {
      printf("email address? ");
      char *email_input = malloc(sizeof(char *));
      scanf(" %[^\n\t]s", email_input);
      lookup_customer(email_input, buckets, NUM_BUCKETS);
    } else if (strcmp(command, "list") == 0) {
      list_customers(buckets, NUM_BUCKETS);
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

