#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 101

void processLine(char *line, int *wordLengths, int *wordCount, int *maxLength,
                 char *biggestWord) {
    int currentLength = 0;
    char currentWord[MAX_LEN] = "";
    int wordPos = 0;

    for (int i = 0; line[i]; i++) {
        if (isspace(line[i])) {
            if (currentLength > 0) {
                wordLengths[*wordCount] = currentLength;
                (*wordCount)++;
                currentWord[currentLength] = '\0';
                if (currentLength >= *maxLength) {
                    *maxLength = currentLength;
                    strcpy(biggestWord, currentWord);
                }
                currentLength = 0;
                wordPos = 0;
            }
        } else {
            currentWord[wordPos++] = line[i];
            currentLength++;
        }
    }

    if (currentLength > 0) {
        wordLengths[*wordCount] = currentLength;
        (*wordCount)++;
        currentWord[currentLength] = '\0';
        if (currentLength >= *maxLength) {
            *maxLength = currentLength;
            strcpy(biggestWord, currentWord);
        }
    }
}

void readLinesAndProcess() {
    char line[MAX_LEN];
    char biggestWord[MAX_LEN] = "";
    int maxLength = 0;

    while (1) {
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "0") == 0) break;

        int wordLengths[MAX_LEN] = {0};
        int wordCount = 0;

        processLine(line, wordLengths, &wordCount, &maxLength, biggestWord);

        for (int i = 0; i < wordCount; i++) {
            if (i > 0) printf("-");
            printf("%d", wordLengths[i]);
        }
        printf("\n");
    }

    if (maxLength > 0) {
        printf("\nThe biggest word: %s\n", biggestWord);
    }
}

int main() {
    readLinesAndProcess();
    return 0;
}
