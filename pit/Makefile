#
# Torture-tester for the INTERCAL compiler
#
# Type 'make' to test-compile the pit programs and run a regression check

ICKENV = ICKINCLUDEDIR=../src ICKCSKELDIR=../src ICKSYSDIR=lib ICKLIBDIR=..
ICK = ../ick
ICKOPTS = -b
PIT = .

BASE2SOURCES = \
	$(PIT)/beer.i \
	$(PIT)/bubble.i \
	$(PIT)/change.i \
	$(PIT)/flonck.i \
	$(PIT)/fft.i \
	$(PIT)/guess.i \
	$(PIT)/icat.i \
	$(PIT)/iching1.i \
	$(PIT)/iching2.i \
	$(PIT)/ins.i \
	$(PIT)/interfunge \
	$(PIT)/lib/lib2.i \
	$(PIT)/lib/numio.i \
	$(PIT)/lib/plus.i \
	$(PIT)/lib/syslib.i \
	$(PIT)/lib/syslib3.i \
	$(PIT)/lib/syslib4.i \
	$(PIT)/lib/syslib5.i \
	$(PIT)/lib/syslib6.i \
	$(PIT)/lib/syslib7.i \
	$(PIT)/life.i \
	$(PIT)/life2.i \
	$(PIT)/pi.i \
	$(PIT)/pow.i \
	$(PIT)/quine \
	$(PIT)/pass.i \
	$(PIT)/primes.i \
	$(PIT)/random.i \
	$(PIT)/random2.i \
	$(PIT)/rot13.i \
	$(PIT)/rot13b.i \
	$(PIT)/sample.i \
	$(PIT)/sort.i \
	$(PIT)/tests/ais1.i \
	$(PIT)/tests/ais2.i \
	$(PIT)/tests/compucome.i \
	$(PIT)/tests/hello.i \
	$(PIT)/tests/ignorret.i \
	$(PIT)/tests/ignorearray.i \
	$(PIT)/tests/iogerunds.i \
	$(PIT)/tests/limits.i \
	$(PIT)/tests/permute.i \
	$(PIT)/tests/sink.i \
	$(PIT)/tests/onceagain.i \
	$(PIT)/tests/test1.i \
	$(PIT)/tests/test16bit.i \
	$(PIT)/tests/test2.i \
	$(PIT)/tests/testarray.i \
	$(PIT)/tests/testcf.i \
	$(PIT)/tests/testcreate .i \
	$(PIT)/tests/testlib2.i \
	$(PIT)/tests/testonce.i \
	$(PIT)/tests/testsplat.i \
	$(PIT)/tests/whileadd.i \
	$(PIT)/tpk.i \
	$(PIT)/unlambda.i \
	$(PIT)/yapp.i

BASENSOURCES = \
	$(PIT)/hail_mary.3i \
	$(PIT)/tests/count.3i \
	$(PIT)/tests/limits3.3i \
	$(PIT)/tests/testops3.3i \
	$(PIT)/tests/testops5.5i

SOURCES = $(BASE2SOURCES) $(BASENSOURCES)

TARGETS = $(BASE2SOURCES:.i=) \
	$(PIT)/hail_mary \
	$(PIT)/tests/count \
	$(PIT)/tests/limits3 \
	$(PIT)/tests/testops3 \
	$(PIT)/tests/testops5

.SUFFIXES:	.i .3i .4i .5i .6i .7i

%: %.i $(ICK)
	$(ICKENV) $(ICK) $(ICKOPTS) $<

%: %.3i $(ICK)
	$(ICKENV) $(ICK) $(ICKOPTS) $<

%: %.4i $(ICK)
	$(ICKENV) $(ICK) $(ICKOPTS) $<

%: %.5i $(ICK)
	$(ICKENV) $(ICK) $(ICKOPTS) $<

%: %.6i $(ICK)
	$(ICKENV) $(ICK) $(ICKOPTS) $<

%: %.7i $(ICK)
	$(ICKENV) $(ICK) $(ICKOPTS) $<

