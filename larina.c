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

#define N 20

double Abs(double);
system();

int main(void) {

	double ArrayA[N][N],
		   ArrayB[N][N];

	double sum = 0;

	int i = 0,
		j = 0,
		n = 0,
		m = 0,
		len = 0,
		tempJ = -1,
		tempN = 0,
		tempM = 0;
	
	printf("Insert length of Array");
	scanf("%d", &len);

	for (i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			ArrayB[i][j] = 0;
			ArrayA[i][j] = 0;
		}
	}

	printf("\nInsert elements of Array\n");
	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			if (!scanf("%lf", &ArrayA[i][j])) {
				printf("Wrong Insert\n");
				system("PAUSE");
				return;
			}
		}
	}

	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			for (n = i,tempJ=-1; n >= 0; n--) {

                tempJ++;
				if ((j - tempJ) < 0){
				
					m = 0;
				}
				else {
					m = j - tempJ;
				}
				if((j+tempJ) >len-1){
					tempN = len-1;
				}
				else {
					tempN = j + tempJ;
				}
				for (; m <= tempN; m++) {
					ArrayB[i][j] += Abs(ArrayA[n][m]); 
				}
			}
		}
	}

	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			printf("%.3lf ", ArrayB[i][j]);
		}
		printf("\n");
	}

	system("PAUSE");
	return 0;
}

double Abs(double tmp) {
	if (tmp < 0)
		tmp = -tmp;

	return tmp;
}
