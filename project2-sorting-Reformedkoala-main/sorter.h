/*
 * sorter.h
 *
 * Declares a template function:
 *    
 *   sorter() : k-way merge sort.
 * 
 * 
 * You may add other functions if you wish, but this template function
 * is the only one that need to be exposed for the testing code.
 * 
 * Authors: C. Painter-Wakefield & Tolga Can
 */

#ifndef _SORTER_H
#define _SORTER_H

#include <iostream>
#include <string>
#include <cstddef>
#include <vector>
#include <cmath>

using namespace std;

template <class T>
void sorter(vector<T> &vec, int k) {  
  // base case
  if(vec.size() <= 1) {return;} // already sorted
  
  int size = vec.size();

  vector<vector<T>> vecStore;
  if(size/k >= 1){
    for (int i = 0; i < k; i++){
      vector<T> subVec(vec.end()-size/k, vec.end());
      vec.erase(vec.end()-size/k, vec.end());
      vecStore.emplace_back(subVec);
    }
  }

  if(vec.size() > 0){
    while(vec.size() > 0){
      vector<T> subVec(vec.end()-1,vec.end());
      vec.pop_back();
      vecStore.emplace_back(subVec);
    }
  }

  unsigned int i=0;

  for(i=0; i < vecStore.size(); i++){
    sorter(vecStore[i], k);
  }


  T maximum = vecStore[0].back();
  int maximumIndice = 0;
  vec.resize(size);
  size--;
  while(vecStore.size() != 0){
    maximum = vecStore[0].back();
    maximumIndice = 0;
    for(i = 0; i < vecStore.size(); i++){
      if(vecStore[i].back() > maximum){
        maximum = vecStore[i].back();
        maximumIndice = i;
      }
    } 

    vec[size]=maximum;
    size--;
    vecStore[maximumIndice].pop_back();

    if(vecStore[maximumIndice].size() == 0){
      vecStore.erase(vecStore.begin()+maximumIndice);
    }
  }
}
#endif