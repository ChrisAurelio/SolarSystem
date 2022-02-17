CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++11
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJ = Main.o CelestialBody.o Universe.o
TARGET = NBody

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(SFMLFLAGS)
	
Main.o: Main.cpp CelestialBody.h Universe.h
	$(CC) $(CFLAGS) -c Main.cpp -o Main.o
	
CelestialBody.o: CelestialBody.cpp CelestialBody.h
	$(CC) $(CFLAGS) -c CelestialBody.cpp -o CelestialBody.o
	
Universe.o: Universe.cpp Universe.h
	$(CC) $(CFLAGS) -c Universe.cpp -o Universe.o

clean:
	rm $(TARGET) $(OBJ) $(TARGET)
