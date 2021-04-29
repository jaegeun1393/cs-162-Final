CC = g++
EXE_FILE = maze

all: $(EXE_FILE)

$(EXE_FILE):application.cpp maze.o mazelevel.o wall.o openspace.o ta.o instructor.o intrepidstudent.o mazelocation.hpp mazeperson.hpp
	$(CC) application.cpp maze.o mazelevel.o wall.o openspace.o ta.o instructor.o intrepidstudent.o mazelocation.hpp mazeperson.hpp -o $(EXE_FILE)

maze.o: maze.cpp maze.hpp
	$(CC) -c maze.cpp

mazelevel.o: mazelevel.cpp mazelevel.hpp
	$(CC) -c mazelevel.cpp

wall.o: wall.cpp wall.hpp
	$(CC) -c wall.cpp

openspace.o: openspace.cpp openspace.hpp
	$(CC) -c openspace.cpp

ta.o: ta.cpp ta.hpp
	$(CC) -c ta.cpp

instructor.o: instructor.cpp instructor.hpp
	$(CC) -c instructor.cpp

clean:
	rm -f *.o $(BIN)
