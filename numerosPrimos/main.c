#include <stdio.h>
#include <time.h>
#include "headers/primeNumbers.h"

long long int n = 1000100000000;
bool answer;
        
int main(int argc, char const *argv[])
{
    FILE *fp = fopen("geraGrafico/resultados.csv", "w");
    fprintf(fp, "n,tempo\n");

    for(long long int i=1000000000000;i<=n;i+=100000) {
        clock_t inicio = clock();

        answer = isPrime(i);

        clock_t fim = clock();

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("Tempo para n = %lld: %f segundos\n", i, tempo);
        //printf("Resposta: %d\n", answer);
        fprintf(fp, "%lld,%f\n", i, tempo);
    }
        
    fclose(fp);
}

