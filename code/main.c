#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <complex.h>
#include <fftw3.h>
#include <math.h>
#include "stft.h"
#include "audioread.h"
#include "encoding.h"
#include "utils.h"
#include "wave.h"
#define TRUE 1 
#define FALSE 0
#define windowSize 70000
#define sample_freq 22050
#define lenght 661504



int main(int argc, char* argv[]){

 
 char *filename;
 
 //creation of variables 
 //Demarrage de la fenetre suivante
 int hopSize=windowSize/2;
 //Taille de la magnitude 
 int magnitude_size= (lenght/(windowSize/2))*((windowSize/2)+1);
 //declaration of wav_data
 double* wav_data;
 //declaration of magnitude
 double* magnitude;

 //get filename
 filename = (char*) malloc(sizeof(char) * 1024);
 if (filename == NULL) {
   printf("Error in mallocn");
   exit(1);
 }

 // get file path
 char cwd[1024];
 if (getcwd(cwd, sizeof(cwd)) != NULL) {
   
    strcpy(filename, cwd);

    //get filename from command line
    if (argc < 2) {
      printf("No wave file specifiedn");
     return 0;
    }
    
    strcat(filename, "/");
    strcat(filename, argv[1]);
    printf("%sn", filename);
 }

 //creation of wav_data 
wav_data= malloc((lenght) * sizeof(double));
if (wav_data==NULL)
{
   printf("Error in creation of wav_data ");
   return 1;
}

//Fenetrage pour la magnitude
magnitude = malloc(magnitude_size*sizeof(double));
if (wav_data==NULL)
 {
    printf("Error in creation of magnitude ");
    return 1;
 }

//calcul de wave_data 
wav_data=audioread(filename);
//printf("Going to enter 1\n");
//Calcul de la stft
stft(&wav_data[0], magnitude_size, windowSize, hopSize,&magnitude[0],sample_freq, lenght);
for (int i = 0; i < 10; ++i) printf("%.2f\n", magnitude[i]);
//printf("Going to enter 2\n");


//creation du fichier csv
encoding(&wav_data);


return 0;

}


