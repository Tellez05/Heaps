#include "MyHeap.h"

MyHeap::MyHeap(){
    size = 0; 
    len = 7; 
    this->values = new int [7];
}

MyHeap::MyHeap(int* valores, int size ){
    this->size = 0; 
    this->len = size;
    this->values = new int[size];

    for(int i {0}; i<size; i++){
        push(valores[i]); 
    }
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
        delete[] borrar; 
    }
    this->values[size] = n; 
    revisarPush();
    size++; 
 
}
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

void MyHeap::swap(int n1, int n2){
    int temp = this->values[n1];
    this->values[n1] = this->values[n2];
    this->values[n2] = temp;
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