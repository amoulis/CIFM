.PHONY: clean run

CXX = C:/MinGW/bin/mingw32-g++
EXE = prog.exe
SOURCES = main.cpp CMatrix.cpp CShell.cpp CStats.cpp
OBJS = main.o CMatrix.o CShell.o CStats.o
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
