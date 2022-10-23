CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test:
	$(CXX) $(CXXFLAGS) $(GTESTCFLAGS) llrec-test.cpp llrec.cpp llrec.h -o llrec-test

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 