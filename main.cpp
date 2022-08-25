#include <iostream> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;
int main() {
    const char* s1 = "Hello";
    const char* s2 = s1;
    while (*s1 != '\0') s1++;
    cout << s2 - s1 << endl;
}