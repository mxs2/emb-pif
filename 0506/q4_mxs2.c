#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int length;
} Segment;

bool canFormTriangle(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

bool checkCombinations(Segment* segments) {
    const int combinations[4][3] = {
        {0, 1, 2}, {0, 1, 3},
        {0, 2, 3}, {1, 2, 3}
    };

    for (int i = 0; i < 4; i++) {
        int a = segments[combinations[i][0]].length;
        int b = segments[combinations[i][1]].length;
        int c = segments[combinations[i][2]].length;
        if (canFormTriangle(a, b, c)) {
            return true;
        }
    }
    return false;
}

int main() {
    Segment* segments = (Segment*)malloc(4 * sizeof(Segment));

    scanf("%d %d %d %d",
          &segments[0].length,
          &segments[1].length,
          &segments[2].length,
          &segments[3].length);

    printf("%c\n", checkCombinations(segments) ? 'S' : 'N');

    free(segments);
    return 0;
}
