#include "MyHeap.h"

int main() {
    int arr[] = {40, 10, 90, 30, 50, 5, 70, 20, 60, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    MyHeap heap(arr, n);

    heap.imprimir(); // tu función ya lo imprime

    return 0;
}