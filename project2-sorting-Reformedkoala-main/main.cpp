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

#include "sorter.h"

using namespace std;

int main() {
    cout << "hi" << endl;
    vector<int> a = {10, 12, 2, 17, -4, 0, -9, 31, 6, 11};
    vector<int> b = {-9, -4, 0, 2, 6, 10, 11, 12, 17, 31};
    vector<int> kvals = {2, 3, 5, 10, 17};
    sorter(a, 2);
    
    cout << "If you are seeing this, you have successfully run main!" << endl;

    return 0;
}


