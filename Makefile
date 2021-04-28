CC = g++
CFLAGS = -ansi -pedantic -Wall -std=c++11
LDFLAGS =
SOURCE = src/
BINARY = bin/
SRC = $(wildcard $(SOURCE)*.cpp)
HDR = $(wildcard $(SOURCE)*.h)
OBJ = $(patsubst $(SOURCE)%.cpp,$(BINARY)%.o, $(SRC))
EXEC = analog

all: $(EXEC)

analog: $(OBJ) # édition des liens
	$(CC) -o $@ $^ $(LDFLAGS)

$(BINARY)%.o: $(SOURCE)%.cpp $(SOURCE)%.h # compilations classiques
	$(CC) -o $@ -c $< $(CFLAGS)

$(BINARY)main.o: $(SOURCE)main.cpp $(SOURCE)Traitement.h $(SOURCE)Lecture.h # compilation
	$(CC) -o $@ -c $< $(CFLAGS)

$(BINARY)Traitement.o: $(SOURCE)Traitement.cpp $(SOURCE)Traitement.h $(SOURCE)Lecture.h $(SOURCE)Log.h $(SOURCE)Extension.h # compilations
	$(CC) -o $@ -c $< $(CFLAGS)

$(BINARY)Lecture.o: $(SOURCE)Lecture.cpp $(SOURCE)Lecture.h $(SOURCE)Log.h # compilations
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm $(BINARY)*

mrproper:
	rm $(BINARY)* $(EXEC)

# https://gl.developpez.com/tutoriel/outil/makefile/
