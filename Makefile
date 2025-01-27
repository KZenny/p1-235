CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -O2

PROG ?= main

# Notice how each name corresponds to a .cpp / .hpp pair (you can change these to test different files!)
OBJS = ChessPiece.o Pawn.o Rook.o main.o

mainprog: $(PROG)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(PROG) *.o *.out

rebuild: clean all test
