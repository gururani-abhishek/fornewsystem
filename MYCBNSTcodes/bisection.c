#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001 



float valuediff(float x) {
	return 4*x-exp(x);
}

float value(float x) {
	return 2*x*x-5-exp(x);
}

float bisect(float x1, float x2) {
	return x-value(x)/valuediff(x);
}

	int main() {
		int i = 1, maxIteration;
		float x1, x2, x3, x;

	printf("enter max no. of iterations: ");
	scanf("%d",&maxIteration);

	do{
		
		printf("enter x1: and x2: ");
		scanf("%f%f", &x1, &x2);

		if(value(x1)*value(x2) > 0) {
			printf("\ninvalid entries\n");
			continue;
		}else {
			printf("root of the equation lie between %f and %f\n", x1, x2);
			break;
		}

	}while(1);

	do{
		x = bisect(x1, x2);
		if(value(x1)*value(x) < 0) {
			x2 = x;
		}else {
			x1 = x;
		}

		printf("root: %f iteration: %d\n", x, i);
		x3 = bisect(x1, x2);

		if(fabs(x3-x) < EPSILON) {
			printf("root: %f total iterations: %d", x, i);
			return 0;
		}

		x = x3;
		i++;
		
	}while(i<maxIteration);

	printf("root: %f total iterations: %d" , x, i);

return 0;
}
