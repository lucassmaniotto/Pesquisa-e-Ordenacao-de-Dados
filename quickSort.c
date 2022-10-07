#include <stdio.h>

int partition(int *array, int start, int end){
    int pivot = end;
    int k = start;

    for (int i = start; i < end; i++){
        if(array[i] <= array[pivot]){
            int aux = array[i];
            array[i] = array[k];
            array[k] = aux;
            k++;
        }
    }
    if(array[k] > array[pivot]){
        int aux = array[k];
        array[k] = array[pivot];
        array[pivot] = aux;
        pivot = k;
    }
    return pivot;
}

void quickSort(int *array, int start, int end){
    int pivot = end;
    if(start < end){
        pivot = partition(array, start, end);
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}

int main(){
    int v[10] = {5, 8, 9, 4, 10, 2, 3, 7, 6, 1};
    
    // vetor inicial
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    quickSort(v, 0, 9);

    // vetor ordenado
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    
    return 0;
}