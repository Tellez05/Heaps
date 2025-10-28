#include "MyHeap.h"

MyHeap::MyHeap(){
    size = 0; 
    len = 7; 
    this->values = new int [7];
}

MyHeap::MyHeap(int* valores, int size ){

}

void MyHeap::push(int n){
    if (size == len){
        int *borrar = values;
        int nuevo_tamano {(len*2)+1};
        len = nuevo_tamano; 
        values = new int [nuevo_tamano]; 
        for(int i {0}; i < nuevo_tamano; i++){
            values[i] = borrar[i];
        }
        this->values[size] = n;  
        size++; 
    }
    this->values[size] = n; 
    size++; 
}

bool MyHeap::isEmpty(){
    return size==0; 
}

void MyHeap::pop(){
    for(int i {0}; i<size; i++){
        values[i] = values[i+1];
    }
    size--; 
    MyHeap(values, size); 
}

int MyHeap::top(){
    return values[0];
}

int MyHeap::length(){
    return size; 
}

void MyHeap::imprimir(){
    cout<<"arbol size: "<<this->size<<" len:"<<this->len<<endl;
    for(int i=0; i<this->size; i++){
        cout<<values[i]<<",";
    }
    cout<<endl;
}