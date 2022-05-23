#ifndef __AUDIOREAD_H_
#define __AUDIOREAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include <fftw3.h>
#include <math.h>

char* seconds_to_time(float raw_seconds);
double* audioread(char* filename);

#endif
