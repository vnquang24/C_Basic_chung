#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void printArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int next_permutation(int array[], int size) {
    for(int i = size - 2; i >= 0; i--) {
        if(array[i] < array[i + 1]) {
            for(int j = size - 1; j > i; j--) {
                if(array[j] > array[i]) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    qsort(array + i + 1, size - i - 1, sizeof(int), compare);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++) {
        array[i] = i + 1;
    }
    qsort(array, n, sizeof(int), compare);
    do {
        printArray(array, n);
    } while(next_permutation(array, n));
    return 0;
}
