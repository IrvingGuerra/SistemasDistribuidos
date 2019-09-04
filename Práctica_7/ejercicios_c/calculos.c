#include <math.h>
int main(void){
	float lo=0 ,s=0, c=0, t=0, r2=0;
	double i;
	int max=10000000;
	while (i < max){

		s+=sin(i);
		c+=cos(i);
		t+=tan(i);
		lo+=log(i);
		r2+=sqrt(i);
		i++;
	}

	return (0);
}
