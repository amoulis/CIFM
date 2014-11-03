CC = g++
EXE = prog.exe
SOURCES = main.cpp CMatrix.cpp CMatrix.hpp

all: $(SOURCES)
	$(CC) $(SOURCES) -o $(EXE)

run:  $(EXE)
	$(EXE)
	
clean:
	rm *.exe
