#include "final.h"

#include <stdio.h>

size_t word_count(char *text) {
  // Your code here!
  // Count up all the words that occur in the given string. A new word starts
  // when you see a letter a-z or A-Z.

  int count = 0;
  int state = 0;

  while (*text != '\0') {
    if (*text == ' ' || *text == '\n' || *text == '\t' || !((*text >= 'a' && *text <= 'z') || (*text >= 'A' && *text <= 'Z'))) {
      state = 0;
    } else if (state == 0) {
      state = 1;
      ++count;
    }
    ++text;
  }
  return count;
}
