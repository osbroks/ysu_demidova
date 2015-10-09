#include<stdio.h>

#pragma warning(disable: 4996)

#define N 3
system();

int main(void) {

	int A[N] = {0}, B[N] = {0};

	int i = 0,
		j = 0,
		max = 0,
		ner = 0,
		moda = 0,
		chastota = 1;

	printf("Insert array A[], a number of elements = %d\n", N);

	while (scanf("%d", &A[i++]) == 1 && i < N);
	for (i = 0; i < N; i++) printf("%d\n", A[i]);

	for (i = 0; i < N; i++) {
		if (moda != A[i]) {
			moda = A[i];
			for (j = 1; j <= N; j++)
				if (moda == A[j]) {
					chastota++;
					B[moda] = chastota;
				}
		}
		else { i++; }
	}

	for (i = 0; i < N; i++) {
		if (B[i] == B[i + 1])
			ner++;
	}

	max = B[0];
	for (i = 0; i < N; i++) {
		if (B[i] > max)
			max = B[i];
	}

	printf("Moda: %d", max);

	system("pause");

	return 0;
}
