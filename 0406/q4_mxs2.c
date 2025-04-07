#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000
#define MAX_SUBSEQS 1000

char subseqs[MAX_SUBSEQS][MAX_LEN + 1];
int subseqCount = 0;

void insertSubseq(char *subseq) {
    int left = 0, right = subseqCount - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        int cmp = strcmp(subseqs[mid], subseq);
        if (cmp == 0) return;
        else if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    for (int i = subseqCount; i > left; i--) {
        strcpy(subseqs[i], subseqs[i - 1]);
    }
    strcpy(subseqs[left], subseq);
    subseqCount++;
}

void generateSubsequences(char *s, int index, char *current, int pos) {
    if (pos > 0) {
        current[pos] = '\0';
        insertSubseq(current);
    }
    if (s[index] == '\0') return;
    
    char lastChar = '\0';
    for (int i = index; s[i]; i++) {
        if (s[i] != lastChar) {
            lastChar = s[i];
            current[pos] = s[i];
            generateSubsequences(s, i + 1, current, pos + 1);
        }
    }
}

int main() {
    char s[MAX_LEN + 1];
    char current[MAX_LEN + 1];
    
    while (fgets(s, sizeof(s), stdin) != NULL) {
        s[strcspn(s, "\n")] = '\0';
        subseqCount = 0;
        generateSubsequences(s, 0, current, 0);
        for (int i = 0; i < subseqCount; i++) {
            printf("%s\n", subseqs[i]);
        }
        printf("\n");
    }
    return 0;
}
