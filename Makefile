.PHONY: clean run

CXX = mingw32-g++
EXE = prog.exe
SOURCES = main.cpp CMatrix.cpp CShell.cpp
OBJS = main.o CMatrix.o CShell.o
DEPS = CMatrix.hpp CShell.hpp
#LIB = .a 
#LIB_OBJS = .o

all: $(LIB) $(EXE)

$(EXE): $(LIB) $(OBJS)
	$(CXX) -o $@ $^

$(LIB): $(LIB_OBJS)
	$(AR) rsc $@ $^

%.o: %.cpp $(DEPS)
	$(CXX) -g -c -o $@ $<

run:  $(EXE)
	$(EXE)
	
clean:
	rm *.exe *.o *.a
