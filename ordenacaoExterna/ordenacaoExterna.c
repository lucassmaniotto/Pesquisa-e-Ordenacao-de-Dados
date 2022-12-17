// simple external sorting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateInputFile(char *filename, int n) {
    FILE *fp;
    int i, key;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Cannot open %s", filename);
        exit(1);
    }

    for (i = 0; i < n; i++) {
        key = rand() % 100;
        fprintf(fp, "%d ", key);
    }

    fclose(fp);
}

void printFile(char *filename) {
    FILE *fp;
    int key;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open %s", filename);
        exit(1);
    }

    while (fscanf(fp, "%d", &key) != EOF) {
        printf("%d ", key);
        
    }
    printf("\n");

    fclose(fp);
}

void externalSort(char *filename, int n) {
    FILE *fp;
    int i, j, key, *array;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open %s", filename);
        exit(1);
    }

    array = (int *) malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Cannot allocate memory");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &array[i]);
    }

    fclose(fp);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                key = array[i];
                array[i] = array[j];
                array[j] = key;
            }
        }
    }

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Cannot open %s", filename);
        exit(1);
    }

    for (i = 0; i < n; i++) {
        fprintf(fp, "%d ", array[i]);
    }

    fclose(fp);
    free(array);
}

void intercalate(char *filename1, char *filename2, char *filename3, int n) {
    FILE *fp1, *fp2, *fp3;
    int i, key1, key2;

    fp1 = fopen(filename1, "r");
    if (fp1 == NULL) {
        printf("Cannot open %s", filename1);
        exit(1);
    }

    fp2 = fopen(filename2, "r");
    if (fp2 == NULL) {
        printf("Cannot open %s", filename2);
        exit(1);
    }

    fp3 = fopen(filename3, "w");
    if (fp3 == NULL) {
        printf("Cannot open %s", filename3);
        exit(1);
    }

    fscanf(fp1, "%d", &key1);
    fscanf(fp2, "%d", &key2);

    for (i = 0; i < n+1; i++) {
        if (key1 < key2) {
            fprintf(fp3, "%d ", key1);
            fscanf(fp1, "%d", &key1);
            if (feof(fp1)) {
                fprintf(fp3, "%d ", key2);
                while (fscanf(fp2, "%d", &key2) != EOF) {
                    fprintf(fp3, "%d ", key2);
                }
                break;
            }
        } else {
            fprintf(fp3, "%d ", key2);
            fscanf(fp2, "%d", &key2);
        }
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

int main() {
    generateInputFile("input.txt", 5);
    printf("Primeiro arquivo: ");
    printFile("input.txt");    
    externalSort("input.txt", 5);
    printf("Primeiro arquivo ordenado: ");
    printFile("input.txt");
    printf("\n");

    printf("Segundo arquivo: ");
    generateInputFile("input2.txt", 3);
    printFile("input2.txt");
    externalSort("input2.txt", 3);
    printf("Segundo arquivo ordenado: ");
    printFile("input2.txt");
    printf("\n");

    intercalate("input.txt", "input2.txt", "output.txt", 8);
    printf("Arquivo intercalado: ");
    printFile("output.txt");

    return 0;
}

