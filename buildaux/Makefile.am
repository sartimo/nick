ICK_SPECIFIC_SUBDIR = ick-@PACKAGE_VERSION@
ickincludedir = $(includedir)/$(ICK_SPECIFIC_SUBDIR)
ickdatadir = $(datadir)/$(ICK_SPECIFIC_SUBDIR)

AM_CFLAGS = '-DICKINCLUDEDIR="$(ickincludedir)"' \
            '-DICKDATADIR="$(ickdatadir)"' \
            '-DICKBINDIR="$(bindir)"' '-DICKLIBDIR="$(libdir)"' \
            -DYYDEBUG -DICK_HAVE_STDINT_H=@HAVE_STDINT_H@
AM_CPPFLAGS = -I$(srcdir)/src

bin_PROGRAMS = ick convickt
ick_SOURCES = src/feh2.c src/dekludge.c src/ick_lose.c \
              src/fiddle.c src/perpet.c src/uncommon.c
nodist_ick_SOURCES = parser.y lexer.l
parser.y : src/parser.y
	$(LN_S) -f `test -f 'src/parser.y' || echo '$(srcdir)/'`src/parser.y parser.y
lexer.l : src/lexer.l
	$(LN_S) -f `test -f 'src/lexer.l' || echo '$(srcdir)/'`src/lexer.l lexer.l
ick-wrap.c : src/ick-wrap.c
	$(LN_S) -f `test -f 'src/ick-wrap.c' || echo '$(srcdir)/'`src/ick-wrap.c ick-wrap.c
pickwrap.c : src/pickwrap.c
	$(LN_S) -f `test -f 'src/pickwrap.c' || echo '$(srcdir)/'`src/pickwrap.c pickwrap.c
syslib.i : pit/lib/syslib.i
	$(LN_S) -f `test -f 'pit/lib/syslib.i' || echo '$(srcdir)/'`pit/lib/syslib.i syslib.i
syslib3.3i : pit/lib/syslib3.3i
	$(LN_S) -f `test -f 'pit/lib/syslib.3i' || echo '$(srcdir)/'`pit/lib/syslib3.3i syslib3.3i
syslib4.4i : pit/lib/syslib4.4i
	$(LN_S) -f `test -f 'pit/lib/syslib.4i' || echo '$(srcdir)/'`pit/lib/syslib4.4i syslib4.4i
syslib5.5i : pit/lib/syslib5.5i
	$(LN_S) -f `test -f 'pit/lib/syslib.5i' || echo '$(srcdir)/'`pit/lib/syslib5.5i syslib5.5i
syslib6.6i : pit/lib/syslib6.6i
	$(LN_S) -f `test -f 'pit/lib/syslib.6i' || echo '$(srcdir)/'`pit/lib/syslib6.6i syslib6.6i
syslib7.7i : pit/lib/syslib7.7i
	$(LN_S) -f `test -f 'pit/lib/syslib.7i' || echo '$(srcdir)/'`pit/lib/syslib7.7i syslib7.7i
floatlib.i : pit/lib/floatlib.i
	$(LN_S) -f `test -f 'pit/lib/floatlib.i' || echo '$(srcdir)/'`pit/lib/floatlib.i floatlib.i
ecto_b98.c : pit/explib/ecto_b98.c
	$(LN_S) -f `test -f 'pit/explib/ecto_b98.c' || echo '$(srcdir)/'`pit/explib/ecto_b98.c ecto_b98.c
ick_ec.h : src/ick_ec.h
	$(LN_S) -f `test -f 'src/ick_ec.h' || echo '$(srcdir)/'`src/ick_ec.h ick_ec.h
ick_lose.h : src/ick_lose.h
	$(LN_S) -f `test -f 'src/ick_lose.h' || echo '$(srcdir)/'`src/ick_lose.h ick_lose.h
fiddle.h : src/fiddle.h
	$(LN_S) -f `test -f 'src/fiddle.h' || echo '$(srcdir)/'`src/fiddle.h fiddle.h
ick_bool.h : src/ick_bool.h
	$(LN_S) -f `test -f 'src/ick_bool.h' || echo '$(srcdir)/'`src/ick_bool.h ick_bool.h
yuk.h : src/yuk.h
	$(LN_S) -f `test -f 'src/ick-ec.h' || echo '$(srcdir)/'`src/yuk.h yuk.h
ick_LDADD = libidiot.a
AM_YFLAGS = -d
# BUILT_SOURCES is used both to make sure parser.h is built early, and to
# create symlinks used by ick to find files if it's run without first being
# installed.
BUILT_SOURCES = parser.h ick-wrap.c pickwrap.c syslib.i syslib3.3i \
		syslib4.4i syslib5.5i syslib6.6i syslib7.7i floatlib.i \
		ecto_b98.c ick_ec.h fiddle.h ick_bool.h ick_lose.h yuk.h
