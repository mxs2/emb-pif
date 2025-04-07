#include <stdio.h>
#include <string.h>

void shiftAlphabet(char* alphabet, int shiftAmount) {
    for (int j = 0; j < strlen(alphabet); ++j) {
        alphabet[j] = ((alphabet[j] - 'A' - shiftAmount + 26) % 26) + 'A';
    }
}

int main() {
    char alphabet[51];
    int testCases, shiftAmount;

    scanf("%d", &testCases);

    for (int i = 0; i < testCases; ++i) {
        scanf("%s", alphabet);
        scanf("%d", &shiftAmount);

        shiftAlphabet(alphabet, shiftAmount);

        printf("%s\n", alphabet);
    }

    return 0;
}
