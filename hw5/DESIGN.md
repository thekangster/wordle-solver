
# homework 5: strings, searching, words

This is the design document for homework 5.

# how the program works

This program is a version of wordle, a word-guessing game. The player must guess a 5-letter word for each turn and the game compares the guess to the secret word. After the guess, the program returns a response that can either be a gray, yellow, or green square in the place of the corresponding letter in the word. A gray square indicates the letter does not appear in the secret word, yellow indicates the letter appears in the secret word but not in that corresponding slot, and green indicates the corresponding letter appears in the secret word in that slot. 

# pseudocode
```
score_guess
  initialize bool match
  for index up to 6
    if guess[index] equals secret[index]
      set match to true
      set result[index] to g
    else if strchr(secret, guess[index]) not equal to NULL and guess[index] not equal to secret[index]
      set match to false
      set result[index] to y
    else
      set match to false
      set result[index] to x
  return match

valid_guess
  for index up to num_words
    if strcmp(guess, vocabulary[index]) == 0
      return true
  return false 

load_vocabulary
  set char **out to calloc(2309 * sizeof(char *))
  set infile to fopen(filename, "r")
  set index to 0
  while(1)
    set s to fgets(**out, 7, filename)
    if s is EOF
      break
    set **out[index] to s
  fclose(filename)

free_vocabulary
  for index up to num_words
    free(vocabulary[index])
  free(vocabulary)
```    
