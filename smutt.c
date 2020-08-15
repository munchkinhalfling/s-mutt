#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

int main(int argc, const char **argv) {
  char *profile = malloc(80*sizeof(char));
  char *passwd = malloc(80*sizeof(char));
  char *profile_path = malloc(160*sizeof(char));
  char *muttrc_path = malloc(160*sizeof(char));
  register int i = 0;
  FILE *muttrc;
  FILE *profile_file;
  char file_char;
  char curpasschar;
  char *imap_pass = malloc(160*sizeof(char));
  char *smtp_pass = malloc(160*sizeof(char));
  int cursory;
  int cursorx;
start:
  initscr();
  printw("Enter name of profile ('new' for new profile): ");
  attron(A_BOLD);
  refresh();
  getnstr(profile, 79);
  attroff(A_BOLD);
  refresh();
  if(!strcmp(profile, "new")) {
    endwin();
    system("smutt.genconf");
    goto start;
  }
  noecho();
  printw("Enter password for profile '%s': ", profile);
  refresh();
  while(true) {
    getyx(stdscr, cursory, cursorx);
    curpasschar = getch();
    if(curpasschar == '\n') {break;}
    if(curpasschar == 127 || curpasschar == 8) {
      i--;
      move(cursory, cursorx-1);
      addch(' ');
      move(cursory, cursorx-1);
      refresh();
      continue;
    }
    addch('*' | A_BOLD);
    refresh();
    *(passwd + i) = curpasschar;
    i++;
  }
  

  sprintf(profile_path, "%s/.mutt-config/%s.muttrc", getenv("HOME"), profile);
  if((profile_file = fopen(profile_path, "r")) == NULL) {
    endwin();
    printf("Cannot open profile file. Please make sure it is at the path %s.", profile_path);
    exit(1);
  }
  sprintf(muttrc_path, "%s/.muttrc", getenv("HOME"));
  if((muttrc = fopen(muttrc_path, "w")) == NULL) {
    endwin();
    puts("Cannot create ~/.muttrc. Please make sure that it does not already exist.");
    exit(1);
  }
  while(!feof(profile_file)) {
    file_char = getc(profile_file);
    if(!feof(profile_file)) putc(file_char, muttrc);
  }
  fflush(muttrc);
  fclose(profile_file);
  sprintf(imap_pass, "\nset imap_pass = \"%s\"", passwd);
  sprintf(smtp_pass, "\nset smtp_pass = \"%s\"", passwd);
  fputs(imap_pass, muttrc);
  fputs(smtp_pass, muttrc);
  fflush(muttrc);
  fclose(muttrc);
  endwin();
  system("mutt");
  remove(muttrc_path);
  return 0;
}
