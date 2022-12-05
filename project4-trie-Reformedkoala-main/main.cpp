/*
 * main.cpp
 *
 * Includes the main() function for the trie project.
 *
 * This code creates the executable run-main.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <chrono>
#include <algorithm>

#include "trie.h"

using namespace std;

int main() {
    // You can use this main() to run your own analysis or testing code.
    cout << "If you are seeing this, you have successfully run main!" << endl;

// You can uncomment the code below to read in a large word list and insert
// them all into your trie, to set up your own tests.

    ifstream fin("dictionary.txt");
    if (!fin) {
        cout << "Error opening dictionary.txt, exiting." << endl;
        return -1;
    }

    vector<string> words;
    while (fin) {
        string s;
        fin >> s;
        if (!s.empty()) words.push_back(s);
    }
    fin.close();

    trie t;
    auto start_time = chrono::system_clock::now();
    for (string s: words) {
        t.insert(s);
    }
    auto stop_time = chrono::system_clock::now();
    chrono::duration<double> elapsed = stop_time - start_time; 
    cout << "trie insert: " << elapsed.count() << endl;
    start_time = chrono::system_clock::now();
    for (string s: words) {
        t.contains(s);
    }
    stop_time = chrono::system_clock::now();
    elapsed = stop_time - start_time; 
    cout << "trie find: " << elapsed.count() << endl;

    set<string> setTest;
    start_time = chrono::system_clock::now();
    for (string s: words) {
        setTest.insert(s);
    }
    stop_time = chrono::system_clock::now();
    elapsed = stop_time - start_time; 
    cout << "set insert: " << elapsed.count() << endl;
    start_time = chrono::system_clock::now();
    for (string s: words) {
        setTest.find(s);
    }
    stop_time = chrono::system_clock::now();
    elapsed = stop_time - start_time; 
    cout << "set find: " << elapsed.count() << endl;


    unordered_set<string> u_setTest;
    start_time = chrono::system_clock::now();
    for (string s: words) {
        u_setTest.insert(s);
    }
    stop_time = chrono::system_clock::now();
    elapsed = stop_time - start_time; 
    cout << "unordered set insert: " << elapsed.count() << endl;
    start_time = chrono::system_clock::now();
    for (string s: words) {
        u_setTest.find(s);
    }
    stop_time = chrono::system_clock::now();
    elapsed = stop_time - start_time; 
    cout << "unordered set find: " << elapsed.count() << endl;

    cout << endl;
    random_shuffle(words.begin(), words.end());

    trie t2;
    start_time = chrono::system_clock::now();
    for (string s: words) {
        t2.insert(s);
    }
    stop_time = chrono::system_clock::now();
    elapsed = stop_time - start_time; 
    cout << "random trie insert: " << elapsed.count() << endl;
    start_time = chrono::system_clock::now();
    for (string s: words) {
        t2.contains(s);
    }
    stop_time = chrono::system_clock::now();
    elapsed = stop_time - start_time; 
    cout << "random trie find: " << elapsed.count() << endl;

    set<string> setTest2;
    start_time = chrono::system_clock::now();
    for (string s: words) {
        setTest2.insert(s);
    }
    stop_time = chrono::system_clock::now();
    elapsed = stop_time - start_time; 
    cout << "random set insert: " << elapsed.count() << endl;
    start_time = chrono::system_clock::now();
    for (string s: words) {
        setTest2.find(s);
    }
    stop_time = chrono::system_clock::now();
    elapsed = stop_time - start_time; 
    cout << "random set find: " << elapsed.count() << endl;

    unordered_set<string> u_setTest2;
    start_time = chrono::system_clock::now();
    for (string s: words) {
        u_setTest2.insert(s);
    }
    stop_time = chrono::system_clock::now();
    elapsed = stop_time - start_time; 
    cout << "random unordered set insert: " << elapsed.count() << endl;
    start_time = chrono::system_clock::now();
    for (string s: words) {
        u_setTest2.find(s);
    }
    stop_time = chrono::system_clock::now();
    elapsed = stop_time - start_time; 
    cout << "random unordered set find: " << elapsed.count() << endl;

    cout << t.call_count_nodes() << endl;
    cout << t.call_count_leaf_nodes() << endl;

    return 0;
}
