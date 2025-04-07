#include <stdio.h>
#include <string.h>

void checkResistance(char *D, char *S) {
    if (strstr(D, S)) {
        printf("Resistente\n");

    } else {
        printf("Nao resistente\n");
    }
}

int main() {
    char D[102], S[102];

    while (fgets(D, sizeof(D), stdin) && fgets(S, sizeof(S), stdin)) {
        D[strcspn(D, "\n")] = '\0';
        S[strcspn(S, "\n")] = '\0';

        checkResistance(D, S);
    }

    return 0;
}
