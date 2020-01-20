#
# Makefile for garagedoor
# File: makefile
#
CC = g++
LINK = g++
# '-pedantic' sorgt dafuer, dass g++ streng arbeitet
CFLAGS = -c -pedantic -Wall
LFLAGS = -pedantic -Wall
OBJS = ValveCtrl.o valveTest.o Valve.o
EXE = valveTest

$(EXE): $(OBJS)
	$(LINK) $(LFLAGS) -o $(EXE) $(OBJS)

valveTest.o: valveTest.cpp ValveCtrl.h
	$(CC) $(CFLAGS) valveTest.cpp

ValveCtrl.o: ValveCtrl.cpp ValveCtrl.h
	$(CC) $(CFLAGS) ValveCtrl.cpp

Valve.o: Valve.cpp Valve.h
	$(CC) $(CFLAGS) Valve.cpp

clean:
	# for UNIX
	#rm -f $(EXE) $(OBJS)
	# for WIN
	del $(EXE) $(OBJS)
