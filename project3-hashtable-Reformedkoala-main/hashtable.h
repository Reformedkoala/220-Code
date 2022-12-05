/*
 * hashtable.h
 *
 * A basic hashtable implementation.
 * 
 * Author: <your name here>
 */

#ifndef _HASHTABLE_PROJECT_H
#define _HASHTABLE_PROJECT_H

#include <functional>   // for std::hash
#include <vector>
#include <iostream>

using namespace std;

template <class T, class H = std::hash<T>>
class hashtable {
public:
    // constructor
    hashtable(){
        m_size = 4;
        m_n = 0;
        m_table.resize(m_size);
    };

    // basic hashset operations
    void insert(const T& key){
        if(this->contains(key) == false && this->load_factor() < .75 ){
            m_table[hash(key)%m_size].push_back(key);
            m_n++;
        } else if(this->contains(key) == false && this->load_factor() >= .75 ){
            m_size *= 2;
            vector<vector<T>> new_table(m_size);
            for(unsigned int i = 0; i < m_table.size(); i++){
                for(unsigned int j = 0; j < m_table[i].size(); j++){
                    T tempKey = m_table[i][j];
                    new_table[hash(tempKey)%m_size].push_back(tempKey);
                }
            }
            new_table[hash(key)%m_size].push_back(key);
            m_table.swap(new_table);
            m_n++;
        }else{
            return;
        }
    };

    void remove(const T& key){
        if(this->contains(key) == true){
            for(unsigned int j = 0; j < m_table[hash(key)%m_size].size(); j++){
                if(m_table[hash(key)%m_size][j] == key){
                    m_table[hash(key)%m_size].erase(m_table[hash(key)%m_size].begin()+j);
                    m_n--;
                    return;
                }
            }
        }else{return;}
    };

    void print(){
        vector<int> bucketSizes;
        for (unsigned int i = 0; i < 1000000; i++){
            bucketSizes.push_back(0);
        }
        for(unsigned int i = 0; i < m_table.size(); i++){
            bucketSizes[m_table[i].size()]++;
        }
        for(unsigned int i = 0; i < m_table.size(); i++){
            if(bucketSizes[i] != 0){
                cout << i << ", " << bucketSizes[i] << endl;
            }
        }

    }

    bool contains(const T& key){
        for(unsigned int j = 0; j < m_table[hash(key)%m_size].size(); j++){
            if(m_table[hash(key)%m_size][j] == key){
                return true;
            }
        }
        return false;
        
    };

    size_t size(){
        return m_n;
    };

    // diagnostic functions
    double load_factor(){
        return double(m_n)/double(m_size);
    };

    // convenience method, invokes the "hash" template parameter
    // function object to get a hash code
    static size_t hash(const T &key) {
        H h;
        return h(key);
    }

private:
    vector<vector<T>> m_table;
    size_t m_size;
    size_t m_n;
 
};

#endif
