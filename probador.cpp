#include "MyHeap.h"


int main(){
    int arr[] = {10, 5, 20, 3, 8, 15};
    int n = 6;

    MyHeap h(arr, n);

    cout << "Heap inicial: ";
    h.imprimir();

    cout << "Top (max): " << h.top() << endl;

    cout << "\nPop\n";
    h.pop();  // debe eliminar el 20
    h.imprimir();

    cout << "\nOtro pop\n";
    h.pop();  // debe eliminar el 15
    h.imprimir();

    cout << "\nInsertando 25\n";
    h.push(25);
    h.imprimir();

    cout << "\nTop actual: " << h.top() << endl;

    return 0;
}