#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 2001

typedef struct {
    int idealCount;
    int length;
} PalindromeResult;

char str[MAX_SIZE];
bool ideal[MAX_SIZE];
int memo[MAX_SIZE][MAX_SIZE][2];

PalindromeResult getPalindrome(int start, int end) {
    if (start > end) return (PalindromeResult){0, 0};
    if (start == end) return (PalindromeResult){ideal[start], 1};
    if (memo[start][end][0] != -1) return (PalindromeResult){memo[start][end][0], memo[start][end][1]};

    PalindromeResult best = {0, 0};

    if (str[start] == str[end]) {
        PalindromeResult inner = getPalindrome(start + 1, end - 1);
        best = (PalindromeResult){inner.idealCount + ideal[start] + ideal[end], inner.length + 2};
    }

    PalindromeResult excludeLeft = getPalindrome(start + 1, end);
    PalindromeResult excludeRight = getPalindrome(start, end - 1);

    if (excludeLeft.idealCount > best.idealCount || (excludeLeft.idealCount == best.idealCount && excludeLeft.length > best.length))
        best = excludeLeft;

    if (excludeRight.idealCount > best.idealCount || (excludeRight.idealCount == best.idealCount && excludeRight.length > best.length))
        best = excludeRight;

    memo[start][end][0] = best.idealCount;
    memo[start][end][1] = best.length;
    return best;
}

int main() {
    int numIdealPositions, position;
    scanf("%s", str);
    scanf("%d", &numIdealPositions);

    memset(ideal, false, sizeof(ideal));
    memset(memo, -1, sizeof(memo));

    while (numIdealPositions--) {
        scanf("%d", &position);
        ideal[position - 1] = true;
    }

    printf("%d\n", getPalindrome(0, strlen(str) - 1).length);
    return 0;
}
