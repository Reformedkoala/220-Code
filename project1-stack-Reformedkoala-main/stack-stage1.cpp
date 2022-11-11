/*
 * stack.cpp
 *
 * Method definitions for the stack implementation.
 *
 * Author: Your Name
 */

#include "stack-stage1.h"

void stack::push(const string & s){
    if (_size == _capacity-1){
        string* tempArray = new string[2*_capacity];
        for(unsigned int i = 0; i <= _size; i++){
            tempArray[i] = _data[i];
        }
        delete [] _data;
        _data = tempArray;
        _capacity = 2*_capacity;
    } 
    _size++;
    _data[_size] = s;
}

stack::stack(){
    _size = 0;
    _capacity = 4;
    _data = new string[_capacity];
}

string stack::pop(){ 
    string tempValue = _data[_size];
    _data[_size] = "";
    _size--;
    return tempValue;

}