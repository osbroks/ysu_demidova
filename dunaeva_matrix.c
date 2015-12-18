/*
Строго нижним треугольным массивом А размерности n x n называется массив,
у которого Аиж = 0, если и <= ж. Разместите два нижних треугольных массива
А и Б размерности n x n в массиве размера n x (n + 1) так, 
чтобы можно было по заданным координатам элементов исходных массивов
определит их значения.
*/
#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable: 4996)

void writeArray(int, int **, int **, int **);
int findCoordinations(int **, int);

#define N 20
#define RAND100 100
#define RAND10 10

int main(int argv, char *argc[]) {
	int **array,
		**A,
		**B;

	int n = 0,
		i = 0,
		j = 0,
		value = 0;

	printf("insert N: ");
	if (!scanf("%d", &n)) {
		printf("ERROR N\n");
		system("pause");
		return;
	}
	if (n > N) {
		printf("ERROR N\n");
		system("pause");
		return;
	}

    A = (int **)malloc(sizeof(int *) * n);
    A[0] = (int *)malloc(n * n * sizeof(int));
    for (i = 0; i < n; i++) {
        A[i] = A[0] + i * n;
    }

    B = (int **)malloc(sizeof(int *) * n);
    B[0] = (int *)malloc(n * n * sizeof(int));
    for (i = 0; i < n; i++) {
        B[i] = B[0] + i * n;
    }

    array = (int **)malloc(sizeof(int *) * n);
    array[0] = (int *)malloc(n * n * sizeof(int));
    for (i = 0; i < n; i++) {
        array[i] = A[0] + i * n;
    }

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (j > i) {
				A[i][j] = 0;
                B[i][j] = 0;
			}
			else {
				A[i][j] = (rand() % RAND100) - (rand() % RAND100);
                B[i][j] = (n + rand() % RAND100) - (rand() % RAND100);
			}
		}
	}

	printf("Array A\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d\t", A[i][j]);
		}
		printf("\n");
	}

	printf("Array B\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d\t", B[i][j]);
		}
		printf("\n");
	}

    writeArray(n, array, A, B);

    printf("Array C\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    value = findCoordinations(array, n);
    printf("value = %d", value);

    free(A);
    free(B);
    free(array);

	system("PAUSE");
	return 0;
}

int findCoordinations(int **array, int n) {
    int i = 0,
        j = 0,
        choise = 0;

    printf("A(1) of B(2) : ");
    scanf("%d", &choise);
    if (choise == 1 || choise == 2) {
        printf("insert i and j : ");
        scanf("%d %d", &i, &j);
        if (i > n || j > n + 1) {
            printf("Error!!");
            return 0;
        }
        if (choise == 1) {
            return array[i-1][j-1];
        }
        else if (choise == 2) {
            return array[j-1][i];
        }
        else {
            printf("Error");
            return 0;
        }
    }
    else {
        printf("Error!");
        return 0;
    }
    
}

void writeArray(int len, int **array, int **A, int **B) {
	int i = 0,
		j = 0;

	for (i = 0; i < len; i++) {
		for (j = 0; j < len + 1; j++) {
            if (j <= i) {
                array[i][j] = A[i][j];
            }
            else {
                array[i][j] = B[j-1][i];
            }
		}
	}
}
