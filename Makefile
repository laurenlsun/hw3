CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes
#DEFS=-DDEBUG

all: llrec-test

OBJS = llrec-test.o llrec.o

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

llrec-test.o: llrec-test.cpp llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) -c -o $@ llrec-test.cpp
llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) -c -o $@ llrec.cpp

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 