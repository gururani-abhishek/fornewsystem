#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001

float value(float x) {
	return x*x - 2*x -5;
}

float bisect(float x1, float x2) {
	return x1 - ((x2- x1)/(value(x2) - value(x1)))*value(x1);
}

int main() {
	
	int maxIteration, i =1; 
	float x1, x2, x3, x;
	
	printf("enter the maximum no. of iterations: ");
	scanf("%d", &maxIteration);


	do{
		printf("enter the values of x1 and x2: ");
		scanf("%f%f", &x1, &x2);

		if(value(x1)*value(x2) > 0) {
			printf("\ninvalid roots\n");
			continue;
		}else{
			printf("roots lie between %f and %f\n", x1, x2);
			break;
		}

	}while(1);

	do{

		x = bisect(x1, x2);
		if(value(x1)*value(x) < 0) {
			x2 = x;
		} else {
			x1 = x;
		}

		printf("root: %f iterations: %d\n", x, i);

		x3 = bisect(x1, x2);

		if(fabs(x3-x) < EPSILON) {
			printf("root: %f total iteration: %d", x, i);
			return 0;
		}
		
		x = x3;
		i++;
	}while(i < maxIteration);

	printf("roots: %f total iteration: %d", x, i);

return 0;
}