noinst_LIBRARIES = libidiot.a
libidiot_a_SOURCES = src/idiotism.oil
libidiot.a: src/idiotism.oil oil$(EXEEXT) src/oil.h src/sizes.h src/ick.h \
	    parser.h src/fiddle.h src/ick_lose.h src/feh.h
	./oil$(EXEEXT) < `test -f 'src/idiotism.oil' || echo '$(srcdir)/'`src/idiotism.oil
	for oo in oilout*.c; do echo $$oo; $(COMPILE) -c $$oo; done
	$(AR) $(ARFLAGS) libidiot.a oilout*.o
	$(RANLIB) libidiot.a
convickt_SOURCES = src/convickt.c src/clc-cset.c src/uncommon.c

@INCLUDE_HIDDEN_FROM_AUTOMAKE@ ./host.mak

noinst_PROGRAMS = oil bin2c
oil_SOURCES = src/oil.y
oil_YFLAGS =
bin2c_SOURCES = src/bin2c.c
oil$(EXEEXT_FOR_BUILD): src/oil-oil.c bconfig.h
	$(CC_FOR_BUILD) $(DEFAULT_INCLUDES) $(INCLUDES) $(CFLAGS_FOR_BUILD) $(CPPFLAGS_FOR_BUILD) $(LDFLAGS_FOR_BUILD) -o oil$(EXEEXT_FOR_BUILD) src/oil-oil.c $(LIBS_FOR_BUILD)
bin2c$(EXEEXT_FOR_BUILD): src/bin2c.c bconfig.h
	$(CC_FOR_BUILD) $(DEFAULT_INCLUDES) $(INCLUDES) $(CFLAGS_FOR_BUILD) $(CPPFLAGS_FOR_BUILD) $(LDFLAGS_FOR_BUILD) -o bin2c$(EXEEXT_FOR_BUILD) `test -f 'src/bin2c.c' || echo '$(srcdir)/'`src/bin2c.c $(LIBS_FOR_BUILD)
oil$(EXEEXT):
bin2c$(EXEEXT):

# Optional libraries are in lib_LIBRARIES, but with a null build rule.
lib_LIBRARIES = libick.a libickmt.a libickec.a libyuk.a libick_ecto_b98.a
libick_ecto_b98_a_SOURCES =
libick_ecto_b98.a: etc/libick_ecto_b98.a
	-(test -f etc/libick_ecto_b98.a || test -f $(srcdir)/etc/libick_ecto_b98.a) && $(LN_S) -f `test -f 'etc/libick_ecto_b98.a' || echo '$(srcdir)/'`etc/libick_ecto_b98.a libick_ecto_b98.a
etc/libick_ecto_b98.a:
libick_a_SOURCES = src/cesspool.c src/numerals.c src/ick_lose.c src/fiddle.c \
                   src/arrgghh.c src/clc-cset.c src/uncommon.c
libick_a_LIBADD = atari.o baudot.o ebcdic.o latin1.o
libickmt_a_SOURCES = src/cesspool.c src/numerals.c src/ick_lose.c src/fiddle.c \
                     src/arrgghh.c src/clc-cset.c src/uncommon.c src/unravel.c
libickmt_a_LIBADD = atari.o baudot.o ebcdic.o latin1.o
libickec_a_SOURCES = src/cesspool.c src/numerals.c src/ick_lose.c src/fiddle.c \
                     src/arrgghh.c src/clc-cset.c src/uncommon.c src/ick_ec.c
libickec_a_LIBADD = atari.o baudot.o ebcdic.o latin1.o
libyuk_a_SOURCES = src/yuk.c
atari.o: bin2c$(EXEEXT_FOR_BUILD) src/atari.bin
	./bin2c$(EXEEXT_FOR_BUILD) ick_clc_cset_atari < `test -f 'src/atari.bin' || echo '$(srcdir)/'`src/atari.bin > atari.c
	$(COMPILE) -c atari.c
baudot.o: bin2c$(EXEEXT_FOR_BUILD) src/baudot.bin
	./bin2c$(EXEEXT_FOR_BUILD) ick_clc_cset_baudot < `test -f 'src/baudot.bin' || echo '$(srcdir)/'`src/baudot.bin > baudot.c
	$(COMPILE) -c baudot.c
