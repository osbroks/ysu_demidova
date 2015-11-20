//Требуется запрограммировать рекурсивный алгоритм, который вычисляет
//Сумму элементов числового массива;
#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable: 4996)
#define PAUSE system("pause")

int summOfElements(int *, int, int);

int main(int argv, char *argc[]) {
	int i = 0,
		array_length = 0,
		summ = 0;
	int *array_of_int;

	printf("Insert number of elements ");
	if (!scanf("%d", &array_length)) {
		printf("\nWrong insert!");
		PAUSE;
		return;
	}
	array_of_int = (int *)malloc(sizeof(int) * array_length);
	if (array_of_int == NULL) {
		printf("\nHEAP CORRUPTED... Exiting\n\n\n");
		PAUSE;
		return;
	}

	for (i = 0; i < array_length; i++) {
		array_of_int[i] = rand() % 10;
	}
	for (i = 0; i < array_length; i++) {
		printf("%d ", array_of_int[i]);
	}

	summ = summOfElements(array_of_int, array_length, summ);
	printf("\nSumm = %d \n", summ);

	PAUSE;
	return;
}

int summOfElements(int *array_of_int, int array_length, int summ) {
	if (array_length < 1) {
		return summ;
	}
	else {
		summ += summOfElements(array_of_int, array_length - 1, summ);
		return summ;
	}
}
