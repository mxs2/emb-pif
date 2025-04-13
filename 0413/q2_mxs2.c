#include <stdio.h>

typedef struct {
    int size;
    int totalSquares;
}
Grid;

void calculateSquares(Grid *grid) {
    grid -> totalSquares = 0;
    for (int i = 1; i <= grid -> size; i++) {
        grid -> totalSquares += i * i;
    }
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;

        Grid currentGrid;
        currentGrid.size = n;
        calculateSquares(&currentGrid);
        printf("%d\n", currentGrid.totalSquares);
    }
    return 0;
}
