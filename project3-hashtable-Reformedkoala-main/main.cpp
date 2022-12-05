/*
 * main.cpp
 *
 * Includes the main() function for the hashtable project.
 *
 * This code is included in the default build target.  It
 * produces the program run-main.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <chrono>

#include "hashtable.h"
#include "hash_functions.h"

using namespace std;

double time_n_hashes(vector<string> &data){
    hashtable<string> ht;
    
    for(string& words : data){
        ht.insert(words);
    }
    
    auto start_time = chrono::system_clock::now();

    

    auto stop_time = chrono::system_clock::now();
    chrono::duration<double> elapsed = stop_time - start_time; 
    return elapsed.count();
}

int main() {
    // You can use this main() to run your own analysis or testing code.
    cout << "If you are seeing this, you have successfully run main!" << endl;

    // ==================================================================
    // The code below this point is relevant for the analysis part of the
    // hashtable project.  You do not need it for the programming part.
    // ==================================================================

    // The code below illustrates how to use the provided hash function 
    // "functional" objects, and lets you see the different hash values 
    // produced by each.
    // create ifstream object (if stands for input file)
    ifstream file("sequence.txt");
    //             ^ the file you want to read needs to be in the build directory

    // create vector to hold strings
    vector<string> data;

    // loop while not at end of file
    while(!file.eof()) {
        string s;
        // we use the insertion operator (<<) to push a string into a stream (like with cout)
        // we use the extraction operator (>>) to pull a string from a stream (like with cin or ifstream)
        file >> s;
        data.push_back(s);
    }

    hashtable<string, hash4> ht;

    for(string& words : data){
        ht.insert(words);
    }

    ht.print();
}