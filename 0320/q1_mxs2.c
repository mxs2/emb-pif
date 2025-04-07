#include <stdio.h>

int main() {
    int N[20], *ptr1 = N, *ptr2 = N + 19;

    for (int i = 0; i < 20; i++) {
        scanf("%d", &N[i]);
    }

    for (int i = 0; i < 10; i++, ptr1++, ptr2--) {
        *ptr1 ^= *ptr2;
        *ptr2 ^= *ptr1;
        *ptr1 ^= *ptr2;
    }

    for (int i = 0; i < 20; i++) {
        printf("N[%d] = %d\n", i, N[i]);
    }

    return 0;
}
