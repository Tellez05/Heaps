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

void MyHeap::pop(){
    values[0] = values[size-1];
    size--; 
    revisarPop(); 
}

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


void MyHeap::revisarPopR(int n){
    if(size<=n){
        return; 
    }
    int izquierda {(n*2)+1};
    int derecha {(n*2)+1};

    if(size<=izquierda){
        return;
    }
    if(size<= derecha){
        if(values[n]< values[derecha]){
            swap(izquierda, n);
            revisarPopR(izquierda); 
             
        }
        return; 
    }

    bool cont {values[izquierda] < values[derecha]};
    if(!cont){
        if(values[n] < values[izquierda]){
            swap(n,izquierda);
            revisarPopR(izquierda);
        }else{
            if(values[n]< values[derecha]){
                swap(n,derecha);
                revisarPopR(derecha);
            }
        }
    }

}