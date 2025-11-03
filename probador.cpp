#include "MyHeap.h"


int main() {
    cout << "==== Prueba completa de POP ====" << endl;

    // valores pensados para probar todos los casos
    int arr[] = {50, 30, 40, 10, 20, 35, 37, 5, 9};
    int n = 9;

    MyHeap h(arr, n);

    cout << "\nHeap inicial:\n";
    h.imprimir();

    // 1. POP normal con dos hijos y baja por izquierda
    cout << "\nPop 1 (baja por izquierda)\n";
    h.pop();
    h.imprimir();

    // 2. POP normal con dos hijos y baja por derecha
    cout << "\nPop 2 (baja por derecha)\n";
    h.pop();
    h.imprimir();

    // 3. POP con nodo que solo tiene hijo izquierdo
    cout << "\nPop 3 (solo hijo izquierdo)\n";
    h.pop();
    h.imprimir();

    // 4. POP con nodo que NO tiene hijos
    cout << "\nPop 4 (nodo sin hijos)\n";
    h.pop();
    h.imprimir();

    // 5. POP en secuencia hasta quedar uno
    cout << "\nPop hasta 1 elemento\n";
    while (h.length() > 1) {
        h.pop();
        h.imprimir();
    }

    // 6. POP con un solo elemento
    cout << "\nPop con un solo elemento\n";
    h.pop();
    h.imprimir();

    // 7. POP cuando ya está vacío
    cout << "\nPop en heap vacío (no debe fallar)\n";
    h.pop();
    h.imprimir();

    cout << "\n==== FIN DE PRUEBAS ====" << endl;
    return 0;
}