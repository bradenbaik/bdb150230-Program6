# Braden Baikauskas
# email: bdb150230@utdallas.edu
# CS 3377.501
# 23221
# make file for Program 6
#Note I hade to use the -std=c++11 flag to get the <stdint.h> to work
CXX = g++
CXXFLAGS = 
CPPFLAGS = -Wall -g -std=c++11 -I /scratch/perkins/include

LDFLAGS = -L /scratch/perkins/lib
LDLIBS = -lcdk -lcurses

EXE = Program6

OBJS = program6.o

all: $(EXE)

clean:
	rm -f $(OBJS) $(EXE) *.P *~ \#*

$(EXE): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)
