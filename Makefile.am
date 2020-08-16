AUTOMAKE_OPTIONS = foreign
bin_PROGRAMS = smutt smutt.genconf
smutt_SOURCES = smutt.c
smutt_genconf_SOURCES = genconf/genconf.c

package: all
	cp smutt pkgdir/
	cp smutt.genconf pkgdir/
	cp -r pkgdir $(distdir)-bin
	tar -c $(distdir)-bin -f $(distdir)-bin.tar
	gzip $(distdir)-bin.tar
	rm -rf $(distdir)-bin