#include "final.h"

#include <stdio.h>

// citation: geeksforgeeks
int getLevel(int data, BinaryTree *tree, int level) {
  if (tree == NULL) {
    return -1;
  }

  if (tree->val == data) {
    return level;
  }

  int downlevel = getLevel(data, tree->left, level+1);

  if (downlevel != -1) {
    return downlevel;
  }

  downlevel = getLevel(data, tree->right, level+1);
  return downlevel;
}

int depth_of_value(int value, BinaryTree *tree) {
  // Your code here!
  // Remember -- return 0 if the value is found at the root node, and -1 if the
  // value is not found in the tree at all.
  // You don't have to handle trees where the same value occurs more than once,
  // but if it does happen, you ought to return the shallowest depth of that
  // value.
  // Also remember that this is just a binary tree, not a binary *search* tree.
  
  return getLevel(value, tree, 0);
}


