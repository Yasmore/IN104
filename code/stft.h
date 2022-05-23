// #include <stdio.h>
// #include <stdlib.h>
// #include <complex.h>
// #include <fftw3.h>
// #include <math.h>

#ifndef __STFT_H_
#define __STFT_H_

#define PI 3.14159265

double hamming(int windowLength, double *buffer);
double* stft(double *wav_data, int samples, int windowSize, int hop_size,\
             double *magnitude, int sample_freq, int length);
             
#endif            
