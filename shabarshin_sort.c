#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable : 4996)
#define PAUSE system("pause");

int main(int argv, char *argc[]){
    int rows = 0,
        cols = 0,
        tmp = 0,
        k = 0,
        i = 0,
        j = 0;
    int **arr;

    printf("Insert Rows ");
    scanf("%d", &rows);
    printf("Insert cols ");
    scanf("%d", &cols);

    //выделение памяти под матрицу
    arr = (int **)malloc(sizeof(int *) * rows);
    arr[0] = (int *)malloc(rows * cols * sizeof(int));
    for (i = 0; i < rows; i++) {
        arr[i] = arr[0] + i * rows;
        for (j = 0; j < cols; j++) {
            arr[i][j] = (rand() % 100);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < (rows - 1); j++) {
            if (arr[j][0] > arr[j + 1][0])
                for (k = 0; k < cols; k++) {
                    tmp = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = tmp;
            }
        }
    }

    printf("Bubble sorted matrix\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    free(arr[0]);
    free(arr);

    PAUSE
	return;
}
