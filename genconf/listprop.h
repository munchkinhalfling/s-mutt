#include <string.h>

char *getprop(char *list[][2], char *name, int listlen) {
  for(register int i = 0; i < listlen; i++) {
    if(!strcmp(list[i][0], name)) return list[i][1];
  }
  return "";
}

void setprop(char *list[][2], char *name, char *value, int listlen) {
  for(register int i = 0; i < listlen; i++) {
    if(!strcmp(list[i][0], name)) strcpy(list[i][1], value);
  }
}
