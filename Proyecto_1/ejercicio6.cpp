/********************************************************/
//Ejercicio 6

#include <iostream>
#include <math.h>

#define PI 3.14159265

using namespace std;

class Coordenada{

  private:

	  double x;   
	  double y;
    double z;

  public:
    
    Coordenada(double = 0, double = 0,double=0);
    
    double obtenerX();
    double obtenerY();
    double obtenerZ();
  
};
  
double Coordenada::obtenerX(){ 

  return x;
  
}
 
double Coordenada::obtenerY(){

  return y; 
}

double Coordenada::obtenerZ(){
  
  return z;

}

Coordenada::Coordenada(double xx, double yy, double zz) : x(xx), y(yy), z(zz) { }


class Rectangulo{

private:

  Coordenada superiorIzq;
  Coordenada inferiorDer;

public:

  Rectangulo(Coordenada SI, Coordenada ID);
  Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
  void imprimeEsq();
  Coordenada obtieneInfIzq();
  Coordenada obtieneSupDer();
  double obtenerArea();

};

Rectangulo::Rectangulo(Coordenada SI, Coordenada ID): superiorIzq(SI), inferiorDer(ID){ }

void Rectangulo::imprimeEsq(){

  cout << "Para la esquina superior izquierda.\n";
  cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << " z = "<<superiorIzq.obtenerZ()<<endl;
  cout << "Para la esquina inferior derecha.\n";
  cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << " z = "<<inferiorDer.obtenerZ()<<endl;   

}

Coordenada Rectangulo::obtieneInfIzq(){

  return superiorIzq;

}

Coordenada Rectangulo::obtieneSupDer(){

  return inferiorDer;

}

double Rectangulo::obtenerArea(){

  double ancho, alto;
  alto = superiorIzq.obtenerY() - inferiorDer.obtenerY();
  ancho = inferiorDer.obtenerX() - superiorIzq.obtenerX();

  return alto*ancho;

}

class Ortoedro{

private:

  Rectangulo r1;
  Rectangulo r2;
  Rectangulo r3;
  Rectangulo r4;
  Rectangulo r5;
  Rectangulo r6;

public:

  Ortoedro(Coordenada co,Coordenada lo);
  void obtieneVertices();
  void obtieneArea();
  void obtieneVolumen();

};

Ortoedro::Ortoedro(Coordenada co,Coordenada lo):
r1(co,Coordenada(lo.obtenerX(),lo.obtenerY(),co.obtenerZ())),
r2(Coordenada(lo.obtenerX(),co.obtenerY(),co.obtenerZ()),lo),
r3(Coordenada(co.obtenerX(),co.obtenerY(),lo.obtenerZ()),lo),
r4(co,Coordenada(co.obtenerX(),lo.obtenerY(),lo.obtenerZ())),
r5(co,Coordenada(lo.obtenerX(),co.obtenerY(),lo.obtenerZ())),
r6(Coordenada(co.obtenerX(),lo.obtenerY(),co.obtenerZ()),lo) {}

void Ortoedro::obtieneVertices(){

  cout << "x = " << r1.obtieneInfIzq().obtenerX() << " y = " << r1.obtieneInfIzq().obtenerY()  << " z = "<<r1.obtieneInfIzq().obtenerZ()<<endl;
  cout << "x = " << r1.obtieneSupDer().obtenerX() << " y = " << r1.obtieneSupDer().obtenerY()  << " z = "<<r1.obtieneSupDer().obtenerZ()<<endl;
  cout << "x = " << r2.obtieneInfIzq().obtenerX() << " y = " << r2.obtieneInfIzq().obtenerY()  << " z = "<<r2.obtieneInfIzq().obtenerZ()<<endl;
  cout << "x = " << r2.obtieneSupDer().obtenerX() << " y = " << r2.obtieneSupDer().obtenerY()  << " z = "<<r2.obtieneSupDer().obtenerZ()<<endl;
  cout << "x = " << r3.obtieneInfIzq().obtenerX() << " y = " << r3.obtieneInfIzq().obtenerY()  << " z = "<<r3.obtieneInfIzq().obtenerZ()<<endl;
  cout << "x = " << r6.obtieneInfIzq().obtenerX() << " y = " << r6.obtieneInfIzq().obtenerY()  << " z = "<<r6.obtieneInfIzq().obtenerZ()<<endl;
  cout << "x = " << r4.obtieneSupDer().obtenerX() << " y = " << r4.obtieneSupDer().obtenerY()  << " z = "<<r4.obtieneSupDer().obtenerZ()<<endl;
  cout << "x = " << r5.obtieneSupDer().obtenerX() << " y = " << r5.obtieneSupDer().obtenerY()  << " z = "<<r5.obtieneSupDer().obtenerZ()<<endl;
}

void Ortoedro::obtieneArea(){
  
  double area=0;
  double a=-r1.obtieneInfIzq().obtenerX()+r2.obtieneInfIzq().obtenerX();
  double b=-r1.obtieneInfIzq().obtenerZ()+r3.obtieneInfIzq().obtenerZ();
  double h=-r1.obtieneInfIzq().obtenerY()+r6.obtieneInfIzq().obtenerY();
  
  area=2*(a*b+a*h+b*h);
  
  cout<<"El area del ortoedro es: "<<area<<endl;

}

void Ortoedro::obtieneVolumen(){

  double volumen=0;
  double a=-r1.obtieneInfIzq().obtenerX()+r2.obtieneInfIzq().obtenerX();
  double b=-r1.obtieneInfIzq().obtenerZ()+r3.obtieneInfIzq().obtenerZ();
  double h=-r1.obtieneInfIzq().obtenerY()+r6.obtieneInfIzq().obtenerY();

  volumen=a*b*h;

  cout<<"El volumen del ortoedro es: "<<volumen<<endl;

}

  
int main(){
  
  Ortoedro ortoedro1(Coordenada(0,0,0),Coordenada(3,8,1)); 

  ortoedro1.obtieneVertices();
  ortoedro1.obtieneArea();
  ortoedro1.obtieneVolumen();
  
  return 0;

}