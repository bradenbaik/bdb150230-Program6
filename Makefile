# Braden Baikauskas
# email: bdb150230@utdallas.edu
# CS 3377.501
# 23221
# make file for Program 6

CXX = g++
CXXFLAGS = 
CPPFLAGS = -Wall -g -I /scratch/perkins/include

LDFLAGS = -L /scratch/perkins/lib
LDLIBS = -lcdk -lcurses

EXE = Program6

OBJS = program6.o

all: $(EXE)

clean:
	rm -f $(OBJS) $(EXE) *.P *~ \#*

$(EXE): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)
