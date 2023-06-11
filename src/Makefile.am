## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = utilisateur_finale

utilisateur_finale_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	utilisateur.c utilisateur.h \
	fon.c fon.h \
	fonction.c fonction.h\
	BureauVote.c BureauVote.h

utilisateur_finale_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

