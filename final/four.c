#include "final.h"

#include <stdio.h>
#include <string.h>

// YOUR CODE GOES IN THIS FUNCTION!! Probably don't change the other ones.
WordCountTable *sum_word_count_tables(WordCountTable *table_a,
                                      WordCountTable *table_b) {

  // Your code here! You can change whatever you want in this function.
  // return an empty one just so we don't crash.
  WordCountTable *out = build_word_count_table(table_a->num_buckets);
  
  WordCountTable *tmp = build_word_count_table(table_a->num_buckets);
  WordCountNode *node_a;
  WordCountNode *node_b;
  
  int w_count;
  int a_count;
  int b_count;

  for (int i = 0; i < (int)table_a->num_buckets; i++) {
    node_a = table_a->buckets[i];
    while (node_a != NULL) {
      for (int j = 0; j < (int)table_b->num_buckets; j++) {
        node_b = table_b->buckets[j];
        while (node_b != NULL) {
          a_count = get_word_count(node_a->word, tmp);
          b_count = get_word_count(node_b->word, tmp);
          if (a_count != 1 && b_count != 1 && strcmp(node_b->word, node_a->word) == 0) {
            set_word_count(node_b->word, 1, tmp);
            set_word_count(node_b->word, node_a->count + node_b->count, out);
          } 
          node_b = node_b->next;
        }
      }
      node_a = node_a->next;
    }
  }
 
  WordCountNode *node_test;
  for (int i = 0; i < (int)tmp->num_buckets; i++) {
    node_test = tmp->buckets[i];
    while(node_test != NULL) {
      for (int j = 0; j < (int)table_a->num_buckets; j++) {
        node_a = table_a->buckets[j];
        while(node_a != NULL) {
          w_count = get_word_count(node_test->word, tmp);
          if (strcmp(node_a->word, node_test->word) != 0 && w_count != 1) {
            set_word_count(node_a->word, node_a->count, out);
          }
          node_a = node_a->next;
        }
      }
      node_test = node_test->next;
    }
  }

  for (int i = 0; i < (int)tmp->num_buckets; i++) {
    node_test = tmp->buckets[i];
    while(node_test != NULL) {
      for (int j = 0; j < (int)table_b->num_buckets; j++) {
        node_b = table_b->buckets[j];
        while(node_b != NULL) {
          w_count = get_word_count(node_test->word, tmp);
          if (strcmp(node_b->word, node_test->word) != 0 && w_count != 1) {
            set_word_count(node_b->word, node_b->count, out);
          }
          node_b = node_b->next;
        }
      }
      node_test = node_test->next;
    }
  }
  return out;
}

//// more functions, table infrastructure. Please don't change these.

// Thank you Dan Bernstein.
unsigned long hash(char *str) {
  unsigned long hash = 5381;
  int c;

  while (*str != '\0') {
    c = *str;
    hash = ((hash << 5) + hash) + (unsigned char)c; /* hash * 33 + c */
    str++;
  }
  return hash;
}

WordCountNode *set_word_count_in_list(char *word, int count,
                                      WordCountNode *bucket) {
  WordCountNode *new_node;

  new_node = malloc(sizeof(WordCountNode));
  new_node->word = strdup(word);
  new_node->count = count;
  new_node->next = bucket;
  return new_node;
}

void set_word_count(char *word, int count, WordCountTable *table) {
  size_t which_bucket = hash(word) % table->num_buckets;

  // We're going to "overwrite" the previous value here (if it exists) by simply
  // putting a new value at the front of the linked list in the appropriate
  // bucket. This is faster and simpler, but will use more memory.
  table->buckets[which_bucket] =
      set_word_count_in_list(word, count, table->buckets[which_bucket]);
}

// Construct an empty WordCountTable.
WordCountTable *build_word_count_table(size_t num_buckets) {
  WordCountTable *out;

  out = calloc(1, sizeof(WordCountTable));
  out->num_buckets = num_buckets;

  // bunch of NULL pointers to WordCountNode.
  out->buckets = calloc(num_buckets, sizeof(WordCountNode *));
  return out;
}

int get_word_count_in_list(char *word, WordCountNode *node) {
  if (node == NULL) {
    return 0;
  }

  if (strcmp(word, node->word) == 0) {
    return node->count;
  }
  return get_word_count_in_list(word, node->next);
}

int get_word_count(char *word, WordCountTable *table) {
  size_t which_bucket = hash(word) % table->num_buckets;

  return get_word_count_in_list(word, table->buckets[which_bucket]);
}
