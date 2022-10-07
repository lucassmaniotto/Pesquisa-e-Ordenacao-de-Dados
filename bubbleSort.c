#include <stdio.h>

void bubbleSort(int *vector, int length){
    int aux;
    for(int i = 0; i < length - 1; i++){
        for(int j = 0; j < length - 1; j++){
            if (vector[j] > vector[j+1]){
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
}

int main(){
    int v[10] = {5, 8, 9, 4, 10, 2, 3, 7, 6, 1};
 
    // vetor inicial
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    bubbleSort(v, 10);

    // vetor ordenado
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    
    return 0;
}