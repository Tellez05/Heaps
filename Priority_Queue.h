#pragma once
#include <iostream>
#include <vector>

using namespace std; 

class Priority_Queue{   
    private:
    int size {0};
    vector <int> lista; 
    public:
    int getSize(); 
    void push(); 
    void pop(); 
    int top(); 
    bool empty(); 


};  