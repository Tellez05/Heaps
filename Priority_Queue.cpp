#include "Priority_Queue.h"


void Priority_Queue::pop(){
    if(size != 0){
        for(int i {0}; i < getSize(); i++){
            lista[i] = lista[i+1]; 
        }
    }
}

bool Priority_Queue::empty(){
    return size==0;
}

int Priority_Queue::getSize(){
     return size; 
}

int Priority_Queue::top(){
    return lista[0];
}