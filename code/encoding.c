#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <complex.h>
#include <fftw3.h>
#include <math.h>
#include "encoding.h"
#include "audioread.h"
#include "utils.h"
#include "stft.h"
#define windowSize 7000
#define lenght 661504
#define sample_freq 22050

//On créer un fichier csv qui contient tous les vecteur 1D de moyennes & ecart_types des 1000 fichiers audios

//On initialise un wav_data dans le main qui va correspondre au pointeur null t il va être modifié à chaque appel de la fonction audioread

void encoding(double** pwav_data) {

//printf("Enter encoding\n");
 //creation of variables 
 //Demarrage de la fenetre suivante
 int hopSize=windowSize/2;
 //Taille de la magnitude 
 int magnitude_size= (lenght/(windowSize/2))*((windowSize/2)+1);
 //declaration of magnitude
 double* magnitude;
 double* mgn;
 //nombre de ligne 
 int ligne_size=(lenght/(windowSize/2));

double moy;
double ec_type;


char** genres = malloc(10*sizeof(char*));
genres[0]=malloc(20*sizeof(char));
genres[0] = "blues";
genres[1]=malloc(20*sizeof(char));
genres[1] = "classical";
genres[2]=malloc(20*sizeof(char));
genres[2] = "country";
genres[3]=malloc(20*sizeof(char));
genres[3] = "disco";
genres[4]=malloc(20*sizeof(char));
genres[4] = "hiphop";
genres[5]=malloc(20*sizeof(char));
genres[5] = "jazz";
genres[6]=malloc(20*sizeof(char));
genres[6] = "metal";
genres[7]=malloc(20*sizeof(char));
genres[7] = "pop";
genres[8]=malloc(20*sizeof(char));
genres[8] = "reggae";
genres[9]=malloc(20*sizeof(char));
genres[9] = "rock";



FILE* fp = fopen("encoding.csv", "wb"); // ouvre le fichier csv.
//char* NAME;
char buffer[250];
double* wav_data;

//Fenetrage pour la magnitude
magnitude = malloc(magnitude_size*sizeof(double));
if (wav_data==NULL)
 {
    printf("Error in creation of magnitude ");
    return ;
 }

for (int i = 0; i<2; ++i) 
{
	for (int j = 0; j<100; ++j) 
	{
		
		//printf("%d\n",i);
		char filename[250]="/home/ensta/IN104_yasmina/NewFile/genres/";
		//finding path to file
		strcat(filename, genres[i]);
		strcat(filename,"/");
		strcat(filename, genres[i]);
		strcat(filename,".");
		strcat(filename, "000");
		sprintf(buffer,"%02d", j);
		strcat(filename,buffer);
		strcat(filename,".wav");
		//printf("%s\n", filename);

		//filling the csv 
		fprintf(fp, "%d;", i);
		wav_data=audioread(filename);
		//Calcul de la stft
		mgn=stft(&wav_data[0], magnitude_size, windowSize, hopSize,&magnitude[0],sample_freq, lenght);
		if (mgn!=NULL)
		{
			for (int k=1; k <= (windowSize/2)+1 ; ++k) 
			{
				moy = moyenne(mgn, k*ligne_size, (k+1)*ligne_size);
				ec_type = ecart_type(mgn, j*ligne_size, (j+1)*ligne_size, moy);
				fprintf(fp, " %.2f; %.2f;", moy, ec_type);
			};
		}
		fprintf(fp, "\n");
	}
	

		
}

fclose(fp);
}

// FILE* file = NULL;
// file = fopen("encoding.csv", "w");

// if (file == NULL) {
// 	fclose(file);
// 	return ; }


// for (int i = 0; i<10 ; ++i) {
// 	for (int j = 0; i<100 ; ++j) {
	
// 
		
// 		// 
		
// 		// fprintf(file, "%d;", i);
		
// 		// for (int j=1; j <= (windowSize/2)+1 ; ++j) {
// 		// 	moy = moyenne(*pwav_data, j*ligne_size, (j+1)*ligne_size);
// 		// 	printf("%f\n",moy);
// 		// 	ec_type = ecart_type(*pwav_data, j*ligne_size, (j+1)*ligne_size, moy); 
// 		// 	printf("%f\n",ec_type);
// 		// 	fprintf(file, " %.2f; %.2f;", moy, ec_type);
// 		// }
// 		// fprintf(file, "\n");
		
// 		}}
// fclose(file);
// return;

		


	

