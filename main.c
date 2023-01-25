#include <stdio.h>
#include <vstup.h>

#define MIN 0
#define MAX 10

int vstup(const char *text, int min, int max) {
    int z;
    int countOfChar;
    do {
        printf("Zadej %s v intervalu %d a %d:", text, min, max);
        scanf("%d", &z);
        countOfChar = 0;
        while (getchar() != '\n') {
            countOfChar++;
        }
        if (countOfChar != 0) {
            printf("Nezadal jsi cele cislo, zkus znovu.");
        } else if (z < min || z > max) {
            printf("Nezadal jsi cislo v intervalu %d a %d, zkus znovu.\n", min, max);
        }
    } while (countOfChar != 0 || z < min || z > max);
    return z;
}

unsigned int mocnina(int z, int e) {
    unsigned int vysledek = 1;
    for (; e > 0; e--) {
        vysledek *= z;
    }
    return vysledek;
}

int next() {
    printf("Pro pokracovani stisknete enter...");
    if (getchar() == '\n') {
        return 1;
    } else return 0;
}

int main() {
    int zaklad, exponent;
    do {
        zaklad = vstup("zaklad", MIN, MAX);
        exponent = vstup("exponent", MIN, MAX);
        printf("%d ^ %d = %u \n", zaklad, exponent, mocnina(zaklad, exponent));
    } while (next());
    return 0;
}