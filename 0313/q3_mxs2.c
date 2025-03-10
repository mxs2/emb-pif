#include <stdio.h>

int main() {
    double x, t = 0.0;

    scanf("%lf", &x);

    if (x <= 2000.00) {
        printf("Isento\n");

    } else {
        if (x > 2000.00 && x <= 3000.00) {
            t += (x - 2000.00) * 0.08;

        } else if (x > 3000.00 && x <= 4500.00) {
            t += 1000.00 * 0.08;
            t += (x - 3000.00) * 0.18;

        } else {
            t += 1000.00 * 0.08;
            t += 1500.00 * 0.18;
            t += (x - 4500.00) * 0.28;
        }

        printf("R$ %.2lf\n", t);
    }

    return 0;
}
