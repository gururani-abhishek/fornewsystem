#include<stdio.h>
#include<math.h>

int main() {

	float a[10][10], x[10], s , k;
	int i, j, n;
	printf("enter the size of unknowns: ");
	scanf("%d", &n);

	printf("enter the augmented matrix: \n");

	//taking input
	for(i = 0; i<n; i++) {
		for(j = 0; j<=n; j++) {
		scanf("%f", &a[i][j]);
		}
	}

	

	//making upper triangular matrix
	for(i = 0; i<n-1; i++) {
		for(j = i+1; j<n; j++) {
		k = a[j][i]/a[i][i];

			for(int l =0; l<=n; l++) {
			a[j][l] -= a[i][l]*k;
			}
		}
	}

	//output matrix
	for(i = 0; i<n; i++) {
		for(j = 0; j<n; j++) {
			printf("%f ", a[i][j]);
		}
	printf("\n");
	}

	//substitution of values(i.e. backward substitution)

	for(i = n-1; i>=0; i--) {
		s = 0;
		for(j = i+1; j<n; j++) {
			s+=a[i][j]*x[j];
		}
		x[i] = (a[i][n]-s)/a[i][i];
	}

	for(i =0; i<n; i++) {
		printf("x[%d] = %f\t", i+1 ,x[i]);
	}

return 0;
}
