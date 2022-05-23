#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "math.h"


double moyenne(double* wav_data, int first_index, int last_index) {

double moy = 0; 
for (int i = first_index; i < last_index+1 ; ++i){ 
	moy = moy + wav_data[i];}
moy = moy/(last_index - first_index +1);
return (moy);
}


double ecart_type(double* wave_data, int first_index, int last_index, double moy) {

double ec_type ; 
double somme = 0; 

for (int i = first_index; i< last_index+1 ; ++i){ 
	somme = somme + (wave_data[i] - moy)*(wave_data[i] - moy);
}
//printf("%f\n", somme);
ec_type = sqrt(somme/(last_index - first_index +1));
//printf("%f\n", ec_type);
return (ec_type);
}

/*int main() {
	double L[8] = {45,23,1,0,0,0,23,24};
	double moy = moyenne(L,0,8);
	printf("%f\n%f\n", moy, ecart_type(L,0,8,moy));
	return 0;
}*/ 
	
	

