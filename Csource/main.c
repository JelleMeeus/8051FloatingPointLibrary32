// Main.c : 4 basisbewerkingen met twee floating point (IEEE754) single precision getallen
//	samen gebruikt met assembly test programma ter verificatie
//

#include "fpconversie.h"

void addition(double_cast* d1, double_cast* d2)
{
	d1->f += d2->f;
}

void substraction(double_cast* d1, double_cast* d2)
{
	d1->f -= d2->f;
}

void multiplicatie(double_cast* d1, double_cast* d2)
{
	
	d1->f *= d2->f;
}

void deling(double_cast* d1, double_cast* d2)
{
	d1->f /= d2->f;
}

int binary_conversion(int num)
{
	if (num == 0)
	{
		return 0;
	}
	else
	{
		return (num % 2) +10 * binary_conversion(num / 2);
	}
}

void print_bin(int n)
{
	int c, k;
	for (c = 31; c >= 0; c--)
	{
		k = n >> c;

		if (k & 1)
			printf("1");
		else
			printf("0");
	}
}

char randomOp()
{
	const char arrayOp[4] = { '+', '-', 'x', '/' };
	int RandIndex = rand() % 4;
	return arrayOp[RandIndex];
}

void print(double_cast* d1, double_cast* d2)
{
	printf(";getal 1\n");
	printf(";dec = %f\n", d1->f);
	printf(";hex = %x\n", d1->b);
	printf(";\tsign = %x\n", d1->parts.sign);
	printf(";\texponent = %x\n", d1->parts.exponent);
	printf(";\tmantisa = %x\n", d1->parts.mantisa);

	printf("\n;getal 2\n");
	printf(";dec = %f\n", d2->f);
	printf(";hex = %x\n", d2->b);
	printf(";\tsign = %x\n", d2->parts.sign);
	printf(";\texponent = %x\n", d2->parts.exponent);
	printf(";\tmantisa = %x\n", d2->parts.mantisa);
}

void print_2(double_cast* d1, double_cast* d2)
{
	printf("mov r3,#0%xh\n", d1->b >> 24 & 0xff );
	printf("mov r2,#0%xh\n", d1->b >> 16 & 0xff);
	printf("mov r1,#0%xh\n", d1->b >> 8 & 0xff);
	printf("mov r0,#0%xh\n", d1->b >> 0 & 0xff);

	printf("mov r7,#0%xh\n", d2->b >> 24 & 0xff);
	printf("mov r6,#0%xh\n", d2->b >> 16 & 0xff);
	printf("mov r5,#0%xh\n", d2->b >> 8 & 0xff);
	printf("mov r4,#0%xh\n", d2->b >> 0 & 0xff);
}

void print1(double_cast* d1)
{
	printf(";getal 1\n");
	printf(";dec = %f\n", d1->f);
	printf(";hex = %x\n", d1->b);
	printf(";\tsign = %x\n", d1->parts.sign);
	printf(";\texponent = %x\n", d1->parts.exponent);
	printf(";\tmantisa = %x\n", d1->parts.mantisa);
}

void print1_2(double_cast* d1)
{
	printf("mov 13h,#0%xh\n", d1->b >> 24 & 0xff);
	printf("mov 12h,#0%xh\n", d1->b >> 16 & 0xff);
	printf("mov 11h,#0%xh\n", d1->b >> 8 & 0xff);
	printf("mov 10h,#0%xh\n", d1->b >> 0 & 0xff);
}

void printlijnen()
{
	printf("\n;==========================\n\n");
}

void printbewerking(char c)
{
	printf("\n\n;------ [Bewerking: %1c] ------\n\n", c);
}

/* generate a random floating point number from min to max */
double randfrom(double min, double max)
{
	double range = (max - min);
	double div = RAND_MAX / range;
	return min + (rand() / div);
}

int main(int argc, char *argv[])
{
	double_cast d1;
	double_cast d2;	
	if (argc==1)
	{
			d1.f = -2.5;
			d2.f = 7.5;
			
	}
	else{
		d1.f = atof(argv[1]);  
		d2.f = atof(argv[2]);
	}
	
	if (argc<3)
	{
			print(&d1, &d2);
			printbewerking('+');
			addition(&d1, &d2);
			print1(&d1);
			printlijnen();

			print(&d1, &d2);
			printbewerking('x');
			multiplicatie(&d1,&d2);
			print1(&d1);
			printlijnen();

			print(&d1, &d2);
			printbewerking('-');
			substraction(&d1, &d2);
			print1(&d1);
			printlijnen();

			print(&d1, &d2);
			printbewerking('/');
			deling(&d1, &d2);
			print1(&d1);
			printlijnen();			
	}
	if (argc==4)
	{
		switch (argv[3][0]) {					
					case '+':
						print(&d1, &d2);
						printbewerking('+');
						addition(&d1, &d2);
						print1(&d1);
						printlijnen();
						break;
					case '-':
						print(&d1, &d2);
						printbewerking('-');
						substraction(&d1, &d2);
						print1(&d1);
						printlijnen();
						break;
					case '/':
						print(&d1, &d2);
						printbewerking('/');
						deling(&d1, &d2);
						print1(&d1);
						printlijnen();
						break;
					case 'x':
						print(&d1, &d2);
						printbewerking('x');
						multiplicatie(&d1,&d2);
						print1(&d1);
						printlijnen();
						break;	
			}
	}	
	if (argc == 5 || argc == 6)
	{
		int i_max;
		if (argc == 5)
		{
			i_max = 100;
		}
		else
		{
			i_max = atoi(argv[5]);
		}

		printf("; %d waarden tussen %f en %f\n;bewerking '%c' \n", i_max, atof(argv[1]), atof(argv[2]), argv[3][0]);
		for (int i = 0; i < i_max; i++)
		{
			//-1.701412E38..3.4028235E38
			d1.f = randfrom(atof(argv[1]) , atof(argv[2]));
			d2.f = randfrom(atof(argv[1]), atof(argv[2]));
			printf(";\n");

			if (argv[4][0] == 'a')
			{
				argv[3][0] = randomOp();
			}

			switch (argv[3][0]) {
			case '+':
				print_2(&d1, &d2);
				print(&d1, &d2);
				//printbewerking('+');
				addition(&d1, &d2);
				print1(&d1);
				print1_2(&d1);
				printf("lcall fadd32\n");
				//printlijnen();
				break;
			case '-':
				print_2(&d1, &d2);
				print(&d1, &d2);
				//printbewerking('-');
				substraction(&d1, &d2);
				print1(&d1);
				print1_2(&d1);
				printf("lcall fsub32\n");
				//printlijnen();
				break;
			case '/':
				print_2(&d1, &d2);
				print(&d1, &d2);
				//printbewerking('/');
				deling(&d1, &d2);
				print1(&d1);
				print1_2(&d1);
				printf("lcall fdiv32\n");
				//printlijnen();
				break;
			case 'x':
				print_2(&d1, &d2);
				print(&d1, &d2);
				//printbewerking('x');
				multiplicatie(&d1, &d2);
				print1(&d1);
				print1_2(&d1);
				printf("lcall fmul32\n");
				//printlijnen();
				break;
			}
		}
		
	}
}

