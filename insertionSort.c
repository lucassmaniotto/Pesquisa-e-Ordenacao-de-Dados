#include <stdio.h>

void insertionSort(int *vector, int length){
    int j;
    for(int i = 1; i <= length - 1; i++){
        int p = vector[i];
        for(j = i; j >= 1 && p < vector[j-1]; j--){
            vector[j] = vector[j-1];
        }
        vector[j] = p;
    }
}

int main(){
    int v[10] = {5, 8, 9, 4, 10, 2, 3, 7, 6, 1};
    
    // vetor inicial
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    insertionSort(v, 10);

    // vetor ordenado
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    
    return 0;
}