#include <stdio.h>
#include <time.h>
#include "headers/knapsackProblem.h"

int n = 40;
        
int main(int argc, char const *argv[])
{
    int *peso, *valores, capacidade, answer;
    FILE *fp = fopen("geraGrafico/resultados.csv", "w");
    fprintf(fp, "n,tempo\n");

    for(int i=1;i<=n;i++) {
        
        peso = geraPesos(i);
        valores = geraValores(i);
        capacidade = geraCapacidade(peso, i);

        clock_t inicio = clock();

        answer = knapsack(capacidade, peso, valores, i);

        clock_t fim = clock();

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("Tempo para n = %d: %f segundos\n", i, tempo);
        //printf("Resposta: %d\n", answer);
        fprintf(fp, "%d,%f\n", i, tempo);

        free(peso);
        free(valores);
    }
        
    fclose(fp);
}

