/*
 * stack.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings, unsafe
 * copies/assignments Stage 2: template stack class, unsafe copies/assignments
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

#include <cstddef> // for size_t
#include <string>  // for stage 1

using namespace std;

class stack {
  public:
    string top() { return _data[_size]; } // non-inline, implemented in stack-stage1.cpp

    // inline definitions, doing nothing at the moment
    void push(const string & s);
    string pop();
    size_t size() { return _size; }
    bool is_empty() { if(_size==0){return true;} else{return false;} }

    stack();

  private:
    string* _data;
    size_t _size;
    size_t _capacity;
};

#endif
