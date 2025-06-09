#include <stdio.h>
#include <math.h>
#include <stdbool.h>


bool isPrime(long long int n);

bool isPrime(long long int n) {
    if (n <= 1) return false;
    bool primeValid;
    int limit = (int)sqrt(n);

    for (int i = 2; i <= limit; i++) {
        if (n % i == 0) {
            primeValid = false;
        }
        else {
            primeValid = true;
        }
    }
    return primeValid;
}
