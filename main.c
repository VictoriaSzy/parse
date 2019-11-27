#include "main.h"

char ** parse_args(char * line) {
  char ** args = malloc(500) ; // I got strange characters and question marks when I used less than 400 in the malloc...
  char * current = strsep(&line, " ") ;
  printf("Here is the command with its arguments: \n") ;
  int x = 0 ;
  while (current) {
    printf("%s\n", current) ;
    args[x] = current ;
    // keep going to check for more arguments
    current = strsep(&line, " ") ;
    x++ ;
  }
  return args ;
}

int main() {
  /*
  From stuycs.org:
  char line[100] = "woah-this-is-cool" ;
  char *curr = line ;
  char * token ;
  token = strsep( &curr, "-") ;
  --------------------------------------------------
  char line[100] = "woah-this-is-cool" ;
  char *s1 = line ;
  printf("[%s]\n", strsep( &s1, "-" )) ;
  printf("[%s]\n", s1) ;*/

  char line[100] = "ls -a -l" ;
  char ** args = parse_args(line) ;
  printf("\nWe are now executing!\n\n") ;
  execvp(args[0], args) ;
  //printf("Here is the result: %p\n", args) ;
  return 0 ;
}
