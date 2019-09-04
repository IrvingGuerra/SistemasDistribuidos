#ifndef FRACCION_H_
#define FRACCION_H_

class Fraccion{
	private:
		int numerador;
		int denominador;
	public:
		Fraccion(int = 1, int = 2); // por defecto le ponemos 1/2
		void setNumerador(int);
		void setDenominador(int);
		int getNumerador();
		int getDenominador();
		double getFraccion();
		int * getMinimaExpresion();

};

#endif