# For instructions on test conventions, see the header comment of regresscheck
test: $(TARGETS)
	@$(PIT)/beer | $(PIT)/regresscheck $(PIT)/beer
	@file $(PIT)/beer | grep -q 'shell script' || echo "Regression test of -F (using beer) FAILED."
	@cat $(PIT)/bubble.tst | $(PIT)/bubble | $(PIT)/regresscheck $(PIT)/bubble
	@cat $(PIT)/fft-delta.tst | $(PIT)/fft | $(PIT)/regresscheck $(PIT)/fft-delta
	@cat $(PIT)/fft-tophat.tst | $(PIT)/fft | $(PIT)/regresscheck $(PIT)/fft-tophat
	@cat $(PIT)/flonck.tst | $(PIT)/flonck | $(PIT)/regresscheck $(PIT)/flonck
	@echo 'Hello, sailor!' | $(PIT)/regresscheck $(PIT)/icat 
	@cat $(PIT)/interfunge.tst | $(PIT)/interfunge | $(PIT)/regresscheck $(PIT)/interfunge
	@echo 'A man, a plan, a canal, Panama.' | $(PIT)/rot13 | $(PIT)/regresscheck $(PIT)/rot13
	@echo 'A man, a plan, a canal, Panama.' | $(PIT)/rot13b | $(PIT)/regresscheck $(PIT)/rot13b
	@echo "FIVE" | $(PIT)/pi | $(PIT)/regresscheck $(PIT)/pi
	@cat $(PIT)/pow.tst | $(PIT)/pow 2>&1 | $(PIT)/regresscheck $(PIT)/pow
	@cat $(PIT)/pass.tst | $(PIT)/pass | $(PIT)/regresscheck $(PIT)/pass
	@cp $(PIT)/quine.i $(PIT)/quine.chk; $(PIT)/quine | $(PIT)/regresscheck $(PIT)/quine; rm -f $(PIT)/quine.chk 
	@cat $(PIT)/sort.tst | $(PIT)/sort | $(PIT)/regresscheck $(PIT)/sort
	@cat $(PIT)/tpk.tst | $(PIT)/tpk | $(PIT)/regresscheck $(PIT)/tpk
	@cat $(PIT)/unlambda.tst | $(PIT)/unlambda | $(PIT)/regresscheck $(PIT)/unlambda
	@cat $(PIT)/yapp.tst | $(PIT)/yapp >$(PIT)/yapptest.i && $(ICKENV) $(ICK) $(ICKOPTS) $(PIT)/yapptest.i && $(PIT)/yapptest | $(PIT)/regresscheck -c $(PIT)/yapp.tst $(PIT)/yapp; rm -f $(PIT)/yapptest.i $(PIT)/yapptest
	@cat $(PIT)/tests/ais1.tst | $(PIT)/tests/ais1 | $(PIT)/regresscheck $(PIT)/tests/ais1 
	@cat $(PIT)/tests/ais2.tst | $(PIT)/tests/ais2 | $(PIT)/regresscheck $(PIT)/tests/ais2 
	@$(PIT)/tests/count | $(PIT)/regresscheck $(PIT)/tests/count 
	@$(PIT)/tests/hello | $(PIT)/regresscheck $(PIT)/tests/hello 
	@$(PIT)/tests/ignorearray | $(PIT)/regresscheck $(PIT)/tests/ignorearray
	@$(PIT)/tests/ignorret | $(PIT)/regresscheck $(PIT)/tests/ignorret 
	@$(PIT)/tests/permute | $(PIT)/regresscheck $(PIT)/tests/permute 
	@$(PIT)/tests/sink 2>&1 | $(PIT)/regresscheck $(PIT)/tests/sink
	@$(PIT)/tests/test1 2>&1 | $(PIT)/regresscheck $(PIT)/tests/test1 
	@cat $(PIT)/tests/test2.tst | $(PIT)/tests/test2 | $(PIT)/regresscheck $(PIT)/tests/test2
	@$(PIT)/tests/testonce | $(PIT)/regresscheck $(PIT)/tests/testonce 
	@$(PIT)/tests/testsplat 2>&1 | $(PIT)/regresscheck $(PIT)/tests/testsplat 
	@cat $(PIT)/tests/whileadd.tst | $(PIT)/tests/whileadd | $(PIT)/regresscheck $(PIT)/tests/whileadd
	@echo "Tests complete."


# Some tests need options to compile extensions; some test extensions.
$(PIT)/beer: $(PIT)/beer.i $(ICK)
	$(ICKENV) $(ICK) -F $(ICKOPTS) $(PIT)/beer.i
$(PIT)/pass: $(PIT)/pass.i $(ICK)
	$(ICKENV) $(ICK) -m $(ICKOPTS) $(PIT)/pass.i
$(PIT)/tests/compucome: $(PIT)/tests/compucome.i $(ICK)
	$(ICKENV) $(ICK) -m $(ICKOPTS) $(PIT)/tests/compucome.i
$(PIT)/tests/permute: $(PIT)/tests/permute.i $(ICK)
	$(ICKENV) $(ICK) -m $(ICKOPTS) $(PIT)/tests/permute.i
$(PIT)/tests/testcreate: $(PIT)/tests/testcreate.i $(ICK)
	$(ICKENV) $(ICK) -a $(ICKOPTS) $(PIT)/tests/testcreate.i
$(PIT)/tests/whileadd: $(PIT)/tests/whileadd.i $(ICK)
	$(ICKENV) $(ICK) -m $(ICKOPTS) $(PIT)/tests/whileadd.i

lines:
	wc -l $(SOURCES)

clean:
	rm -f $(TARGETS) *.c *.o *~
