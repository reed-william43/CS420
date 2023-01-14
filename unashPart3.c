#include <stdlib.h>
#include <stdio.h>

#define BUFBUMP 1024
char *read_line(void)
{
  int bufsize = BUFBUMP;
  int position = 0;
  char *carray = malloc(sizeof(char) * bufsize);
  int c;

  if(!carray){
    fprintf(stderr, "allocation error\n");
    exit(EXIT_FAILURE);
  }

  while(1){
    // Read a character
    c = getchar();

    // If we hit EOF, replace it with a null character and return.
    if(c == EOF || c == '\n'){
      carray[position] = '\0';
      return carray;
    } else {
      carray[position] = c;
    }
    position++;

    // If we have exceeded the carray, reallocate.
    if(position >= bufsize){
      bufsize += BUFBUMP;
      carray = realloc(carray, bufsize);
      if(!carray){
	fprintf(stderr, "lsh: allocation error\n");
	exit(EXIT_FAILURE);
      }
    }
  }
}
