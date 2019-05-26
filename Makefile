smutt:
	gcc smutt.c -o bin/smutt -lncurses
genconf:
	gcc genconf/genconf.c -o bin/genconf -lncurses -I./genconf/
smutt-arm:
	gcc smutt.c -o bin/smutt-arm -lncurses
genconf-arm:
	gcc genconf/genconf.c -o bin/genconf-arm -lncurses -I./genconf/
intel: smutt genconf
arm: smutt-arm genconf-arm
all: intel arm
install-base:
	rm $(HOME)/.muttrc;\
echo export PATH=\$$PATH:`pwd`/bin >> $(HOME)/.bashrc;\
	. $(HOME)/.bashrc
install-arm: arm install-base
	mv bin/smutt-arm bin/smutt;\
	mv bin/genconf-arm bin/smutt.genconf
install-intel: intel install-base
	mv bin/genconf bin/smutt.genconf
