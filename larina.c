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

int main(void){
	double ArrayA[N][N],
		   ArrayB[N][N];
	int i = 0,
		j = 0,
		tempI = 0,
		tempJ = 0,
		sum = 0;

	printf("Insert elements of Array\n");
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (!scanf("%ld", &ArrayA[i][j])){
				printf("Wrong Insert");
				return;
			}
		}
	}

	for (i = 0; i < N; i++){
		tempI = i;
		for (j = 0; j < N; j++){
			for (){

			}
			ArrayB[i][j] = Abs(ArrayA[tempI - 1][tempJ - 1]) +
						   Abs(ArrayA[tempI + 1][tempJ - 1]);
			tempI--;
			if (tempI <= 0){
				ArrayB[i][j] = Abs(ArrayA[i][tempJ - 1]) +
							   Abs(ArrayA[tempI + 1][tempJ - 1]);
			}
			else if (tempJ <= 0)

			}
		}
	}


	return 0;
}

double Abs(double tmp){
	if (tmp < 0)
		tmp = -tmp;
}
