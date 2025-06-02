#include <stdio.h>
#include <time.h>
#include "headers/matrix.h"
        
int n = 1000;

int main(int argc, char const *argv[])
{   
    FILE *fp = fopen("geraGrafico/resultados.csv", "w");
    fprintf(fp, "n,tempo\n");

    for (int i = 1; i < n; i++) {
        int* matrix1 = matrixMaker(i);
        int* matrix2 = matrixMaker(i);

        clock_t inicio = clock();

        int* result = matrixSimpleMultiplication(matrix1, matrix2, i);

        clock_t fim = clock();

        free(matrix1);
        free(matrix2);
        free(result);

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("Tempo para n = %d: %f segundos\n", i, tempo);
        fprintf(fp, "%d,%f\n", i, tempo);
    }

    fclose(fp);
}

