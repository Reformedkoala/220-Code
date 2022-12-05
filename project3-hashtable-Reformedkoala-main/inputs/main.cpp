/*
 * How to read from a file
 */

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // create ifstream object (if stands for input file)
    ifstream file("dictionary.txt");
    //             ^ the file you want to read needs to be in the `build` directory

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

    // print strings to verify
    for(string s : data) {
        cout << s << " ";
    }
    cout << endl;
}