#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int *array, int start, int middle, int end){
    int *aux = (int *) malloc((end - start + 1) * sizeof(int));
    int i = start, j = middle + 1, k = 0;

    while(i <= middle && j <= end){
        if(array[i] < array[j]){
            aux[k] = array[i];
            i++;
        }
        else{
            aux[k] = array[j];
            j++;
        }
        k++;
    }

    while(i <= middle){
        aux[k] = array[i];
        i++;
        k++;
    }

    while(j <= end){
        aux[k] = array[j];
        j++;
        k++;
    }

    for(int k = start; k <= end; k++){
        array[k] = aux[k - start];
    }
    free(aux);
}

void mergeSort(int *array, int start, int end){
    if(start < end){
        int middle = floor((start + end) / 2);
        mergeSort(array, start, middle);
        mergeSort(array, middle + 1, end);
        merge(array, start, middle, end);
    }
}

int main(){
    int v[10] = {5, 8, 9, 4, 10, 2, 3, 7, 6, 1};
    
    // vetor inicial
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    mergeSort(v, 0, 9);

    // vetor ordenado
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    
    return 0;
}