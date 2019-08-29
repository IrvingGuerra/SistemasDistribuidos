PROJECT = ejercicio_2
CFLAGS = -Wall
LDFLAGS = -lm
CC = g++
OBJECTS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: $(PROJECT)

%.o: %.cpp
	$(CC) -c $< $(CFLAGS)

$(PROJECT): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f *.o $(PROJECT)

run:
	./$(PROJECT)
