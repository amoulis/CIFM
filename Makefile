CC = mingw32-g++
EXE = prog.exe
SOURCES = main.cpp CMatrix.cpp

all: $(SOURCES)
	$(CC) $(SOURCES) -o $(EXE)

run:  $(EXE)
	$(EXE)
	
clean:
	rm *.exe