ebcdic.o: bin2c$(EXEEXT_FOR_BUILD) src/ebcdic.bin
	./bin2c$(EXEEXT_FOR_BUILD) ick_clc_cset_ebcdic < `test -f 'src/ebcdic.bin' || echo '$(srcdir)/'`src/ebcdic.bin > ebcdic.c
	$(COMPILE) -c ebcdic.c
latin1.o: bin2c$(EXEEXT_FOR_BUILD) src/latin1.bin
	./bin2c$(EXEEXT_FOR_BUILD) ick_clc_cset_latin1 < `test -f 'src/latin1.bin' || echo '$(srcdir)/'`src/latin1.bin > latin1.c
	$(COMPILE) -c latin1.c

ickinclude_HEADERS = src/ick_ec.h src/fiddle.h src/ick_lose.h src/yuk.h \
                     src/ick_bool.h
nodist_ickinclude_HEADERS = config.h abcess.h
dist_ickdata_DATA = src/atari.bin src/baudot.bin src/ebcdic.bin src/latin1.bin \
                    src/ick-wrap.c src/pickwrap.c COPYING
# These necessary pit files are in nodist_ here because they're in EXTRA_DIST
# later along with the rest of the pit.
nodist_ickdata_DATA = pit/lib/syslib.i pit/lib/syslib3.3i pit/lib/syslib4.4i \
                      pit/lib/syslib5.5i pit/lib/syslib6.6i pit/lib/syslib7.7i \
                      pit/lib/floatlib.i coopt.sh pit/explib/syslibc.c \
                      pit/explib/compunex.c pit/explib/ecto_b98.c
dist_man1_MANS = doc/ick.1 doc/convickt.1
info_TEXINFOS = doc/ick.txi

# How to run splint on this code
SPLINTOPTS = -I. -I$(top_srcdir)/src +quiet -warnposix -boolops -predboolint
splint: $(ick_SOURCES) src/parser.h
	@echo "Running splint on ick..."
	-(for x in $(ick_SOURCES); do echo $(top_srcdir)/$$x; done) | xargs splint $(SPLINTOPTS) -exportlocal -redef

EXTRA_DIST = pit etc BUGS src/abcessh.in src/feh.h src/fiddle.h src/ick_ec.h \
             src/ick.h src/ick_lose.h src/oil.h src/pick1.h src/pick2.h \
             src/sizes.h src/uncommon.h src/yuk.h src/parser.y src/lexer.l \
             doc/Makefile doc/fdl-1-2.txi doc/fix83.pl doc/fixtoc.pl \
             doc/ickstyle.css doc/ick.txt doc/intercal.mm doc/READ.ME \
             doc/THEORY.txt doc/tidy.cfg src/parser.c src/parser.h \
             src/lexer.c control doc/ick.txi doc/ick.txt doc/chipspec.txt \
             HISTORY NEWS README buildaux/buildconfig buildaux/buildconfig.ac \
             buildaux/depcomp buildaux/hostmak.in buildaux/install-sh \
             buildaux/missing buildaux/ylwrap buildaux/bconfigh.in

# It's ugly to distribute the prebuilt files in the root of the
# distribution.  configure will move these files back again into the
# root of the /build tree/, which makes a lot more sense than putting
# them in the root of the source tree. Also, make sure not to
# distribute executables lying around in the pit from previous tests.
dist-hook:
	$(MKDIR_P) $(distdir)/prebuilt
	mv $(distdir)/src/parser.c $(distdir)/prebuilt
	mv $(distdir)/src/parser.h $(distdir)/prebuilt
	mv $(distdir)/src/lexer.c $(distdir)/prebuilt
	mv $(distdir)/src/oil-oil.c $(distdir)/prebuilt
	-find $(distdir)/pit -perm -u+x -type f -and -not -name regresscheck | xargs rm
	touch $(distdir)/MANIFEST
	(cd $(distdir); find . | sort > MANIFEST)

# N.B. the parser.y, lexer.l, libraries, headers and skeletons are the
# links made to simplify the build, not the originals
CLEANFILES = oilout*.c parser.y lexer.l ick-wrap.c pickwrap.c \
             atari.c baudot.c ebcdic.c latin1.c ick.dvi \
             syslib.i syslib3.3i syslib4.4i syslib5.5i \
             syslib6.6i syslib7.7i ick_ec.h fiddle.h \
             ick_lose.h yuk.h floatlib.i ecto_b98.c ick_bool.h
# Distclean deletes the Makefile and thus requires reconfiguring,
# and therefore this is a safe moment to delete the build tree
# versions of the prebuilt files. (The source tree versions will
# be safe in the prebuilt dir, which Automake doesn't even know
# about.)
DISTCLEANFILES = src/parser.c src/parser.h src/lexer.c src/oil-oil.c host.mak bconfig.h config.status.build

