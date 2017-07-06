// fpconversie.h
//
#include <stdio.h>
#include <stdlib.h>

typedef union {
	float f;
	struct {
		unsigned int mantisa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	} parts;
	long b;
} double_cast;

void addition(double_cast* d1, double_cast* d2);
void substraction(double_cast* d1, double_cast* d2);
void multiplicatie(double_cast* d1, double_cast* d2);
void deling(double_cast* d1, double_cast* d2);

int binary_conversion(int num);
void print_bin(int n);
void print(double_cast* d1, double_cast* d2);
void print1(double_cast* d1);
void printlijnen();
void printbewerking(char c);

/* generate a random floating point number from min to max */
double randfrom(double min, double max);