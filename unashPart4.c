#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define BUFBUMP 1024
char **split_line(char* line){
	int bufsize = BUFBUMP;

	char **tarray = malloc(sizeof(char) * bufsize);
	char *token;

	token = strtok(line, " ");
	int i = 0;
	while(token != NULL){
	   printf("%s\n", token);
	   tarray[i] = token;
	   i++;
	   token = strtok(NULL, " ");
	}
	tarray[i] = NULL;
	return tarray;	
}

char *read_line(void){
  int bufsize = BUFBUMP;
  int position = 0;
  char *carray = malloc(sizeof(char) * bufsize);
  int c;

  if(!carray){
    fprintf(stderr, "ERROR1: allocation point\n");
    exit(EXIT_FAILURE);
  }

  while(1){
   // Read a character
   c = getchar();

   // If we hit EOF, replace it with a null character and return
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

void loop(void){
	char *line;
	char** args;
	int i = 0;
	

	do{
 	  printf("csis> ");
	  line = read_line();
	  args = split_line(line);
	  i++;
	}while(1);
}

int main(int argc, char **argv){
	loop();

	return EXIT_SUCCESS;
}
