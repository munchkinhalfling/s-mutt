#include <string.h>
#include <stdlib.h>

char *quote(char *unquoted) {
  char *retval = malloc((strlen(unquoted)+2)*sizeof(char));
  sprintf(retval, "\"%s\"", unquoted);
  return retval;
}
