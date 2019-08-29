PROJECT = ejercicio_1
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

uninstall:
	rm -f $(PROJECT)

clean:
	rm -f *.o

