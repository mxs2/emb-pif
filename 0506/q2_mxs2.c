#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int number;
    int frequency;
} NumberFrequency;

void countFrequencies(int* numbers, int size, NumberFrequency** result, int* resultSize) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    *resultSize = 0;
    *result = (NumberFrequency*)malloc(size * sizeof(NumberFrequency));

    if (size == 0) return;

    (*result)[0].number = numbers[0];
    (*result)[0].frequency = 1;
    (*resultSize)++;

    for (int i = 1; i < size; i++) {
        if (numbers[i] == (*result)[*resultSize - 1].number) {
            (*result)[*resultSize - 1].frequency++;
        } else {
            (*result)[*resultSize].number = numbers[i];
            (*result)[*resultSize].frequency = 1;
            (*resultSize)++;
        }
    }
}

void printFrequencies(NumberFrequency* frequencies, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d aparece %d vez(es)\n", frequencies[i].number, frequencies[i].frequency);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int* numbers = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    NumberFrequency* frequencies;
    int frequenciesSize;

    countFrequencies(numbers, N, &frequencies, &frequenciesSize);
    printFrequencies(frequencies, frequenciesSize);

    free(numbers);
    free(frequencies);

    return 0;
}
