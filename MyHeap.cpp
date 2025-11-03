/*
Andres Tellez Bermudez Matricula: A01640907
Fecha: 2/1/2025
Tarea 3.2
*/

#include "MyHeap.h"

// Complejidad:
// Mejor caso: O(1) - solo inicializa variables y reserva memoria.
// Peor caso: O(1) - no depende del tamaño, siempre hace lo mismo.
MyHeap::MyHeap(){
    size = 0; 
    len = 7; 
    this->values = new int [7];
}

// Complejidad:
// Mejor caso: O(n log n) - si el arreglo ya cumple la propiedad de heap y las subidas son mínimas.
// Peor caso: O(n log n) - se insertan n elementos y cada uno puede subir hasta log n niveles.
// Explicación: cada push cuesta log n y se hace n veces.
MyHeap::MyHeap(int* valores, int size ){
    this->size = 0; 
    this->len = size;
    this->values = new int[size];

    for(int i {0}; i<size; i++){
        push(valores[i]); 
    }
}

// Complejidad:
// Mejor caso: O(1) - el nuevo valor no requiere subir en el heap.
// Peor caso: O(log n) - el valor sube hasta la raíz.
// Nota: cuando se hace expansión del arreglo el costo es O(n) solo en ese momento.
void MyHeap::push(int n){
    if (size == len){
        int *borrar = values;
        int nuevo_tamano {(len*2)+1};
        len = nuevo_tamano; 
        values = new int [nuevo_tamano]; 
        for(int i {0}; i < nuevo_tamano; i++){
            values[i] = borrar[i];
        }
        delete[] borrar; 
    }
    this->values[size] = n; 
    revisarPush();
    size++; 
 
}

// Complejidad:
// Mejor caso: O(1) - no hay necesidad de intercambiar (ya está acomodado).
// Peor caso: O(log n) - el elemento sube hasta la raíz.
void MyHeap::revisarPush(){
    int index {size}; 
    if(index == 0 ){
        return;
    }
    int n {(index-1)/2};
    if((this->values[index] > this->values[n])){
        swap(index, n);
        revisarPushR(n); 
    }
}   

// Complejidad:
// Mejor caso: O(1) - no hay necesidad de intercambiar (ya está acomodado).
// Peor caso: O(log n) - el elemento sube hasta la raíz.
void MyHeap::revisarPushR(int N){
    if(N == 0){
        return; 
    }
    int n {(N-1)/2};
    if((this->values[N] > this->values[n])){
        swap(N, n);
        revisarPushR(n); 
    }
}

// swap
// Complejidad:
// Mejor caso: O(1) - solo intercambia dos valores.
// Peor caso: O(1) - siempre realiza tres asignaciones sin importar el tamaño del heap.
void MyHeap::swap(int n1, int n2){
    int temp = this->values[n1];
    this->values[n1] = this->values[n2];
    this->values[n2] = temp;
}

// isEmpty
// Complejidad:
// Mejor caso: O(1) - solo compara una variable.
// Peor caso: O(1) - operación constante.
bool MyHeap::isEmpty(){
    return size==0; 
}

// top
// Complejidad:
// Mejor caso: O(1) - acceso directo al primer elemento.
// Peor caso: O(1) - siempre retorna en tiempo constante.
int MyHeap::top(){
    return values[0];
}

// length
// Complejidad:
// Mejor caso: O(1) - solo regresa una variable.
// Peor caso: O(1) - tiempo constante.
int MyHeap::length(){
    return size; 
}

// imprimir
// Complejidad:
// Mejor caso: O(n) - siempre imprime los 'n' elementos del heap.
// Peor caso: O(n) - recorre todo el arreglo de elementos válidos.
void MyHeap::imprimir(){
    cout<<"arbol size: "<<this->size<<" len:"<<this->len<<endl;
    for(int i=0; i<this->size; i++){
        cout<<values[i]<<",";
    }
    cout<<endl;
}

// pop
// Complejidad:
// Mejor caso: O(1) - si el heap tiene un solo elemento o el nuevo root ya está en la posición correcta.
// Peor caso: O(log n) - reorganiza el heap bajando hasta el nivel más profundo.
void MyHeap::pop(){
    if(size == 0){
        return; 
    }
    values[0] = values[size-1];
    size--; 
    revisarPop(); 
}

// revisarPop
// Complejidad:
// Mejor caso: O(1) - detecta que no hay necesidad de bajar el nodo.
// Peor caso: O(log n) - puede llamar a la función recursiva para seguir bajando el nodo.
void MyHeap::revisarPop(){
    bool cont {values[1]<values[2]};
    if(size<2){
        return; 
    }
    if(size<3){
        if(values[0]<values[1]){
            swap(0,1);
            
        }
        return;
    }
    if(!cont){
        if(values[0]<values[1]){
            swap(0,1);
            revisarPopR(1);           
        }
        return;
    }else{
        if(values[0]<values[2]){
            swap(0,2);
            revisarPopR(2);
            
        }
        return;
    }
}

// revisarPopR
// Complejidad:
// Mejor caso: O(1) - no requiere intercambios, el heap ya está ordenado en esa posición.
// Peor caso: O(log n) - baja el nodo hasta una hoja del árbol.
void MyHeap::revisarPopR(int n){
    if(size<=n){
        return; 
    }
    int izquierda {(n*2)+1};
    int derecha {(n*2)+2};

    if(size<=izquierda){
        return;
    }
    if(size<= derecha){
        if(values[n]< values[izquierda]){
            swap(n, izquierda);
            revisarPopR(izquierda); 
             
        }
        return; 
    }

    bool cont {values[izquierda] < values[derecha]};
    if(!cont){
        if(values[n] < values[izquierda]){
            swap(n,izquierda);
            revisarPopR(izquierda);
        }
    }else{
        if(values[n]< values[derecha]){
                swap(n,derecha);
                revisarPopR(derecha);
            }
    }
}

// ~MyHeap
// Complejidad:
// Mejor caso: O(1) - libera el arreglo una sola vez.
// Peor caso: O(1) - liberar memoria dinámica siempre se ejecuta en tiempo constante.
MyHeap::~MyHeap(){
    delete[] values; 
}