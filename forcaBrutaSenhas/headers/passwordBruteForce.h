#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

char* passwordMaker(int n, char* charset, int charsetLength);
bool tryPassword(char* password, char* attempt);
void bruteForce(int charsetLength, char* charset, char* password);


char* passwordMaker(int n, char* charset, int charsetLength) {
    char* password = malloc(n+1 * sizeof(char));
    srand(time(NULL));

    for(int i=0;i<=n;i++) {
        char valorAleatorio = charset[rand() % charsetLength];
        if (i == n) {
            password[i] = '\0';
        }
        else {
            password[i] = valorAleatorio; 
        } 
    }
    return password;
}

bool tryPassword(char* password, char* attempt) {
    return strcmp(password, attempt) == 0;
}

void bruteForce(int charsetLength, char* charset, char* password) {
    int attemptLenght = 1;
    bool found = false;

    while(!found) {
        char* attempt = malloc(attemptLenght+1 * sizeof(char));
        unsigned long long totalIters = 1;

        for (int i=0;i<attemptLenght;i++) totalIters *= charsetLength;

        for (unsigned long long i=0;i<totalIters;i++) {
            unsigned long long iAux = i;
            for (int j = 0; j < attemptLenght; j++) {
                attempt[j] = charset[iAux % charsetLength];
                iAux /= charsetLength;
            }
            attempt[attemptLenght] = '\0';
            
           // printf("Tentativa: %s\n", attempt);      <-- Mostra o valor de senha sendo testado pelo attempt
            if (tryPassword(password, attempt)) {
             //   printf("Senha encontrada.\n");    <-- Avisa que a senha foi encontrada
                found = true;
            }
        }
        attemptLenght++;
    }
}
// O(raíz de N)