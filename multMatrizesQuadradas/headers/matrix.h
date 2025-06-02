#include <stdlib.h>

int* matrixSimpleMultiplication(int* matrix1, int*matrix2, int n);
int* matrixMaker (int n);


int* matrixSimpleMultiplication(int* matrix1, int* matrix2, int n) {
    int* result = malloc(n * n * sizeof(int));
    if(result == NULL) {
        return NULL;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            result[i * n + j] = 0;
            for(int k=0;k<n;k++) {
                result[i * n + j] += matrix1[i * n + k] * matrix2[k * n + j];
            }
           // printf("%d ", result[i * n + j]); <--- Para ver o resultado
        }
       // printf("\n"); <--- Para ver o restultado
    }
    return result;
}

int* matrixMaker (int n) {
    int* matrix = malloc(n * n * sizeof(int));
    int nSquare = n * n;

    srand(time(NULL));

    for(int i=0;i<nSquare;i++) {
        int numeroAleatorio = rand() % 10;
        matrix[i] = numeroAleatorio;
        // printf("%d", matrix[i]); --> Para ver o resultado
    }

    return matrix;
}

// Para uma matriz1 com 
// O = O{n^3}