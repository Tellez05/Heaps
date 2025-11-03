#pragma once
#include <iostream>
#include <vector>
using namespace std; 
class   MyHeap{
    //private:
    public: //Dejar todo público para poder revisar atributos
        int* values; //Arreglo donde se van a guardar los valores del HEAP
        int size;    //Representa cuantos valores tiene almacenado el Heap
        int len;    //Representa el tamaño o capacidad máxima actual del arreglo
        void revisarPushR(int n); // Hace la revision en recursivo
        void revisarPopR(int n); // Igual hace la recursion en la verificacion del pop
        void swap(int n1, int n2); // Hace el swap de 2 valores
    //public:
        MyHeap();//Inicializa el los atributos. El atributo values lo inicializa como un arreglo vacío tamaño de 7.
        MyHeap(int* valores,int size); //Conviert el arreglo en un heap. Lo deja del mismo tamaño que tiene el arreglo
        void push(int n); //Inserta un valor en el heap. Sólo cuando el nuevo valor no cabe en el arreglo
                          //crece el arreglo al tamaño 2*n+1. (Expansión din+amica del arreglo)
                          //Es decir si se tiene el arreglo ya con 7 valores y se quiere insertar otro valor(El 8vo)
                          //entonces el arreglo se crece a tamaño 15, se copian los primeros 7 valores del arreglo original
                          //y se inserta el 8vo valor.
        void pop();//Se elimina un valor del heap. No es necesario nunca decrementar el tamaño del arreglo.
        int top();//regresa quien es el siguiente elemento en salir pero sin borrarlo
        bool isEmpty();//regresa true si el heap está vacío caso contrario regresa false
        int length();//regresa cuántos elementos están almacenando el heap. OJO: NO EL TAMAÑO
        void imprimir();//Imprime los atributos del heap. Debe ser la implementación que se muestra abajo. No cambiar nada.
        void revisarPush(); //Primer ciclo para luego la recursion
        void revisarPop();//Revisa que el pop quede bien 

};      