#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char language[21];
} Participant;

bool allSameLanguage(Participant group[], int k) {
    for (int i = 1; i < k; i++) {
        if (strcmp(group[0].language, group[i].language) != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int k;
        scanf("%d", &k);

        Participant group[100];
        for (int i = 0; i < k; i++) {
            scanf("%s", group[i].language);
        }

        if (allSameLanguage(group, k)) {
            printf("%s\n", group[0].language);
        } else {
            printf("ingles\n");
        }
    }

    return 0;
}
