#include <time.h>
#include <stdlib.h>


int* geraValores(int n);
int* geraPesos(int n);
int geraCapacidade(int pesos[], int n);
int knapsack(int capacidade, int pesos[], int valores[], int n);

int* geraValores (int n) {
    int* valores = malloc(n * sizeof(int));

    srand(time(NULL));

    for(int i=0;i<n;i++) {
        int numeroAleatorio = rand() % 30;
        valores[i] = numeroAleatorio;
        //printf("VALOR: %d\n", valores[i]);
    }

    return valores;
}

int* geraPesos (int n) {
    int* pesos = malloc(n * sizeof(int));

    srand(time(NULL));

    for(int i=0;i<n;i++) {
        int numeroAleatorio = rand() % 20;
        pesos[i] = numeroAleatorio;
        //printf("PESO: %d\n", pesos[i]);
    }

    return pesos;
}

int geraCapacidade(int pesos[], int n) {
    int aux = 0;
    int answer;
    float randomMultiplier;

    srand(time(NULL));
    randomMultiplier = rand() % 101;
    randomMultiplier = (randomMultiplier / 100) + n/2.0;

    //printf("Multiplier = %.2f\n", randomMultiplier);

    for(int i=0;i<n;i++) {
        aux += pesos[i];
    }
    answer = (int) aux / n * randomMultiplier;

    //printf("Aux = %d\n", aux);
    //printf("Capacidade = %d\n", answer);
    return answer;
}

int knapsack(int capacidade, int pesos[], int valores[], int n) {
    if (n == 0 || capacidade == 0)
        return 0;

    if (pesos[n - 1] > capacidade)
        return knapsack(capacidade, pesos, valores, n - 1);

    int without_current = knapsack(capacidade, pesos, valores, n - 1);
    int with_current = valores[n - 1] + knapsack(capacidade - pesos[n - 1], pesos, valores, n - 1);

    if (with_current > without_current)
        return with_current;
    else 
        return without_current;
}
