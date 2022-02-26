
# homework 6: strings, searching, pointers

This is the design document for homework 6. 

# how the program works

In this homework, we implimenta solver the Wordle by filtering through the bank of words, judged by the score we calculate for it. The way we calculate the score for each word in the vocabulary list, we have score how many times a unique letter occurs in the word bank. 

To limit the vocabulary based on gray responses, we will filter the words in vocabulary by removing all words that contain that letter. To remove the word, we simply free the string and set the pointer to that word to NULL.

To limit the vocabulary based on yellow responses, we eliminate any word that does not contain that particular letter. We also eliminate the words that contain the letter in the specific spot that was guessed.

To limit the vocabulary based on green responses, we eliminate the word from the vocabulary that does not contain the specified letter in the specified spot.

# pseudocode

score letter
  set count var to 0
  for index to 6
    if letter is in vocab[index]
      increment count
  return count

score word
  initialize score to 0
  set num var
  set seen bitvector
  initialize letter pointer of size 2
  for i up to 5
    letter[0] = word[i]
    set num to strtol(letter, NULL, 36) - 10
    if letter_scores[num] is greater than 0 and seen[i] is 0
      set score to score + letter_scores[num]
    for j up to 5
      if word[i] equals word[j]
        set seen[i] to 1
        set seen[j] to 1
  return score

filter_vocabulary_gray
  set filtered to 0
  for i up to num_words
    if vocab[i] is NULL
      continue
    if letter is not in vocab[i]
      free vocab[i]
      set vocab[i] to NULL
      increment filtered
  return filtered

filter_vocabulary_words
  set filtered to 0
  for i up to num_words
    if vocab[i] is NULL
      continue
    if letter is not in vocab[i]
      free vocab[i]
      set vocab[i] to NULL
      increment filtered
    else if letter is in vocab[i] and vocab[i][position] equals letter
      free vocab[i]
      set vocab[i] to NULL
      increment filtered
    return filtered

filter_vocabulary_green
  set filtered to 0
  for i is up to num_words
    if vocab[i] is NULL
      continue
    if letter is not in vocab[i]
      free vocab[i]
      set vocab[i] to NULL
      increment filtered
    else if letter is in vocab[i] and vocab[i][position] is not letter
      free vocab[i]
      set vocab[i] to NULL
      increment filtered
  return filtered
