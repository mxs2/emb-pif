#include <stdio.h>

int main() {
    int a, b, c, x, y, z, temp;

    scanf("%d %d %d", &a, &b, &c);

    x = a;
    y = b;
    z = c;

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }

    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }

    printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", a, b, c, x, y, z);

    return 0;
}
