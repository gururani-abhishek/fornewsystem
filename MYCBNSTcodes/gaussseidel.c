#include<stdio.h>
#include<math.h>
#define f1(x, y, z)	(17-y+2*z)/20 
#define f2(x, y, z)	(-18-3*x+z)/20
#define f3(x, y, z)	(25-2*x+3*y)/20

int main() {

	int steps = 1;
	float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e;

	printf("enter tolerable error: ");
	scanf("%f", &e);

	printf("steps\t\tx\t\ty\t\tz\n");

	do{
		x1 = f1(x0, y0, z0);	
		y1 = f2(x1, y0, z0);
		z1 = f3(x1, y1, z0);

		e1 = fabs(x1-x0);
		e2 = fabs(y1-y0); 
		e3 = fabs(z1-z0);
		
		printf("%d\t\t%f\t%f\t%f\n", steps, x1, y1, z1);
		x0 = x1; 
		y0 = y1;
		z0 = z1;
		
		steps++;

	}while(e1>e && e2>e && e3>e);

	printf("final solution: \n x: %f\ny: %f\nz: %f", x1, y1, z1);

return 0;
}
