#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Returns true if the guess is an exact match with the secret word, but
// more importantly, fills in the result with the following:
// - 'x' goes in a slot if the corresponding letter in the guess does not appear
//   anywhere in the secret word
// - 'y' goes in a slot if the corresponding letter in the guess appears in the
//   secret word, but not in the corresponding slot
// - 'g' goes in a slot if the corresponding letter in the guess appears in the
//   corresponding slot in the secret word.
//   You can assume that result points at enough memory for a string of length
//   5. (ie, at least 6 bytes long)
bool score_guess(char *secret, char *guess, char *result) {
  // TODO(you): finish this function
  bool match;
  for (int index = 0; index < 6; index++) {
    if (guess[index] == secret[index]) {
      match = true;
      result[index] = 'g';
    } else if (strchr(secret, guess[index]) == NULL && guess[index] != secret[index]) {
      match = false;
      result[index] = 'y';
    } else {
      match = false;
      result[index] = 'x';
    }
  }
  return false;
}

// Returns true if the specified guess is one of the strings in the vocabulary,
// and false otherwise. num_words is the length of the vocabulary.
// A simple linear scan over the strings in vocabulary is fine for our purposes,
// but consider: could you do this search more quickly?
bool valid_guess(char *guess, char **vocabulary, size_t num_words) {
  // TODO(you): finish this function
  for (size_t i = 0; i < num_words; i++) {
    if (strcmp(guess, vocabulary[i]) == 0) {
      return true;
    }
  }
  return false;
}

// Returns an array of strings (so, char **), where each string contains a word
// from the specified file. The file is assumed to contain 5-letter words, one
// per line.
// Also, this function sets the value pointed at by *num_words to be the number
// of words read.
// This will need to allocate enough memory to hold all of the char* pointers --
// so you will keep track of the size of your char** array and then use realloc
// to make the array larger over time, so that you have enough space for the
// dynamically-growing array of char *.
// Use fopen to open the input file for reading,
// strdup (or strndup) to make copies of each word read from that file, and
// fclose to close the file when you are done reading from it.
// Each element of the array should be a single five-letter word,
// null-terminated.
char **load_vocabulary(char *filename, size_t *num_words) {
  /*char **out = NULL;
  out = calloc(2309, sizeof(char *));
  // TODO(you): finish this function
  printf("didnt segfault");
  FILE *infile;
  infile = fopen(filename, "r");

  for (int index = 0; index < 2309; index++) {
    test = fgets(*out, 7, infile);
    if (test == EOF) {
      break;
    }
    out[index] = test;
    num_words++;
  }
  fclose(infile);
  return out;*/

  *num_words = 0;
  char buf[500];
  char **out = NULL;
  size_t maxlen = 500;
  out = calloc(maxlen, sizeof(char *));

  FILE *infile;
  infile = fopen(filename, "r");
  while (fgets(buf, 7, infile) != NULL) {
    out[(*num_words)++] = strdup(buf);
    if (*num_words == maxlen) {
      void *tmp = realloc(out, maxlen * 2 * sizeof(*out));
      out = tmp;
      maxlen *= 2;
    }
  }
  fclose(infile);
  return out;
}

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  // TODO(you): finish this function
  for (size_t index = 0; index < num_words; index++) {
    free(vocabulary[index]);
  }
  free(vocabulary);
}

// Once your other functions are working, please revert your main() to its
// initial state, but please feel free to change it, during development. You'll
// want to test out each individual function!
int main(void) {
  char **vocabulary;
  size_t num_words;
  int num_guesses = 0;

  srand(time(NULL));
  
  // load up the vocabulary and store the number of words in it.
  vocabulary = load_vocabulary("vocabulary.txt", &num_words);
  
  for (int i = 0; i < 5; i++) {
    printf("%s\n", vocabulary[0]);
  }
  // Randomly select one of the words from the file to be today's SECRET WORD.
  int word_index = rand() % num_words;
  char *secret = vocabulary[word_index];

  // input buffer -- we'll use this to get a guess from the user.
  char guess[80];

  // buffer for scoring each guess.
  char result[6] = {0};
  bool success = false;

  printf("time to guess a 5-letter word! (press ctrl-D to exit)\n");
  while (!success) {
    printf("guess: ");
    if (fgets(guess, 80, stdin) == NULL) {
      break;
    }
    // Whatever the user input, cut it off at 5 characters.
    guess[5] = '\0';

    if (!valid_guess(guess, vocabulary, num_words)) {
      printf("not a valid guess\n");
      continue;
    } else {
      num_guesses++;
    }
    success = score_guess(secret, guess, result);
    printf("%s\n", guess);
    printf("%s\n", result);
  }

  if (success) {
    printf("you win, in %d guesses!\n", num_guesses);
  }
  free_vocabulary(vocabulary, num_words);

  return 0;
}
