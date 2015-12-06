#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable : 4996)
#define PAUSE system("pause");

void fillGraph(int **, int);
void powGraph(int **, int **, int);

int main(int argv, char *argc[]) {
    int edge = 0,
        pow_graph = 0,
        vertex = 0;
    int i = 0,
        j = 0;
    int **graph,
        **reach_matrix;

    printf("insert number of vertex: ");
    if (!scanf("%d", &vertex)) {
        printf("ERROR... exiting");
        PAUSE
        return;
    }

    //выделение памяти под матрицу
    graph = (int **)malloc(sizeof(int *) * vertex);
    graph[0] = (int *)malloc(vertex * vertex * sizeof(int));
    for (i = 0; i < vertex; i++) {
        graph[i] = graph[0] + i * vertex;
    }
    for (i = 0; i < vertex ; i++) {
        for (j = 0; j < vertex; j++) {
            graph[i][j] = 0;
        }
    }

    reach_matrix = (int **)malloc(sizeof(int *) * vertex);
    reach_matrix[0] = (int *)malloc(vertex * vertex * sizeof(int));
    for (i = 0; i < vertex; i++) {
        reach_matrix[i] = reach_matrix[0] + i * vertex;
    }
    for (i = 0; i < vertex; i++) {
        for (j = 0; j < vertex; j++) {
            reach_matrix[i][j] = 0;
        }
    }

    fillGraph(graph, vertex);
    powGraph(graph, reach_matrix, vertex);

    for (i = 0; i < vertex; i++) {
        for (j = 0; j < vertex; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("Reacheable matrix\n");
    for (i = 0; i < vertex; i++) {
        for (j = 0; j < vertex; j++) {
            printf("%d ", reach_matrix[i][j]);
        }
        printf("\n");
    }

    free(reach_matrix[0]);
    free(reach_matrix);
    free(graph[0]);
    free(graph);

    PAUSE
	return;
}

void fillGraph(int **graph, int vertex) {
    int i = 0,
        j = 0;

    for (i = 0; i < vertex; i++) {
        for (j = 0; j < vertex; j++) {
            if (i >= j) {
                printf("Insert link %d to %d: ", i, j);
                scanf("%d",&graph[i][j]);
                graph[j][i] = graph[i][j];
            }  
        }
    }
}

void powGraph(int **graph, int **reach_matrix, int pow_of_graph) {
    int i = 0,
        j = 0,
        k = 0,
        tmp = 0;
    int **tmp_graph;

    tmp_graph = (int **)malloc(sizeof(int *) * pow_of_graph);
    tmp_graph[0] = (int *)malloc(sizeof(int) * pow_of_graph * pow_of_graph);
    for (i = 0; i < pow_of_graph; i++) {
        tmp_graph[i] = tmp_graph[0] + i * pow_of_graph;
    }

    for (i = 0; i < pow_of_graph; i++) {
        for (j = 0; j < pow_of_graph; j++) {
            tmp_graph[i][j] = graph[i][j];
    	}
    }

    for (k = 0; k < pow_of_graph; k++) {
        for (i = 0; i < pow_of_graph; i++) {
            for (j = 0; j < pow_of_graph; j++) {
                reach_matrix[k][i] += tmp_graph[k][j] * graph[j][i];
            }
        }
    }

    free(tmp_graph[0]);
    free(tmp_graph);
}
