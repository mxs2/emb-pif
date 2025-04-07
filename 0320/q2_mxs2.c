#include <stdio.h>

int main() {
    char T;
    double M[12][12], sum = 0.0;

    scanf("%c", &T);

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 12; j++) {
            sum = sum + M[j][i];
        }
    }

    if (T == 'S') {
        printf("%.1lf\n", sum);
    }

    else {
        printf("%.1lf\n", (sum / 66.0));
    }

    return 0;
}
