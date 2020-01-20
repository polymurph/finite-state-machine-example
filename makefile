#
# Makefile for garagedoor
# File: makefile
#
CC = g++
LINK = g++
# '-pedantic' sorgt dafuer, dass g++ streng arbeitet
CFLAGS = -c -pedantic -Wall
LFLAGS = -pedantic -Wall
OBJS = garagedoor.o garagedoor_ctrl.o garagedoor_test.o
EXE = door

$(EXE): $(OBJS)
	$(LINK) $(LFLAGS) -o $(EXE) $(OBJS)

garagedoor_test.o: garagedoor_test.cpp garagedoor_ctrl.h
	$(CC) $(CFLAGS) garagedoor_test.cpp

garagedoor_ctrl.o: garagedoor_ctrl.cpp garagedoor_ctrl.h
	$(CC) $(CFLAGS) garagedoor_ctrl.cpp

garagedoor.o: garagedoor.cpp garagedoor.h
	$(CC) $(CFLAGS) garagedoor.cpp

clean:
	# for UNIX
	rm -f $(EXE) $(OBJS)
	# for WIN
	#del $(EXE) $(OBJS)
