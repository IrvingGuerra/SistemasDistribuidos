/********************************************************/
//Ejercicio 7

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class objeto{

private:

	bool primo;
	int num;

public:

	objeto(int a);
	int get_numero();
	void set_primofalse();
	bool es_primo();
};

objeto::objeto(int a):primo(true),num(a){}

int objeto::get_numero(){

	return num;
}

void objeto::set_primofalse(){

	primo=false;
}

bool objeto::es_primo(){

	return primo;
}


void encontrar_primos(vector<objeto>array_numeros,int n);

vector<objeto> llenar_arreglo(int n);

int main(){

	int n=500;
	vector <objeto> array_numeros=llenar_arreglo(n);
	vector <objeto> ::iterator i;
	
	int aux=2;
	int aux2=pow(aux,2);
			
	while(aux2<n){
	
		for(i=array_numeros.begin();i!=array_numeros.end();i++){
			
			if((*i).get_numero()%aux==0&&(*i).get_numero()>aux){
		
				(*i).set_primofalse();
		
			}
		}
		
		for(i=array_numeros.begin();i!=array_numeros.end();i++){
		
			if((*i).es_primo()&&(*i).get_numero()>aux){

				aux=(*i).get_numero();
				break;

			}
		}

		aux2=pow(aux,2);
	}
	
	for(i=array_numeros.begin();i!=array_numeros.end();i++){
		
		if((*i).es_primo()){

			cout<<(*i).get_numero()<<" "<<endl;

		}
	
	}
	
	return 0;

}

vector<objeto> llenar_arreglo(int n){

	vector <objeto> array_numeros;
	
	for(int i=2;i<n+1;i++){
	
		objeto o=objeto(i);
		array_numeros.push_back(o);
	}
	
	return array_numeros;
}

void encontrar_primos(vector<objeto>array_numeros, int n){
	
	int aux=2;
	int aux2=pow(aux,2);
	
	while(aux2<n){
	
		for(auto e:array_numeros){

			if(e.es_primo()&&e.get_numero()!=aux){

				aux=e.get_numero();
			}
		}

		for(auto e:array_numeros){
			
			if(e.get_numero()%aux==0&&e.get_numero()>aux){

				e.set_primofalse();
			}
		}
	}
	
	for(auto e:array_numeros){

		if(e.es_primo())

			cout<<e.get_numero()<<" "<<endl;
	}
}