/*
 * main.cpp
 *
 * Includes the main() function for the sorting project. 
 *
 * This code is included in the build target "run-main"
*/

#include <iostream>
#include <cstddef>
#include <vector>
#include <chrono>

#include "sorter.h"

using namespace std;


int main() {
    srand(1234);
    vector<int> a;
    for (int j = 20000; j <= 100000; j+=20000){
        for (int i = 0; i < j; i++) {
            a.push_back(rand());
        }
        
        // get starting clock value  
        auto start_time = chrono::system_clock::now(); 
        
        sorter(a, 13);

        // get ending clock value 
        auto stop_time = chrono::system_clock::now(); 
        chrono::duration<double> elapsed = stop_time - start_time; 
        cout << elapsed.count() << endl; 
    }
    
    

    return 0;
}


