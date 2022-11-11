/*
 * stack.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings,
 *            unsafe copies/assignments
 *   Stage 2: template stack class, unsafe copies/assignments
 *   Stage 3: template stack class, safe copies/assignments
 *
 * Note: no underflow detection is performed.  Performing pop() or top()
 * on an empty stack results in undefined behavior (possibly crashing your
 * program)!
 *
 * Author: Your Name
 */

#ifndef _STACK_H
#define _STACK_H

// To start stage 2, you probably want to copy all of your code from
template <class T>
class stack {
  public:
    T top() { return _data[_size]; } // non-inline, implemented in stack-stage1.cpp

    // inline definitions, doing nothing at the moment
    void push(const T & s);
    T pop();
    size_t size() { return _size; }
    bool is_empty() { if(_size==0){return true;} else{return false;} }

    stack();
    ~stack(){delete [] _data;}
    stack(const stack & originalStack);
    stack<T>& operator=(const stack & originalStack);

  private:
    T* _data;
    size_t _size;
    size_t _capacity;
};


template <typename T>
void stack<T>::push(const T & s){
    if (_size == _capacity-1){
        T* tempArray = new T[2*_capacity];
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


template <typename T>
stack<T>::stack(){
    _size = 0;
    _capacity = 4;
    _data = new T[_capacity];
}


template <typename T>
stack<T>::stack(const stack & originalStack){
    this->_size = originalStack._size;
    this->_capacity = originalStack._capacity;
    this->_data = new T[this->_capacity];
    for(unsigned int i = 0; i <= this->_size; i++){
        this->_data[i] = originalStack._data[i];
    }
}


template <typename T>
stack<T>& stack<T>::operator=(const stack & originalStack){
    if(this->_data != originalStack._data){
    delete [] this->_data;
    this->_size = originalStack._size;
    this->_capacity = originalStack._capacity;
    this->_data = new T[this->_capacity];
    for(unsigned int i = 0; i <= this->_size; i++){
        this->_data[i] = originalStack._data[i];
    }
    return *this;
    } else {
        return *this;
    }
}


template <typename T>
T stack<T>::pop(){ 
    T tempValue = _data[_size];
    _size--;
    return tempValue;
}


#endif