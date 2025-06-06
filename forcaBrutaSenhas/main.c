#include <stdio.h>
#include "headers/passwordBruteForce.h"

int n = 7;
char charset[] = "abcdefghijklmnopqrstuvwxyz";
        
int main(int argc, char const *argv[])
{
    int charsetLength = strlen(charset);

    FILE *fp = fopen("geraGrafico/resultados.csv", "w");
    fprintf(fp, "n,tempo\n");

    for(int i=1;i<=n;i++) {
        char *password = passwordMaker(i, charset, charsetLength);


        clock_t inicio = clock();

        bruteForce(charsetLength, charset, password);

        clock_t fim = clock();

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("Tempo para n = %d: %f segundos\n", i, tempo);
        fprintf(fp, "%d,%f\n", i, tempo);
        free(password);
    }
        
    
    fclose(fp);
}

