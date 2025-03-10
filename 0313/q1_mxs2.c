// TODO: Melhorar lógica para evitar repetição de código

#include <stdio.h>

int main() {
    double N = 0;
    int cem = 0, cinquenta = 0, vinte = 0, dez = 0, cinco = 0, duas = 0, um = 0;

    scanf("%lf", &N);

    while (N / 100 >= 1) {
        N -= 100;
        cem++;
    }

    while (N / 50 >= 1) {
        N -= 50;
        cinquenta++;
    }

    while (N / 20 >= 1) {
        N -= 20;
        vinte++;
    }

    while (N / 10 >= 1) {
        N -= 10;
        dez++;
    }

    while (N / 5 >= 1) {
        N -= 5;
        cinco++;
    }

    while (N / 2 >= 1) {
        N -= 2;
        duas++;
    }

    while (N / 1 >= 1) {
        N -= 1;
        um++;
    }


    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", cem);
    printf("%d nota(s) de R$ 50.00\n", cinquenta);
    printf("%d nota(s) de R$ 20.00\n", vinte);
    printf("%d nota(s) de R$ 10.00\n", dez);
    printf("%d nota(s) de R$ 5.00\n", cinco);
    printf("%d nota(s) de R$ 2.00\n", duas);

    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", um);

    N = N * 100;

    cem = 0, cinquenta = 0, vinte = 0, dez = 0, cinco = 0, duas = 0, um = 0;

    while (N / 50 >= 1) {
        N -= 50;
        cinquenta++;
    }

    while (N / 25 >= 1) {
        N -= 25;
        vinte++;
    }

    while (N / 10 >= 1) {
        N -= 10;
        dez++;
    }

    while (N / 5 >= 1) {
        N -= 5;
        cinco++;
    }
    
    while (N / 1 >= 1) {
        N -= 1;
        um++;
    }

    printf("%d moeda(s) de R$ 0.50\n", cinquenta);
    printf("%d moeda(s) de R$ 0.25\n", vinte);
    printf("%d moeda(s) de R$ 0.10\n", dez);
    printf("%d moeda(s) de R$ 0.05\n", cinco);
    printf("%d moeda(s) de R$ 0.01\n", um);

    return 0;
}
