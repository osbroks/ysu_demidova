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
		chastota = 0;

	printf("Insert array A[], a number of elements = %d\n", N);

	while (scanf("%d", &A[i++]) == 1 && i < N);

	for (i = 0; i < N; i++) {
		chastota = 0;
		for (j = 0; j < N; j++) {
			if (A[i] == A[j]) {
				chastota++;
			}	
		}
		if (chastota > moda) {
			moda = chastota;
		}
		if (chastota == moda) {
			max = A[i];
		}
	}

	printf("\nKolichestvo elementov = %d, Moda = %d\n", moda, max);

	system("pause");

	return 0;
}
