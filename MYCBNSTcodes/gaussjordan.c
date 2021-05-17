#include<stdio.h>
#include<math.h>

int main() {

	int i, j, l, n;
	float a[10][10], x[10], s, k;
	
	printf("enter the number of unknowns: ");
	scanf("%d", &n);

	printf("enter the augmented matrix\n");

	
	
	//input
	for(i=0; i<n; i++) {
		for(j=0; j<=n; j++) {
			scanf("%f", &a[i][j]);
		}
	}

	//converting into diagonal matrix
	for(i=0; i<n; i++) {
		for(j=0; j<=n; j++) {
			if(j!=i) {
			k = a[j][i]/a[i][i];

			for(int l=0; l<=n; l++) {
				a[j][l]-=a[i][l]*k;
			}
			}
		}
	}

	//print diagonal matrix
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			printf("%f ",a[i][j]);
		}
	printf("\n");
	}
	
	//backward substitution
	for(i=n-1; i>=0; i--) {
		for(j = i+1; j<n; j++) {
			s+=a[i][j]*x[j];
		}
		x[i] = (a[i][n]-s)/a[i][i];
	}

	//output the answer
	for(i =0; i<n; i++) {
		printf("%f ", x[i]);
	}

return 0;
}
   
   
   
   
