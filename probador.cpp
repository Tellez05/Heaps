#include "MyHeap.h"

int main() {
    MyHeap h;

    cout << "Insertando valores y mostrando el heap:\n";

    h.push(50);
    h.push(30);
    h.push(60);
    h.push(10);
    h.push(80);
    h.push(20);
    h.push(90);
    h.push(55);
    h.push(5);
    h.push(100);

    h.imprimir(); 

    return 0;
}
