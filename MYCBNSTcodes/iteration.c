#include<stdio.h>
#include<math.h>
#define f(x) 2*x*x -5 -exp(x)
#define fo(x) 4*x - exp(x)

int main() {

	int itr = 0;
	float x1, x0, x2, aerror, c;

	
	int n; 

	scanf("%f", &x0);
	scanf("%d", &n);
	
	aerror = 1/(2*pow(10, n));

	do{
		float f = f(x0);
		float fo = fo(x0);
		x1 = x0 - f/fo;	
		c = fabs(x0-x1); 
		x0 = x1;
	}while(c>aerror);
	
	x1 = (float)((int)(x1*10000))/10000;
	printf("%.4f", x1);

return 0;
}


