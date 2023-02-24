#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void attemptOpeningFile(FILE *fp, char *filename) {
    if (fp == NULL) {
        printf("Cannot open %s", filename);
        exit(1);
    }
}

void generateInputFile(char *filename, int n) {
    FILE *fp;
    int i, key;

    fp = fopen(filename, "w");
    attemptOpeningFile(fp, filename);

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
    attemptOpeningFile(fp, filename);

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
    attemptOpeningFile(fp, filename);

    array = (int *) malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Cannot allocate memory");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &array[i]);
    }

    fclose(fp);

    //bubble sort
    for (i = n - 1; i >= 1; i--) {
        for (j = 0; j < n - 1; j++) {
            if (array[j] > array[j+1]) {
                key = array[j];
                array[j] = array[j+1];
                array[j+1] = key;
            }
        }
    }

    fp = fopen(filename, "w");
    attemptOpeningFile(fp, filename);

    for (i = 0; i < n; i++) {
        fprintf(fp, "%d ", array[i]);
    }

    fclose(fp);
    free(array);
}

void intercalate(char *filename1, char *filename2, char *outputfilename, int n) {
    FILE *fp1, *fp2, *out;
    int i, key1, key2;

    fp1 = fopen(filename1, "r");
    attemptOpeningFile(fp1, filename1);

    fp2 = fopen(filename2, "r");
    attemptOpeningFile(fp2, filename2);

    out = fopen(outputfilename, "w");
    attemptOpeningFile(out, outputfilename);

    fscanf(fp1, "%d", &key1);
    fscanf(fp2, "%d", &key2);

    for (i = 0; i < n+1; i++) {
        if (key1 < key2) {
            fprintf(out, "%d ", key1);
            fscanf(fp1, "%d", &key1);
            if (feof(fp1)) {
                fprintf(out, "%d ", key2);
                while (fscanf(fp2, "%d", &key2) != EOF) {
                    fprintf(out, "%d ", key2);
                }
                break;
            }
        } else {
            fprintf(out, "%d ", key2);
            fscanf(fp2, "%d", &key2);
            if (feof(fp2)) {
                fprintf(out, "%d ", key1);
                while (fscanf(fp1, "%d", &key1) != EOF) {
                    fprintf(out, "%d ", key1);
                }
                break;
            }
        }
    }

    fclose(fp1);
    fclose(fp2);
    fclose(out);
}

int main() {
    generateInputFile("input.txt", 50);
    printf("Primeiro arquivo: ");
    printFile("input.txt");    
    externalSort("input.txt", 50);
    printf("Primeiro arquivo ordenado: ");
    printFile("input.txt");
    printf("\n");

    printf("Segundo arquivo: ");
    generateInputFile("input2.txt", 30);
    printFile("input2.txt");
    externalSort("input2.txt", 30);
    printf("Segundo arquivo ordenado: ");
    printFile("input2.txt");
    printf("\n");

    intercalate("input.txt", "input2.txt", "output.txt", 80);
    printf("Arquivo intercalado: ");
    printFile("output.txt");

    return 0;
}

