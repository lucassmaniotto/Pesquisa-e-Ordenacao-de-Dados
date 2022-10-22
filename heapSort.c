#include <stdio.h>

void createHeap(int *array, int i, int n){
    int max = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && array[left] > array[i]){
        max = left;
    }
    if(right < n && array[right] > array[max]){
        max = right;
    }

    if(max != i){
        int aux = array[i];
        array[i] = array[max];
        array[max] = aux;
        createHeap(array, max, n);
    }
}

void heapSort(int *array, int n){
    for(int i = n/2 - 1; i >= 0; i--){
        createHeap(array, i, n);
    }
    for(int i = n - 1; i >= 0; i--){
        int aux = array[0];
        array[0] = array[i];
        array[i] = aux;
        createHeap(array, 0, i);
    }
}


int main(){
    int v[10] = {5, 8, 9, 4, 10, 2, 3, 7, 6, 1};
 
    // vetor inicial
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    heapSort(v, 10);

    // vetor ordenado
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    
    return 0;
}