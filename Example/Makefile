CC      =	gcc
CFLAGS  =	-Wall -g -std=c11 -pedantic -fshort-enums -I../
TS	=	testsuite
TSH	=	$(TS).h
BUILD	=	$(TS) compoundtest floattest integraltest

all:		$(BUILD)
	make tclean

testsuite:		../mmzktestbase.o testsuite.o _compoundtest.o _floattest.o _integraltest.o
compoundtest:		compoundtest.o ../mmzktestbase.o
floattest:		floattest.o ../mmzktestbase.o
integraltest:		integraltest.o ../mmzktestbase.o

_compoundtest.o:	compoundtest.c ../mmzktestbase.h $(TSH)
	$(CC) $(CFLAGS) -c compoundtest.c -o _compoundtest.o
_floattest.o:		floattest.c ../mmzktestbase.h $(TSH)
	$(CC) $(CFLAGS) -c floattest.c -o _floattest.o
_integraltest.o:	integraltest.c ../mmzktestbase.h $(TSH)
	$(CC) $(CFLAGS) -c integraltest.c -o _integraltest.o

../mmzktestbase.o:	../mmzktestbase.h

compoundtest.o:		compoundtest.c ../mmzktestbase.h $(TSH)
	$(CC) $(CFLAGS) -c -DTEST_MAIN compoundtest.c
floattest.o:		floattest.c ../mmzktestbase.h $(TSH)
	$(CC) $(CFLAGS) -c -DTEST_MAIN floattest.c
integraltest.o:		integraltest.c ../mmzktestbase.h $(TSH)
	$(CC) $(CFLAGS) -c -DTEST_MAIN integraltest.c

clean:
	rm -f -rf $(wildcard *.o) $(wildcard *.a) $(BUILD) *.dSYM
	cd ../; rm -f -rf *.o *.a *.dSYM

tclean:
	rm -f $(wildcard _*.o)
