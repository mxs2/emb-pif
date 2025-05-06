#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int speed;
} Slug;

int determineLevel(int speed) {
    if (speed < 10) return 1;
    if (speed < 20) return 2;
    return 3;
}

int findMaxLevel(Slug* slugs, int count) {
    int max_speed = 0;
    for (int i = 0; i < count; i++) {
        if (slugs[i].speed > max_speed) {
            max_speed = slugs[i].speed;
        }
    }
    return determineLevel(max_speed);
}

int main() {
    int L;
    while (scanf("%d", &L) != EOF) {
        Slug* slugs = (Slug*)malloc(L * sizeof(Slug));

        for (int i = 0; i < L; i++) {
            scanf("%d", &slugs[i].speed);
        }

        int level = findMaxLevel(slugs, L);
        printf("%d\n", level);

        free(slugs);
    }

    return 0;
}
