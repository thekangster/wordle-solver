#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv) {
  // You're going to have to use argc to decide whether to open up a file, or to
  // read from stdin.
  // If you haven't seen them before, you will likely want to use the functions
  // `fgetc()` and `fputc()`.
  
  if (argc >= 2) {
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
      printf("error no file\n");
    }
    
    char input[100];
    int c;
    while((c = fgetc(fp)) != EOF) {
      c = toupper(c);
      putchar(c);
    }
    fclose(fp);
  }
  
  char input[100];
  if (argc == 1) {
    scanf("%[^\n]s", input); 
    int i = 0;

    while (input[i]) {
      putchar(toupper(input[i]));
      i++;
    }
    printf("\n");
  }
  return 0;
}
