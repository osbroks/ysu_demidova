/*
Задана матрица А вещественных чисел Размера НхН (Н <= 20, задается как параметр).
Построить по ней матрицу Б того же размера, элемент b(i,j) который равен
!сумме модулей! всех этих элементов матрицы А, которые расположены в некоторой ее области
(на соответствующем рисунке закрашена), определяемой по номеру строки i и номеру столбца j
так, как показано на рисунке
На печать вывести исходную и результирующую матрицы.
0 1 1 1 1 1 1 1 1 1
0 0 1 1 1 1 1 1 1 1
0 0 0 1 1 1 1 1 1 1
0 0 0 0 1 1 1 1 1 0
0 0 0 0 0 1 1 1 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
*/

#include<stdio.h>

#pragma warning(disable: 4996)

#define N 3

double Abs(double);

int main(void) {
	double ArrayA[N][N],
		   ArrayB[N][N];

	double tempI = 0,
		   tempJ = 0,
		   tempN = 0,
		   tempM = 0,
		   sum = 0;

	int i = 0,
		j = 0,
		n = 0,
		m = 0;

	printf("Insert elements of Array\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (!scanf("%lf", &ArrayA[i][j])) {
				printf("Wrong Insert\n");
				system("PAUSE");
				return;
			}
		}
	}

	for (i = 0; i < N; i++) {
		tempI = N;
		for (j = 0; j < N; j++) {
			tempJ = N;
			for (n = 0; n < N; n++) {
				for (m = 0; m < N; m++) {
					if (tempI == 0) {
						ArrayB[n][m] = ArrayA[0][j];
					}
					else if (tempJ == 0) {
						ArrayB[n][m] = ArrayA[n - 1][0] + ArrayA[n - 1][m + 1];
					}
					else if (tempJ == N) {
						ArrayB[n][m] = ArrayA[n - 1][m - 1] + ArrayA[n - 1][m];
					}
					ArrayB[n][m] = ArrayA[n - 1][m - 1] + ArrayA[n - 1][m + 1];
					tempI--;
					tempJ--;
				}
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < n; j++) {
			printf("%lf ", ArrayB[i][j]);
		}
	}

	system("PAUSE");
	return 0;
}

double Abs(double tmp) {
	if (tmp < 0)
		tmp = -tmp;

	return tmp;
}
