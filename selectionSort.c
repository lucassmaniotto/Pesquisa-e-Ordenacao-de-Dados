#include <stdio.h>

void selectionSort(int *vector, int length){
    for(int i = 0; i < length - 1; i++){
        int aux;
        int minimumPosition = i;
        for(int j = i + 1; j < length; j++){
            if (vector[j] < vector[minimumPosition]){
                minimumPosition = j;
            }
        }
        if(minimumPosition != i) {
            aux = vector[i];
            vector[i] = vector[minimumPosition];
            vector[minimumPosition] = aux;
        }   
    }
}

int main(){
    int v[10] = {1, 8, 9, 4, 10, 2, 3, 7, 6, 1};
    
    // vetor inicial
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    selectionSort(v, 10);

    // vetor ordenado
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    
    return 0;
}