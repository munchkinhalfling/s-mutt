#include <stdio.h>
#include <string.h>

char *mygetline(int len) {
  char *basestr = malloc(len*sizeof(char));
  fgets(basestr, len, stdin);
  *(basestr + (strlen(basestr)-1)) = '\0';
  return basestr;
}
