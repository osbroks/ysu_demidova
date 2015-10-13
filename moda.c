#include<stdio.h>

#pragma warning(disable: 4996)

#define N 4
system();

int main(void) {

	int A[N];

	int i = 0,
		j = 0,
		max = 0,
		moda = 0,
		flag = 0,
		vhozdenie = 0,
		chastota = 0;

	printf("Insert array A[], a number of elements = %d\n", N);

	while(1){	
		if(!scanf("%d", &A[i])){
			printf("Wrong enter!\n");
			printf("Insert array A[], a number of elements = %d\n", N);
			fflush(stdin);
			i = 0;
		}
		i++;
		if(i == N){
			break;
		}
	}
		
	for (i = 0; i < N; i++) {
		vhozdenie = 0;
		for (j = 0; j < N; j++) {
			if (A[i] == A[j]) {
				vhozdenie++;
				flag = 1;
			}
		}
	
		if (moda == chastota) {
			flag = -1;
		}
	}

	printf("\nKolichestvo elementov = %d, Moda = %d\n", chastota, max);

	system("PAUSE");

	return 0;
}