distclean-local:
	mkdir -p src
	rm -rf src/.deps
	-rmdir src       # this should be empty iff out-of-tree

# A veryclean is a distclean that removes /all/ generated files,
# even the ones that are part of the distributed system
veryclean: distclean
	rm -f $(top_srcdir)/buildaux/buildconfig
	rm -f $(top_srcdir)/buildaux/depcomp
	rm -f $(top_srcdir)/buildaux/install-sh
	rm -f $(top_srcdir)/buildaux/missing
	rm -f $(top_srcdir)/buildaux/ylwrap
	rm -f $(top_srcdir)/buildaux/ar-lib
	rm -f $(top_srcdir)/buildaux/compile
	rm -f $(top_srcdir)/buildaux/Makefile.in
	rm -f $(top_srcdir)/buildaux/bconfigh.in
	rm -f $(top_srcdir)/buildaux/configh.in
	rm -f $(top_srcdir)/aclocal.m4
	rm -f $(top_srcdir)/configure
	rm -rf $(top_srcdir)/autom4te.cache
	rm -rf $(top_srcdir)/buildaux/autom4te.cache

# Clean the pit test binaries on toplevel make clean
clean-local:
	if [ -d pit ]; then cd pit; make clean; fi


# A subtle yet potentially common issue: ick favours the install location over
# the build-directory or current-directory locations for its data files; this
# means that we can easily test against the wrong version of libick.
# It would be nice to compare the file contents, but this doesn't work in
# practice; it's possible that the installed version is stripped and the
# non-installed version is unstripped (yet they match). Instead, we use the
# crude heuristic of comparing modification times; an old installed version
# will be older than an uninstalled version, whereas a version installed from
# the current sources can be no older (and typically is newer)
verify-libick-version: $(lib_LIBRARIES)
	@list='$(lib_LIBRARIES)'; \
	for p in $$list; do \
	test ! -f $(DESTDIR)$(libdir)/$$p || test ! $(DESTDIR)$(libdir)/$$p -ot $$p || \
	( \
	    echo "Error: You have an old installed version of $$p."; \
	    echo "This makes it impossible to test ick, as it will look at the"; \
	    echo "installed version, not the version that was just built."; \
	    echo "Run make install or make uninstall."; \
	    false; \
	) || \
	exit 1; \
	done

# Make self-tests available in the standard way
# The pit has to be writable for the tests to work, unfortunately...
check-am: ick$(EXEEXT) verify-libick-version
	chmod u+w $(top_srcdir)/pit
	chmod u+w $(top_srcdir)/pit/lib
	chmod u+w $(top_srcdir)/pit/tests
	make -f $(top_srcdir)/pit/Makefile ICKENV="" ICK="./ick$(EXEEXT)" ICKOPTS="-b" PIT=$(top_srcdir)/pit test

# Run the fuzztest
fuzz: ick$(EXEEXT) src/idiotism.oil $(top_srcdir)/etc/interfuzz.pl verify-libick-version
	ICK="./ick$(EXEEXT)" IDIOTISM="$(top_srcdir)/src/idiotism.oil" perl $(top_srcdir)/etc/interfuzz.pl

# Run regression tests, fuzz tests and build tests
test: fuzz distcheck

# If a documentation file is needed but not available, invoke the doc
# makefile to build it.
doc/ick.txt: doc/ick.txi
	cd $(top_srcdir)/doc && make ick.txt

echo-version:
	@echo @PACKAGE_VERSION@

# The build system itself is included in the makefile; tell Automake
# about the buildaux tweaking.
$(top_srcdir)/buildaux/buildconfig: $(top_srcdir)/buildaux/buildconfig.ac $(top_srcdir)/buildaux/bconfigh.in
	cd $(top_srcdir) && $(AUTOCONF) buildaux/buildconfig.ac > buildaux/buildconfig
	chmod a+x $(top_srcdir)/buildaux/buildconfig
$(top_srcdir)/buildaux/bconfigh.in: $(top_srcdir)/buildaux/buildconfig.ac
	cd $(top_srcdir)/buildaux && $(AUTOHEADER) buildconfig.ac
	rm -f stamp-h1
	touch $@
CONFIG_STATUS_DEPENDENCIES=$(top_srcdir)/buildaux/buildconfig $(top_srcdir)/buildaux/bconfigh.in $(top_srcdir)/src/abcessh.in

# Ship a release
release: intercal-$(VERSION).tar.gz
	shipper version=$(VERSION) | sh -e -x
	cd website; upload
