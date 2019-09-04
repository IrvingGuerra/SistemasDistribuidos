#ifndef TEMPERATURA_H_
#define TEMPERATURA_H_

#include <math.h>
#include <string.h>

class Temperatura{
	private:
		double kelvin;
	public:
		Temperatura(double = 273);
		void setTempKelvin(double);
		void setTempFahrenheit(double);
		void setTempCelsius(double);
		double getTemp(char);
};

#endif