main: main.cpp PoligonoIrregular.o
	g++ main.cpp PoligonoIrregular.o Coordenada.o -o ejercicio_3
PoligonoIrregular.o: PoligonoIrregular.cpp Coordenada.o PoligonoIrregular.h
	g++ PoligonoIrregular.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
