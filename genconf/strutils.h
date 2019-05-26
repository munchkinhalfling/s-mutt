#include <stdlib.h>
#include <string.h>

char *quote(char *str) {
  int len = strlen(str);
  char *newstr = malloc(len + 3);
  *(newstr+0) = '\"';
  *(newstr+(strlen(newstr) - 2)) = '\"';
  for(register int i = 1; i < len+1; i++) {
    *(newstr+i) = *(str+(i-1));
  }
  return newstr;
}
