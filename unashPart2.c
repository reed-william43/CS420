#include "unashPart3.c"

#include <stdio.h>
#include <stdlib.h>

void loop(void){
	int c;
	printf("csis> ");

	do{
	  c = getchar();
	  if(c!='\n' && c!=EOF){
		 putchar(c);
		 printf("\n");
		 printf("csis> ");
	  }
	} while(1);
}

int main(int argc, char **argv){
	loop();

	return EXIT_SUCCESS;
}
