#include <stdio.h>
#include <string.h>

extern void *malloc(unsigned long);
extern void free(void *);

int main(int argc, char **argv) {
  char *mypass = malloc(80);
  char c;
  register int i = 0;
  
  while(1) {
    c = getc(stdin);
    fseek(stdout, ftell(stdout) - 1, SEEK_SET);
    if(c == 0x0A) break; // Enter
    if(c == 8) { // Delete
      fseek(stdout, ftell(stdout) - 1, SEEK_SET);
      putc(' ', stdout);
      *(mypass + (--i)) = '\0';
      continue;
    }
    putc('*', stdout);
    *(mypass+(i++)) = c;
  }

  printf("The passworfsd you entered was %s.", mypass);
}
