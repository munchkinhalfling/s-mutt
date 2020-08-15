#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "listprop.h"
#include "strutils.h"

int main(int argc, char **argv) {
  char *properties[][2] = {
			   "folder", "\"imaps://imap.gmail.com:993\"",
			   "spoolfile", "\"+INBOX\"",
			   "postponed", "\"+[Gmail]/Drafts\"",
			   "header_cache", "~/.mutt/cache/headers",
			   "message_cachedir", "~/.mutt/cache/bodies",
			   "certificate_file", "~/.mutt/certificates",
			   "move", "no",
			   "imap_keepalive", "900",
			   "from", malloc(162*sizeof(char)),
			   "realname", malloc(82*sizeof(char)),
			   "imap_user", malloc(162*sizeof(char)),
			   "smtp_url", malloc(262*sizeof(char))
  };
  char *profilename = malloc(80*sizeof(char));
  char *profilepath = malloc(160*sizeof(char));
  char *dummystr = malloc(160*sizeof(char));
  char *longerdummystr = malloc(260*sizeof(char));
  char *curpropname = malloc(18*sizeof(char));
  char *curpropvalue = malloc(180*sizeof(char));
  FILE *conf_file;
  initscr();
  const char *HOME = getenv("HOME");
  const int PROPSLEN = 12;
  printw("What is the name of this profile? ");
  attron(A_BOLD);
  getnstr(profilename, 79);
  attroff(A_BOLD);
  printw("What is your name? ");
  attron(A_BOLD);
  getnstr(dummystr, 159);
  attroff(A_BOLD);
  setprop(properties, "realname", quote(dummystr), PROPSLEN);
  puts("What is your Gmail email address? ");
  attron(A_BOLD);
  getnstr(dummystr, 159);
  attroff(A_BOLD);
  setprop(properties, "from", quote(dummystr), 12);
  setprop(properties, "imap_user", quote(dummystr), 12);
  sprintf(longerdummystr, "\"smtp://%s@smtp.gmail.com:587\"", dummystr);
  setprop(properties, "smtp_url", longerdummystr, 12);
  sprintf(profilepath, "%s/.mutt-config/%s.muttrc", HOME, profilename);
  if((conf_file = fopen(profilepath, "w")) == NULL) {
    endwin();
    printf("Could not create configuration file at %s.\n", profilepath);
    exit(1);
  }
  for(register int i = 0; i < PROPSLEN; i++) {
    strcpy(curpropname, properties[i][0]);
    strcpy(curpropvalue, properties[i][1]);
    fprintf(conf_file, "set %s = %s\n", curpropname, curpropvalue);
  }
  fflush(conf_file);
  fclose(conf_file);
  attron(A_UNDERLINE);
  printw("Written to %s.\n", profilepath);
  attroff(A_UNDERLINE);
  free(dummystr);
  free(longerdummystr);
  free(profilename);
  free(profilepath);
  free(curpropname);
  free(curpropvalue);
  endwin();
  return 0;
}
