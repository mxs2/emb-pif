#include <stdio.h>
#include <string.h>

typedef enum { VERTEBRADO, INVERTEBRADO }
Category;

typedef enum { AVE, MAMIFERO, INSETO, ANELIDEO }
Subcategory;

typedef enum { CARNIVORO, ONIVORO, HERBIVORO, HEMATOFAGO }
Spec;

typedef struct {
    Category category;
    Subcategory subcategory;
    Spec spec;
}
AnimalTraits;

int main() {
    char w1[20], w2[20], w3[20];
    scanf("%s", w1);
    scanf("%s", w2);
    scanf("%s", w3);

    if (strcmp(w1, "vertebrado") == 0) {
        if (strcmp(w2, "ave") == 0) {
            if (strcmp(w3, "carnivoro") == 0) {
                printf("aguia\n");
            } else if (strcmp(w3, "onivoro") == 0) {
                printf("pomba\n");
            }
        } else if (strcmp(w2, "mamifero") == 0) {
            if (strcmp(w3, "onivoro") == 0) {
                printf("homem\n");
            } else if (strcmp(w3, "herbivoro") == 0) {
                printf("vaca\n");
            }
        }
    } else if (strcmp(w1, "invertebrado") == 0) {
        if (strcmp(w2, "inseto") == 0) {
            if (strcmp(w3, "hematofago") == 0) {
                printf("pulga\n");
            } else if (strcmp(w3, "herbivoro") == 0) {
                printf("lagarta\n");
            }
        } else if (strcmp(w2, "anelideo") == 0) {
            if (strcmp(w3, "hematofago") == 0) {
                printf("sanguessuga\n");
            } else if (strcmp(w3, "onivoro") == 0) {
                printf("minhoca\n");
            }
        }
    }

    return 0;
}
