CC      =	gcc
CFLAGS  =	-Wall -g -std=c11 -pedantic -fshort-enums -I../
# TS	=	testsuite
# TSH	=	$(TS).h
BUILD	=	$(TS) integraltest

all:		$(BUILD)
	make tclean

testsuite:		mmzktestbase.o testsuite.o _integraltest.o
integraltest:		integraltest.o ../mmzktestbase.o

_integraltest.o:	integraltest.c ../mmzktestbase.h $(TSH)
	$(CC) $(CFLAGS) -c integraltest.c -o _integraltest.o

../mmzktestbase.o:	../mmzktestbase.h

integraltest.o:		integraltest.c ../mmzktestbase.h $(TSH)
	$(CC) $(CFLAGS) -c -DTEST_MAIN integraltest.c

clean:
	rm -f -rf $(wildcard *.o) $(wildcard *.a) $(BUILD) *.dSYM
	cd ../; rm -f -rf *.o *.a *.dSYM

tclean:
	rm -f $(wildcard _*.o)
