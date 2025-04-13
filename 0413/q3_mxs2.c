#include <stdio.h>
#include <string.h>

typedef enum { ONE = 1, TWO = 2, THREE = 3 } Number;

typedef struct {
    char w[6];
    Number value;
} NumberWord;

int getNumberValue(const char *w) {
    int len = strlen(w);

    if (len == 3) {
        int oneMatches = 0;
        oneMatches += (w[0] == 'o');
        oneMatches += (w[1] == 'n');
        oneMatches += (w[2] == 'e');

        int twoMatches = 0;
        twoMatches += (w[0] == 't');
        twoMatches += (w[1] == 'w');
        twoMatches += (w[2] == 'o');

        if (oneMatches >= 2) return ONE;
        if (twoMatches >= 2) return TWO;
    } else if (len == 5) {
        int threeMatches = 0;
        threeMatches += (w[0] == 't');
        threeMatches += (w[1] == 'h');
        threeMatches += (w[2] == 'r');
        threeMatches += (w[3] == 'e');
        threeMatches += (w[4] == 'e');

        if (threeMatches >= 4) return THREE;
    }

    return 0;
}

int main() {
    int numWords;
    scanf("%d", &numWords);

    while (numWords--) {
        char currentW[6];
        scanf("%s", currentW);

        NumberWord numberWord;
        strcpy(numberWord.w, currentW);
        numberWord.value = getNumberValue(currentW);

        printf("%d\n", numberWord.value);
    }

    return 0;
}
