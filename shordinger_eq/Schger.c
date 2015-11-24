#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcPara(double x, double E)
{
	return (x*x - E);
}

void Numerov(double h, double ph0, double ph1, double x1, double E)
{
	FILE *fp = fopen("output1.txt", "w");
	double i1 = h, ph2;
	printf("%f %f\n", ph0, ph1);
	fprintf(fp, "%f %f\n%f %f\n", i1-h, ph0, i1, ph1);
	while((i1+h) <= x1)
	{
		ph2 = ((2.0 + 5.0*h*h*funcPara(i1,E)/6.0) * ph1  - (1.0 - h*h*funcPara(i1-h,E)/12.0) * ph0) / (1 - h*h*funcPara(i1+h,E)/12.0); 
		i1 += h;
		fprintf(fp, "%f %f\n", i1, ph2);
		ph0 = ph1;
		ph1 = ph2;
	}
}

int main(int args, char *argv[])
{
	double h, x1, E, ph0, ph1;
	int n;
	h = atof(argv[1]);
	x1 = atof(argv[2]);
	n = atoi(argv[3]);
	E = atof(argv[4]);
	if(n%2==1)
	{
		ph0 = 0.0;
		ph1 = h + pow(h, 3)*funcPara(0,E)/6.0;
		printf("%f\n", ph1);
		Numerov(h, ph0, ph1, x1, E);
	}
	else
	{
		ph0 = 1.0;
		ph1 = 1 + h*h*funcPara(0,E)/2.0 + pow(h, 4)*(2 + pow(funcPara(0,E), 2))/24.0;
		printf("%f\n", ph1);
		Numerov(h, ph0, ph1, x1, E);
	}
	return 0;
}
