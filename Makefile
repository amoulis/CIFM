CC = mingw32-g++
EXE = prog.exe
SOURCES = main.cpp CMatrix.cpp CShell.cpp analyzeString.cpp


all: astring.o cmatrix.o main.o
	$(CC) astring.o cmatrix.o main.o -o $(EXE)

astring.o: analyzeString.cpp
	$(CC) -c analyzeString.cpp -o astring.o

astring.a: astring.o
	ar rvs astring.a astring.o

cmatrix.o: CMatrix.cpp
	$(CC) -c CMatrix.cpp -o cmatrix.o

main.o: main.cpp
	$(CC) -c main.cpp -o main.o

cshell.o: CShell.cpp astring.a
	$(CC) -c CShell.cpp -l astring.a -o cshell.o

run:  $(EXE)
	$(EXE)
	
clean:
	rm *.exe *.o *.a
