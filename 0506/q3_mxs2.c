#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char word[51];
    int length;
    int original_order;
} WordInfo;

void insertionSort(WordInfo* words, int count) {
    for (int i = 1; i < count; i++) {
        WordInfo key = words[i];
        int j = i - 1;

        while (j >= 0 && (words[j].length < key.length || 
               (words[j].length == key.length && words[j].original_order > key.original_order))) {
            words[j + 1] = words[j];
            j--;
        }
        words[j + 1] = key;
    }
}

int partition(WordInfo* words, int low, int high) {
    WordInfo pivot = words[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (words[j].length > pivot.length || 
            (words[j].length == pivot.length && words[j].original_order < pivot.original_order)) {
            i++;
            WordInfo temp = words[i];
            words[i] = words[j];
            words[j] = temp;
        }
    }

    WordInfo temp = words[i + 1];
    words[i + 1] = words[high];
    words[high] = temp;
    return i + 1;
}

void quickSort(WordInfo* words, int low, int high) {
    if (low < high) {
        int pi = partition(words, low, high);
        quickSort(words, low, pi - 1);
        quickSort(words, pi + 1, high);
    }
}

void printWords(WordInfo* words, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s", words[i].word);
        if (i != count - 1) printf(" ");
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        char line[3000];
        fgets(line, sizeof(line), stdin);

        int count = 0;
        char* token = strtok(line, " \n");
        WordInfo* words = NULL;

        while (token != NULL) {
            words = realloc(words, (count + 1) * sizeof(WordInfo));
            strcpy(words[count].word, token);
            words[count].length = strlen(token);
            words[count].original_order = count;
            count++;
            token = strtok(NULL, " \n");
        }

        if (count <= 50) {
            insertionSort(words, count);
        } else {
            quickSort(words, 0, count - 1);
        }

        printWords(words, count);
        free(words);
    }

    return 0;
}
